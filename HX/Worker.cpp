#include "Worker.h"

Worker::Worker(QWidget* parent, QString name, QString password)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QSqlQuery query;
	query.exec(QString("select * from Worker where Name='%1' and Password='%2'").arg(name).arg(password));
	while (query.next())
	{
		WorkerID = query.value("WorkerID").toULongLong();
		Name = name;
		Password = password;
		ID = query.value("WorkIDCard").toString();
		age = query.value("WorkAge").toUInt();
		time = query.value("Experience").toULongLong();
		state = query.value("Statement").toString();
		phone = query.value("WorkPhone").toString();
	}
	Show();
	HX::mysql->opentable(this, tableperformance, ui.performanceView, "performance", selectperformance, QString("WorkerID='%1'").arg(WorkerID));
	HX::mysql->opentable(this, tableorder, ui.orderView, "order", selectorder, QString("WorkerID='%1'").arg(WorkerID));
}

Worker::~Worker()
{
}

void Worker::Show()
{
	ui.Age->setValue(age);
	ui.name->setText(Name);
	ui.phone->setText(phone);
	ui.ID->setText(ID);
	ui.timeBox->setValue(time);
	ui.WorkerID->setText(QString::number(WorkerID));
	if (state == "空闲中")ui.comboBox->setCurrentIndex(0);
	else if (state == "维修中")ui.comboBox->setCurrentIndex(1);
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::iniPieChart()
{
	
}

void Worker::buildPieChart()
{
}

void Worker::on_name_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_ID_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_phone_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_Age_textEdited(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_comboBox_currentIndexChanged(const QString& arg)
{
	ui.Save->setEnabled(true);
	ui.Cancel->setEnabled(true);
}

void Worker::on_Save_clicked()
{
	Name = ui.name->text();
	ID = ui.ID->text();
	time = ui.timeBox->value();
	state = ui.comboBox->currentText();
	QSqlQuery query;
	query.exec(QString("update worker set Name='%1',WorkIDCard='%2',WorkAge='%3',Experience='%4',Statement='%5'").arg(Name).arg(ID).arg(age).arg(time).arg(state));
	if (!query.isActive())
	{
		QMessageBox::critical(this, "保存失败", query.lastError().text());
		return;
	}
	QMessageBox::information(this, "保存", "保存成功!");
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::on_Cancel_clicked()
{
	Show();
}
