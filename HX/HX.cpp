#include "HX.h"
HX::HX(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.Register->setEnabled(false);
	mysql = new MySQL(this, "dbo", "root", "hx19990627");
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
	if (query.size() == -1)QMessageBox::warning(this, "登录失败", "用户名或密码错误");
	else openWedget();
}

void HX::on_Register_clicked()
{
	QSqlQuery query;
	query.exec(QString("insert into %1 (Name,Password) values('%2','%3')").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	if (query.isActive())openWedget();
	else QMessageBox::critical(this, "注册失败", "错误信息:" + query.lastError().text());
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