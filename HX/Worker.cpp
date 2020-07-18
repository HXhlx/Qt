#include "Worker.h"

Worker::Worker(QWidget* parent, QString name, QString password)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QSqlQuery query;
	query.exec(QString("select * from worker where Name='%1' and Password=encode('%2','worker')").arg(name).arg(password));
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
	opentable();
	setCentralWidget(ui.tabWidget);
}

Worker::~Worker()
{
}

void Worker::opentable()
{
	table = new QSqlRelationalTableModel(this, HX::Database);
	table->setTable("order");
	table->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
	table->setFilter(QString("WorkerID='%1'").arg(WorkerID));
	if (!(table->select()))
	{
		QMessageBox::critical(this, "����", table->lastError().text());
		return;
	}
	QStringList strs;
	strs << "������" << "��ʼʱ��" << "���ʱ��" << "���ƺ�" << "�̱�" << "�ͺ�" << "�˺�" << "����" << "����" << "�۸�";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	ui.orderView->setModel(table);
	ui.orderView->setSelectionModel(select);
	ui.orderView->setColumnHidden(6, true);
	ui.orderView->setColumnHidden(8, true);
}

void Worker::Show()
{
	ui.Age->setValue(age);
	ui.name->setText(Name);
	ui.phone->setText(phone);
	ui.ID->setText(ID);
	ui.timeBox->setValue(time);
	ui.WorkerID->setText(QString::number(WorkerID));
	if (state == "������")ui.comboBox->setCurrentIndex(0);
	else if (state == "ά����")ui.comboBox->setCurrentIndex(1);
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
	query.exec(QString("update worker set Name='%1',WorkIDCard='%2',WorkAge=%3,Experience=%4,Statement='%5' where WorkerID=%6").arg(Name).arg(ID).arg(age).arg(time).arg(state).arg(WorkerID));
	if (!query.isActive())
	{
		QMessageBox::critical(this, "����ʧ��", query.lastError().text());
		return;
	}
	QMessageBox::information(this, "����", "����ɹ�!");
	ui.Save->setEnabled(false);
	ui.Cancel->setEnabled(false);
}

void Worker::on_Cancel_clicked()
{
	Show();
}

void Worker::on_Finish_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	record.setValue(2, QDateTime::currentDateTime());
	table->setRecord(index.row(), record);
	state = "������";
	QSqlQuery query;
	query.exec(QString("update worker set Statement='%1' where WorkerID=%2").arg(state).arg(WorkerID));
}

void Worker::on_orderCancel_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	QSqlQuery query;
	query.exec(QString("select WorkerID from worker where WorkerID!=%1 and Statement in ('������') order by Experience limit 1").arg(WorkerID));
	query.next();
	record.setValue(8, query.value(0).toULongLong());
	table->setRecord(index.row(), record);
	table->removeRow(index.row());
	time += 1;
	state = "������";
	query.exec(QString("update worker set Statement='%1',Experience=%2 where WorkerID=%3").arg(state).arg(time).arg(WorkerID));
}

void Worker::on_orderView_clicked()
{
	QModelIndex index = select->currentIndex();
	QSqlRecord record = table->record(index.row());
	if (record.value(2).isNull())ui.Finish->setEnabled(true);
	else ui.Finish->setEnabled(false);
}
