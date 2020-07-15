#include "Administrator.h"

Administrator::Administrator(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	opentable(tableadmin, ui.adminView, "administrator", selectadmin);
	opentable(tableworker, ui.workerView, "worker", selectworker);
	opentable(tableconsumer, ui.consumerView, "consumer", selectconsumer);
	opentable(tableorder, ui.orderView, "order", selectorder);
	opentable(tablecar, ui.carView, "car", selectcar);
	table = tableadmin;
	select = selectadmin;
	iniCarChart();
	iniWorkerChart();
	iniOrderChart();
}

Administrator::~Administrator()
{
}

void Administrator::on_actInsert_triggered()
{
	table->insertRow(qtable->rowCount(), QModelIndex());
	QModelIndex index = table->index(table->rowCount() - 1, 0);
	select->clearSelection();
	select->setCurrentIndex(index, QItemSelectionModel::Select);
	if (qtable == tableworker)
	{
		table->setData(table->index(index.row(), 0), table->record(index.row() - 1).value(0).toULongLong() + 1);
		table->setData(table->index(index.row(), 4), 0);
		table->setData(table->index(index.row(), 5), 0);
		table->setData(table->index(index.row(), 6), "空闲中");
	}
	ui.actSave->setEnabled(true);
	ui.actCancel->setEnabled(true);
}

void Administrator::iniWorkerChart()
{
	QChart* chart = new QChart();
	chart->setTitle("员工业绩排行前10名");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	ui.WorkerView->setChart(chart);
	ui.WorkerView->setRenderHint(QPainter::Antialiasing);
}

void Administrator::iniCarChart()
{
	QChart* chart = new QChart();
	chart->setTitle("车辆型号");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	ui.CarView->setChart(chart);
	ui.CarView->setRenderHint(QPainter::Antialiasing);
}

void Administrator::iniOrderChart()
{
	QChart* chart = new QChart();
	chart->setTitle("公司盈利情况");
	chart->setAnimationOptions(QChart::SeriesAnimations);
	ui.OrderView->setChart(chart);
	ui.OrderView->setRenderHint(QPainter::Antialiasing);
}

void Administrator::buildWorkerChart()
{
	QChart* chart = ui.WorkerView->chart();
	chart->removeAllSeries();
	chart->removeAxis(chart->axisX());
	chart->removeAxis(chart->axisY());
	QBarSet* set = new QBarSet("业绩");
	QSqlQuery query;
	QStringList strs;
	query.exec("select Name,Experience from worker order by Experience");
	int n = query.size();
	while (query.next())
	{
		set->append(query.value("Experience").toULongLong());
		strs << query.value("Name").toString();
	}
	set->setColor(Qt::darkBlue);
	QHorizontalBarSeries* series = new QHorizontalBarSeries();
	series->append(set);
	chart->addSeries(series);
	QBarCategoryAxis* axisY = new QBarCategoryAxis();
	axisY->append(strs);
	chart->setAxisY(axisY, series);
	axisY->setRange(strs[strs.count() - 10], strs.last());
	QValueAxis* axisX = new QValueAxis();
	axisX->setTitleText("业绩");
	chart->setAxisX(axisX, series);
}

