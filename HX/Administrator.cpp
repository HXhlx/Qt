#include "Administrator.h"

Administrator::Administrator(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	HX::mysql->opentable(this, tableadmin, ui.adminView, "admin", selectadmin);
	HX::mysql->opentable(this,tableworker, ui.workerView, "worker", selectworker);
	HX::mysql->opentable(this,tableconsumer, ui.consumerView, "consumer", selectconsumer);
	HX::mysql->opentable(this,tableorder, ui.orderView, "order", selectorder);
	HX::mysql->opentable(this,tableperformance, ui.performanceView, "performance", selectperformance);
	HX::mysql->opentable(this,tablematerials, ui.materialsView, "materials", selectmaterials);
	HX::mysql->opentable(this,tablecar, ui.carView, "car", selectcar);
	table = tableadmin;
	select = selectadmin;
}

Administrator::~Administrator()
{
}

void Administrator::on_actInsert_triggered()
{
	table->insertRow(table->rowCount(), QModelIndex());
	QModelIndex index = table->index(table->rowCount() - 1, 0);
	select->clearSelection();
	select->setCurrentIndex(index, QItemSelectionModel::Select);
}

void Administrator::iniBarChart()
{
	QChart* chart = new QChart();
	chart->setTitle("员工业绩排行");
	chart->setAnimationOptions(QChart::SeriesAnimations);
}

void Administrator::buildBarChart()
{
}

void Administrator::on_actDelete_triggered()
{
	QModelIndex index = select->currentIndex();
	table->removeRow(index.row());
}

void Administrator::on_actSave_triggered()
{
	if (!table->submitAll())QMessageBox::critical(this, "保存失败!", "错误信息:" + table->lastError().text());
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