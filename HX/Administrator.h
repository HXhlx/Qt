#pragma once
#include <QMainWindow>
#include <QtCharts>
#include <QtSql>
#include "HX.h"
#include "SqlTableModel.h"
#include "ui_Administrator.h"
using namespace QtCharts;
class Administrator : public QMainWindow
{
	Q_OBJECT
public:Administrator(QWidget* parent = Q_NULLPTR);
	~Administrator();
private:
	QItemSelectionModel* select;
	QItemSelectionModel* selectadmin;
	QItemSelectionModel* selectcar;
	QItemSelectionModel* selectconsumer;
	QItemSelectionModel* selectorder;
	QItemSelectionModel* selectworker;
	QSqlRelationalTableModel* tableorder;
	QSqlRelationalTableModel* rtable;
	QSqlTableModel* qtable;
	QSqlTableModel* tablecar;
	QSqlTableModel* tableconsumer;
	SqlTableModel* table;
	SqlTableModel* tableadmin;
	SqlTableModel* tableworker;
	Ui::Administrator ui;
	void iniCarChart();
	void iniOrderChart();
	void iniWorkerChart();
	void buildCarChart();
	void buildOrderChart();
	void buildWorkerChart();
	void opentable(QSqlRelationalTableModel*&, QTableView*, QString, QItemSelectionModel*&);
	void opentable(QSqlTableModel*&, QTableView*, QString, QItemSelectionModel*&);
	void opentable(SqlTableModel*&, QTableView*, QString, QItemSelectionModel*&);
private slots:
	void on_actCancel_triggered();
	void on_actInsert_triggered();
	void on_actDelete_triggered();
	void on_actSave_triggered();
	void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
	void on_PieSliceHighlight(bool show);
	void on_tabWidget_currentChanged(int num);
};