void Administrator::opentable(QSqlRelationalTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select)
{
	table = new QSqlRelationalTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	strs << "订单号" << "开始时间" << "完成时间" << "车牌号" << "商标" << "型号" << "账号" << "描述" << "工号" << "价格";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	connect(select, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
	tableView->setModel(table);
	tableView->setSelectionModel(select);
}

void Administrator::buildCarChart()
{
	QChart* chart = ui.CarView->chart();
	chart->removeAllSeries();
	chart->removeAxis(chart->axisX());
	chart->removeAxis(chart->axisY());
	QBarSet* set = new QBarSet("种类");
	QSqlQuery query;
	QStringList strs;
	query.exec("select Model,count(Model) from car group by Model order by Model");
	int n = query.size();
	while (query.next())
	{
		set->append(query.value("count(Model)").toULongLong());
		strs << query.value("Model").toString();
	}
	set->setColor(Qt::color1);
	QBarSeries* series = new QBarSeries();
	series->append(set);
	chart->addSeries(series);
	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	axisX->append(strs);
	chart->setAxisX(axisX, series);
	QValueAxis* axisY = new QValueAxis();
	axisY->setTitleText("车辆数");
	chart->setAxisY(axisY, series);
}

void Administrator::buildOrderChart()
{
	QChart* chart = ui.OrderView->chart();
	chart->removeAllSeries();
	chart->removeAxis(chart->axisX());
	chart->removeAxis(chart->axisY());
	QLineSeries* line = new QLineSeries();
	QSqlQuery query;
	query.exec("select sum(Pay) from `order` group by year(LDate)");
	int n = query.size();
	for (int i = 2010; query.next(); i++)line->append(QPointF(i, query.value(0).toFloat()));
	chart->addSeries(line);
	QValueAxis* axisX = new QValueAxis(), * axisY = new QValueAxis();
	axisX->setTitleText("年份");
	axisX->setLabelFormat("%.0f");
	axisX->setTickCount(n);
	axisY->setTitleText("金币");
	chart->setAxisX(axisX, line);
	chart->setAxisY(axisY, line);
}

void Administrator::opentable(QSqlTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select)
{
	table = new QSqlTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	if (tablename == "consumer")strs << "账号" << "用户名" << "身份证号" << "电话号码" << "密码";
	else if (tablename == "car")strs << "商标" << "型号" << "类型" << "价格";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	connect(select, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
	tableView->setModel(table);
	tableView->setSelectionModel(select);
	if (tablename == "consumer")tableView->setColumnHidden(table->fieldIndex("Password"), true);
}

void Administrator::opentable(SqlTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select)
{
	table = new SqlTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	if (tablename == "administrator")strs << "选择" << "用户名" << "密码";
	else if (tablename == "worker")strs << "选择" << "工号" << "姓名" << "身份证号" << "电话号码" << "工龄" << "业绩" << "状态" << "密码";
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	connect(select, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
	tableView->setModel(table);
	tableView->setSelectionModel(select);
	if (tablename == "worker")tableView->setColumnHidden(table->fieldIndex("Password"), true);
}

void Administrator::on_actDelete_triggered()
{
	QModelIndex index = select->currentIndex();
	table->removeRow(index.row());
	ui.actSave->setEnabled(true);
	ui.actCancel->setEnabled(true);
}

void Administrator::on_actSave_triggered()
{
	uint row = tableworker->rowCount() - 1;
	tableworker->setData(tableworker->index(row, 7), tableworker->record(row).value(2).toString());
	if (!qtable->submitAll())QMessageBox::critical(this, "保存失败!", "错误信息:" + qtable->lastError().text());
	else
	{
		ui.actSave->setEnabled(false);
		ui.actCancel->setEnabled(false);
	}
}

void Administrator::on_actCancel_triggered()
{
	qtable->revertAll();
	ui.actSave->setEnabled(false);
	ui.actCancel->setEnabled(false);
}

void Administrator::on_currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	Q_UNUSED(current);
	Q_UNUSED(previous);
	ui.actSave->setEnabled(qtable->isDirty());
	ui.actCancel->setEnabled(qtable->isDirty());
}

void Administrator::on_PieSliceHighlight(bool show)
{
	QPieSlice* slice = (QPieSlice*)sender();
	slice->setExploded(show);
}

void Administrator::on_tabWidget_currentChanged(int num)
{
	switch (num)
	{
	case 0:
		table = tableadmin;
		select = selectadmin;
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		break;
	case 1:
		table = tableworker;
		select = selectworker;
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		buildWorkerChart();
		break;
	case 2:
		qtable = tableconsumer;
		select = selectconsumer;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		break;
	case 3:
		select = selectorder;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		buildOrderChart();
		break;
	case 4:
		qtable = tablecar;
		select = selectcar;
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		buildCarChart();
		break;
	}
}