#include "HX.h"
QSqlDatabase HX::Database = QSqlDatabase::addDatabase("QMYSQL");
HX::HX(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.Register->setEnabled(false);
	createconnect();
}

void HX::createconnect()
{
	Database.setHostName("localhost");
	Database.setDatabaseName("dbo");
	Database.setUserName("root");
	Database.setPassword("hx19990627");
	if (!Database.open())
	{
		QMessageBox::critical(this, "错误", Database.lastError().text());
		return;
	}
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
	if (query.size() == -1)QMessageBox::warning(this, "登录失败", QString("用户名或密码错误\n") + QString("select * from %1 where Name='%2' and Password='%3'").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	else openWedget();
}

void HX::on_Register_clicked()
{
	QSqlQuery query;
	query.exec(QString("select * from %1 where Name='%2'").arg(table).arg(ui.username->text()));
	if (query.size() != -1)QMessageBox::warning(this, "注册失败", QString("用户名已存在") + QString("select * from %1 where Name='%2'").arg(table).arg(ui.username->text()));
	else
	{
		query.exec("insert into " + table + "(Name,Password) values('+" + ui.username->text() + "+','" + ui.password->text() + "')");
		openWedget();
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