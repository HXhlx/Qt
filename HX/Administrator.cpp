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
	comselect = new QComboBox;
	comselect->addItems(admins);
	ui.mainToolBar->addWidget(comselect);
	edit = new QLineEdit;
	edit->setMaximumWidth(100);
	ui.mainToolBar->addWidget(edit);
	Strs = Admins;
	iniCarChart();
	iniWorkerChart();
	iniOrderChart();
}

Administrator::~Administrator()
{
}

void Administrator::on_actInsert_triggered()
{
	table->insertRow(table->rowCount(), QModelIndex());
	QModelIndex index = table->index(table->rowCount() - 1, 1);
	select->clearSelection();
	select->setCurrentIndex(index, QItemSelectionModel::Select);
	if (table == tableworker)
	{
		table->setData(table->index(index.row(), 0), table->record(index.row() - 1).value(1).toULongLong() + 1);
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

void Administrator::opentable(QSqlRelationalTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select)
{
	table = new QSqlRelationalTableModel(this, HX::Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
	if (!(table->select()))
	{
		QMessageBox::critical(this, "错误", table->lastError().text());
		return;
	}
	QStringList strs;
	if (tablename == "administrator")strs = admins;
	else if (tablename == "worker")strs = workers;
	else if (tablename == "car")strs = cars;
	else if (tablename == "consumer")strs = consumers;
	else if (tablename == "order")strs = orders;
	for (int i = 0; i < strs.count(); i++)table->setHeaderData(i, Qt::Horizontal, strs[i]);
	select = new QItemSelectionModel(table);
	connect(select, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex, QModelIndex)));
	tableView->setModel(table);
	tableView->setSelectionModel(select);
	if (tablename == "worker" || tablename == "consumer")tableView->setColumnHidden(table->fieldIndex("Password"), true);
}

void Administrator::on_actDelete_triggered()
{
	QModelIndex index = select->currentIndex();
	table->removeRow(index.row());
	ui.actSave->setEnabled(true);
	ui.actCancel->setEnabled(true);
}

void Administrator::on_actExport_triggered()
{
	QString filepath = QFileDialog::getSaveFileName(this, "保存到...", "副本", "Excel 97-2003 工作簿(*.xls);;Excel 工作簿(*.xlsx)");
	if (filepath != "")
	{
		int row = table->rowCount();
		int col = table->columnCount();
		QList<QString> list;
		QString HeaderRow;
		for (int i = 0; i < col; i++)HeaderRow.append(table->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
		list.push_back(HeaderRow);
		for (int i = 0; i < row; i++)
		{
			QString rowStr = "";
			for (int j = 0; j < col; j++) {
				QModelIndex index = table->index(i, j);
				rowStr += table->data(index).toString() + "\t";
			}
			list.push_back(rowStr);
		}
		QTextEdit textEdit;
		for (int i = 0; i < list.size(); i++)textEdit.append(list.at(i));
		QFile file(filepath);
		if (file.open(QFile::WriteOnly | QIODevice::Text))
		{
			QTextStream ts(&file);
			//ts.setCodec("GBK");//这个地方大家自己判断是否用“utf-8”
			ts << textEdit.document()->toPlainText();
			file.close();
			QMessageBox::information(this, "导出", "数据导出成功!");
		}
		else QMessageBox::information(this, "导出", "文件打开错误,数据导出失败!");
	}
}

void Administrator::on_actSave_triggered()
{
	uint row = tableworker->rowCount() - 1;
	tableworker->setData(tableworker->index(row, 7), tableworker->record(row).value(2).toString());
	QSqlQuery query;
	QStringList strs = { "administrator","worker","car" };
	for (QString str : strs)query.exec(QString("update %1 set checked = 0 where checked = 1").arg(str));
	if (!table->submitAll() && !query.isActive())QMessageBox::critical(this, "保存失败!", "错误信息:" + table->lastError().text());
	else
	{
		ui.actSave->setEnabled(false);
		ui.actCancel->setEnabled(false);
	}
}

void Administrator::on_actSelect_triggered()
{
	table->setFilter(QString("%1 like '%%2%'").arg(Strs[comselect->currentIndex()]).arg(edit->text()));
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
	comselect->clear();
	switch (num)
	{
	case 0:
		table = tableadmin;
		select = selectadmin;
		comselect->addItems(admins);
		Strs = Admins;
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		break;
	case 1:
		table = tableworker;
		select = selectworker;
		Strs = Workers;
		comselect->addItems(workers);
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		buildWorkerChart();
		break;
	case 2:
		table = tableconsumer;
		select = selectconsumer;
		comselect->addItems(consumers);
		Strs = Consumers;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		break;
	case 3:
		select = selectorder;
		comselect->addItems(orders);
		Strs = Orders;
		ui.actInsert->setEnabled(false);
		ui.actDelete->setEnabled(false);
		buildOrderChart();
		break;
	case 4:
		table = tablecar;
		select = selectcar;
		comselect->addItems(cars);
		Strs = Cars;
		ui.actInsert->setEnabled(true);
		ui.actDelete->setEnabled(true);
		buildCarChart();
		break;
	}
}
