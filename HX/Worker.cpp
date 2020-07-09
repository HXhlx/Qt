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
	opentable(tableperformance, ui.performanceView, "performance", selectperformance);
	opentable(tableorder, ui.orderView, "order", selectorder);
}

Worker::~Worker()
{
}

void Worker::opentable(QSqlTableModel* &table, QTableView* tableView, QString tablename, QItemSelectionModel* &select)
{
	table = new QSqlTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	table->setFilter(QString("WorkerID='%1'").arg(WorkerID));
	if (!(table->select()))
	{
		QMessageBox::critical(this, "´íÎó", table->lastError().text());
		return;
	}
	select = new QItemSelectionModel(table);
	tableView->setModel(table);
	tableView->setSelectionModel(select);
}

void Worker::Show()
{
	ui.Age->setValue(age);
	ui.name->setText(Name);
	ui.phone->setText(phone);
	ui.ID->setText(ID);
	ui.timeBox->setValue(time);
	ui.WorkerID->setText(QString::number(WorkerID));
	if (state == "¿ÕÏÐÖÐ")ui.comboBox->setCurrentIndex(0);
	else if (state == "Î¬ÐÞÖÐ")ui.comboBox->setCurrentIndex(1);
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
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
		QMessageBox::critical(this, "±£´æÊ§°Ü", query.lastError().text());
		return;
	}
	QMessageBox::information(this, "±£´æ", "±£´æ³É¹¦!");
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::on_Cancel_clicked()
{
	Show();
}
