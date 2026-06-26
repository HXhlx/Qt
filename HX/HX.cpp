#include "HX.h"
#include "DatabaseManager.h"
#include "Config.h"
#include "CryptoHelper.h"
#include "Validator.h"

HX::HX(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.Register->setEnabled(false);
	
	// 加载配置
	Config::instance().load();
	
	// 连接数据库
	if (!DatabaseManager::instance().connect())
	{
		QMessageBox::critical(parent, "错误", 
			"数据库连接失败: " + DatabaseManager::instance().lastError());
		return;
	}
}

HX::~HX()
{
}

void HX::openWedget()
{
	if (table == "administrator")
	{
		Administrator* admin = new Administrator(this);
		admin->setAttribute(Qt::WA_DeleteOnClose);
		admin->setWindowTitle("管理员系统");
		admin->setWindowFlag(Qt::Window, true);
		admin->show();
	}
	else if (table == "worker")
	{
		Worker* worker = new Worker(this, ui.username->text(), ui.password->text());
		worker->setAttribute(Qt::WA_DeleteOnClose);
		worker->setWindowTitle("员工系统");
		worker->setWindowFlag(Qt::Window, true);
		worker->show();
	}
	else if (table == "consumer")
	{
		Consumer* consumer = new Consumer(this, ui.username->text(), ui.password->text());
		consumer->setAttribute(Qt::WA_DeleteOnClose);
		consumer->setWindowTitle("客户系统");
		consumer->setWindowFlag(Qt::Window, true);
		consumer->show();
	}
}

void HX::on_Login_clicked()
{
	QString username = ui.username->text();
	QString password = ui.password->text();
	
	// 输入验证
	if (!Validator::isValidUsername(username)) {
		QMessageBox::warning(this, "登录失败", "用户名格式不正确");
		return;
	}
	
	// 使用参数化查询
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = QString("SELECT Password, Salt FROM %1 WHERE Name = :name").arg(table);
	
	QVariantMap params;
	params[":name"] = username;
	
	if (DatabaseManager::instance().executeQuery(query, sql, params))
	{
		if (query.next())
		{
			QString storedHash = query.value("Password").toString();
			QString salt = query.value("Salt").toString();
			
			// 验证密码
			if (CryptoHelper::verifyPassword(password, storedHash, salt))
			{
				openWedget();
				this->hide();
			}
			else
			{
				QMessageBox::warning(this, "登录失败", "用户名或密码错误");
			}
		}
		else
		{
			QMessageBox::warning(this, "登录失败", "用户名或密码错误");
		}
	}
	else
	{
		QMessageBox::critical(this, "错误", 
			"查询失败: " + DatabaseManager::instance().lastError());
	}
}

void HX::on_Register_clicked()
{
	QString username = ui.username->text();
	QString password = ui.password->text();
	
	// 输入验证
	if (!Validator::isValidUsername(username)) {
		QMessageBox::warning(this, "注册失败", "用户名格式不正确（3-30位字母数字下划线）");
		return;
	}
	
	if (!Validator::isValidPassword(password)) {
		QMessageBox::warning(this, "注册失败", "密码长度至少6位");
		return;
	}
	
	// 生成盐和哈希密码
	QString salt = CryptoHelper::generateSalt();
	QString hashedPassword = CryptoHelper::hashPassword(password, salt);
	
	// 使用参数化查询
	QSqlQuery query = DatabaseManager::instance().createQuery();
	QString sql = QString("INSERT INTO %1 (Name, Password, Salt) VALUES (:name, :password, :salt)").arg(table);
	
	QVariantMap params;
	params[":name"] = username;
	params[":password"] = hashedPassword;
	params[":salt"] = salt;
	
	if (DatabaseManager::instance().executeQuery(query, sql, params))
	{
		openWedget();
		this->hide();
	}
	else
	{
		QMessageBox::critical(this, "注册失败", 
			"注册失败: " + DatabaseManager::instance().lastError());
	}
}

void HX::on_username_textEdited()
{
	if (ui.username->text() != "")
	{
		ui.Login->setEnabled(true);
		if (ui.authority->currentText() == "客户")ui.Register->setEnabled(true);
	}
	else
	{
		ui.Login->setEnabled(false);
		ui.Register->setEnabled(false);
	}
}

void HX::on_password_textEdited()
{
	if (ui.password->text() != "")
	{
		ui.Login->setEnabled(true);
		if (ui.authority->currentText() == "客户")ui.Register->setEnabled(true);
	}
	else
	{
		ui.Login->setEnabled(false);
		ui.Register->setEnabled(false);
	}
}

void HX::on_authority_currentIndexChanged(const QString& arg1)
{
	ui.username->clear();
	ui.password->clear();
	if (arg1 == "管理员")
	{
		table = "administrator";
		ui.Register->setEnabled(false);
	}
	else if (arg1 == "员工")
	{
		table = "worker";
		ui.Register->setEnabled(false);
	}
	else if (arg1 == "客户")
	{
		table = "consumer";
		ui.Register->setEnabled(true);
	}
}
