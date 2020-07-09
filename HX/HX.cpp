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
		admin->setWindowTitle("����Աϵͳ");
		admin->setWindowFlag(Qt::Window, true);
		admin->show();
	}
	else if (table == "worker")
	{
		Worker* worker = new Worker(this, ui.username->text(), ui.password->text());
		worker->setAttribute(Qt::WA_DeleteOnClose);
		worker->setWindowTitle("Ա��ϵͳ");
		worker->setWindowFlag(Qt::Window, true);
		worker->show();
	}
	else if (table == "consumer")
	{
		Consumer* consumer = new Consumer(this, ui.username->text(), ui.password->text());
		consumer->setAttribute(Qt::WA_DeleteOnClose);
		consumer->setWindowTitle("�ͻ�ϵͳ");
		consumer->setWindowFlag(Qt::Window, true);
		consumer->show();
	}
}

void HX::on_Login_clicked()
{
	QSqlQuery query;
	query.exec(QString("select * from %1 where Name='%2' and Password='%3'").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	if (query.size() == -1)QMessageBox::warning(this, "��¼ʧ��", "�û������������");
	else openWedget();
}

void HX::on_Register_clicked()
{
	QSqlQuery query;
	query.exec(QString("insert into %1 (Name,Password) values('%2','%3')").arg(table).arg(ui.username->text()).arg(ui.password->text()));
	if (query.isActive())openWedget();
	else QMessageBox::critical(this, "ע��ʧ��", "������Ϣ:" + query.lastError().text());
}

void HX::on_authority_currentIndexChanged(const QString& arg1)
{
	ui.username->clear();
	ui.password->clear();
	if (arg1 == "����Ա")
	{
		table = "administrator";
		ui.Register->setEnabled(false);
	}
	else if (arg1 == "Ա��")
	{
		table = "worker";
		ui.Register->setEnabled(false);
	}
	else if (arg1 == "�ͻ�")
	{
		table = "consumer";
		ui.Register->setEnabled(true);
	}
}