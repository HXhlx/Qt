#include "Consumer.h"

Consumer::Consumer(QWidget* parent, QString name, QString password)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QSqlQuery query;
	query.exec(QString("select * from consumer where Name='%1' and Password='%2'").arg(name).arg(password));
	while (query.next())
	{
		CustomerID = query.value("CustomerID").toULongLong();
		Name = name;
		Password = password;
		Phone = query.value("CustomerPhone").toString();
		ID = query.value("ID").toString();
	}
	Show();
	HX::mysql->opentable(this, tableorder, ui.orderView, "order", selectorder, QString("CustomerID='%1'").arg(CustomerID));
}

Consumer::~Consumer()
{
}

void Consumer::Show()
{
	ui.consumerID->setText(QString::number(CustomerID));
	ui.name->setText(Name);
	ui.phone->setText(Phone);
	ui.ID->setText(ID);
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Consumer::on_ID_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Consumer::on_name_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}
void Consumer::on_phone_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Consumer::on_Save_clicked()
{
	Name = ui.name->text();
	Phone = ui.phone->text();
	ID = ui.ID->text();
	QSqlQuery query;
	query.exec(QString("update consumer set Name='%1',CustomerPhone='%2',ID='%3' where CustomerID='%4'").arg(Name).arg(Phone).arg(ID).arg(CustomerID));
	if (!query.isActive())
	{
		QMessageBox::critical(this, "保存失败", query.lastError().text());
		return;
	}
	QMessageBox::information(this, "保存", "保存成功!");
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Consumer::on_Cancel_clicked()
{
	Show();
}
