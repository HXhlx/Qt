#include "HX.h"

QSqlDatabase HX::Database = QSqlDatabase::addDatabase("QMYSQL");

HX::HX(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.Register->setEnabled(false);
	Database.setHostName("cdb-geebna1a.cd.tencentcdb.com");
	Database.setUserName("HXhlx");
	Database.setPassword("HXhlx19990627");
	Database.setDatabaseName("fix_system");
	Database.setPort(10053);
	if (!Database.open())
	{
		QMessageBox::critical(parent, "错误", Database.lastError().text());
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
	QSqlQuery query;
	query.exec(QString("select * from %1 where Name='%2' and Password='%3'").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	if (query.size())
	{
		openWedget();
		this->hide();
	}
	else QMessageBox::warning(this, "登录失败", "用户名或密码错误");
}

void HX::on_Register_clicked()
{
	QSqlQuery query;
	query.exec(QString("insert into %1 (Name,Password) values('%2','%3')").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	if (query.isActive())
	{
		openWedget();
		this->hide();
	}
	else QMessageBox::critical(this, "注册失败", "用户名已存在");
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