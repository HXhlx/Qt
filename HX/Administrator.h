#pragma once

#include <QMainWindow>
#include <QtSql>
#include <QtCharts>
#include "ui_Administrator.h"
#include "HX.h"
using namespace QtCharts;
class Administrator : public QMainWindow
{
	Q_OBJECT

public:Administrator(QWidget* parent = Q_NULLPTR);
	~Administrator();

private:
	QSqlTableModel* table;
	QSqlTableModel* tableadmin;
	QSqlTableModel* tableworker;
	QSqlTableModel* tableconsumer;
	QSqlTableModel* tableorder;
	QSqlTableModel* tableperformance;
	QSqlTableModel* tablematerials;
	QSqlTableModel* tablecar;
	QItemSelectionModel* select;
	QItemSelectionModel* selectadmin;
	QItemSelectionModel* selectworker;
	QItemSelectionModel* selectconsumer;
	QItemSelectionModel* selectorder;
	QItemSelectionModel* selectperformance;
	QItemSelectionModel* selectmaterials;
	QItemSelectionModel* selectcar;
	Ui::Administrator ui;
	void iniBarChart();
	void buildBarChart();
private slots:
	void on_actInsert_triggered();
	void on_actDelete_triggered();
	void on_actSave_triggered();
	void on_actCancel_triggered();
	void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
	void on_tabWidget_currentChanged(int num);
};
