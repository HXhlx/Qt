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
	opentable();
	setCentralWidget(ui.tabWidget);
}

Consumer::~Consumer()
{
}

void Consumer::opentable()
{
	table = new QSqlRelationalTableModel(this, HX::Database);
	table->setTable("order");
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	table->setFilter(QString("CustomerID='%1'").arg(CustomerID));
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	strs << "订单号" << "开始时间" << "完成时间" << "车牌号" << "商标" << "型号" << "账号" << "描述" << "工号" << "价格";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	ui.orderView->setModel(table);
	ui.orderView->setSelectionModel(select);
	ui.orderView->setColumnHidden(6, true);
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

void Consumer::on_currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	Q_UNUSED(current);
	Q_UNUSED(previous);
	ui.orderSave->setEnabled(table->isDirty());
	ui.orderCancel->setEnabled(table->isDirty());
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
void Consumer::on_orderSave_clicked()
{
	if (!table->submitAll())QMessageBox::critical(this, "保存失败!", "错误信息:" + table->lastError().text());
	else
	{
		ui.orderSave->setEnabled(false);
		ui.orderCancel->setEnabled(false);
	}
}

void Consumer::on_orderCancel_clicked()
{
	table->revertAll();
	ui.orderSave->setEnabled(false);
	ui.orderCancel->setEnabled(false);
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
	query.exec(QString("update consumer set Name='%1',CustomerPhone='%2',ID='%3' where CustomerID=%4").arg(Name).arg(Phone).arg(ID).arg(CustomerID));
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

void Consumer::on_Insert_clicked()
{
	table->insertRow(table->rowCount(), QModelIndex());
	QModelIndex index = table->index(table->rowCount() - 1, 0);
	select->clearSelection();
	select->setCurrentIndex(index, QItemSelectionModel::Select);
	QDateTime datetime = QDateTime::currentDateTime();
	QSqlQuery query;
	query.exec(QString("select OrderID from `order` where LDate='%1' order by OrderID limit 1").arg(datetime.toString("yyyy-MM-dd hh:mm:ss")));
	query.next();
	table->setData(table->index(index.row(), 0), datetime.toString("yyyyMMddhhmmss").toULongLong() * 10000 + query.value(0).toULongLong() + 1);
	table->setData(table->index(index.row(), 1), datetime);
	query.exec(QString("select WorkerID from worker where Statement in ('空闲中') order by Experience limit 1").arg(datetime.toString("yyyy-MM-dd hh:mm:ss")));
	query.next();
	table->setData(table->index(index.row(), 8), query.value(0).toULongLong());
}

void Consumer::on_Logout_clicked()
{
	QSqlQuery query;
	query.exec("delete * from consumer where CustomerID=" + CustomerID);
	this->close();
}

void Consumer::on_Delete_clicked()
{
	QModelIndex index = select->currentIndex();
	table->removeRow(index.row());
}