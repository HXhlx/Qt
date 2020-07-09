#include "Administrator.h"

Administrator::Administrator(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	opentable(tableadmin, ui.adminView, "administrator", selectadmin);
	opentable(tableworker, ui.workerView, "worker", selectworker);
	opentable(tableconsumer, ui.consumerView, "consumer", selectconsumer);
	opentable(tableorder, ui.orderView, "order", selectorder);
	opentable(tableperformance, ui.performanceView, "performance", selectperformance);
	opentable(tablematerials, ui.materialsView, "materials", selectmaterials);
	opentable(tablecar, ui.carView, "car", selectcar);
	table = tableadmin;
	select = selectadmin;
}

Administrator::~Administrator()
{
}

void Administrator::opentable(QSqlTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select)
{
	table = new QSqlTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	if (!(table->select()))
	{
		QMessageBox::critical(this, "´íÎó", table->lastError().text());
		return;
	}
	select = new QItemSelectionModel(table);
	tableView->setModel(table);
	tableView->setSelectionModel(select);
}

void Administrator::on_actInsert_triggered()
{
	table->insertRow(table->rowCount(), QModelIndex());
	QModelIndex index = table->index(table->rowCount() - 1, 0);
	select->clearSelection();
	select->setCurrentIndex(index, QItemSelectionModel::Select);
}

void Administrator::on_actDelete_triggered()
{
	QModelIndex index = select->currentIndex();
	table->removeRow(index.row());
}

void Administrator::on_actSave_triggered()
{
	if (!table->submitAll())QMessageBox::critical(this, "±£´æÊ§°Ü!", "´íÎóÐÅÏ¢:" + table->lastError().text());
	else
	{
		ui.actSave->setEnabled(false);
		ui.actCancel->setEnabled(false);
	}
}

void Administrator::on_actCancel_triggered()
{
	table->revertAll();
	ui.actSave->setEnabled(false);
	ui.actCancel->setEnabled(false);
}

void Administrator::on_currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	Q_UNUSED(current);
	Q_UNUSED(previous);
	ui.actSave->setEnabled(table->isDirty());
	ui.actCancel->setEnabled(table->isDirty());
}

void Administrator::on_tabWidget_currentChanged(int num)
{
	switch (num)
	{
	case 0:
		table = tableadmin;
		select = selectadmin;
		break;
	case 1:
		table = tableworker;
		select = selectworker;
		break;
	case 2:
		table = tableconsumer;
		select = selectconsumer;
		break;
	case 3:
		table = tableorder;
		select = selectorder;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		break;
	case 4:
		table = tableperformance;
		select = selectperformance;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		break;
	case 5:
		table = tablematerials;
		select = selectmaterials;
		break;
	case 6:
		table = tablecar;
		select = selectcar;
		break;
	}
}