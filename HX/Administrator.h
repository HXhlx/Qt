#pragma once
#include <QMainWindow>
#include <QtCharts>
#include <QtSql>
#include "HX.h"
#include "ui_Administrator.h"
using namespace QtCharts;
class Administrator : public QMainWindow
{
	Q_OBJECT
public:Administrator(QWidget* parent = Q_NULLPTR);
	~Administrator();
private:
	QComboBox* comselect;
	QItemSelectionModel* select;
	QItemSelectionModel* selectadmin;
	QItemSelectionModel* selectcar;
	QItemSelectionModel* selectconsumer;
	QItemSelectionModel* selectorder;
	QItemSelectionModel* selectworker;
	QLineEdit* edit;
	QSqlRelationalTableModel* table;
	QSqlRelationalTableModel* tableadmin;
	QSqlRelationalTableModel* tablecar;
	QSqlRelationalTableModel* tableconsumer;
	QSqlRelationalTableModel* tableorder;
	QSqlRelationalTableModel* tableworker;
	QStringList admins = { "用户名" , "密码" };
	QStringList Admins = { "Name","Password" };
	QStringList cars = { "商标" , "型号" , "类型" , "价格" };
	QStringList Cars = { "Brand","Model","Type","Price" };
	QStringList consumers = { "账号" , "用户名" , "身份证号" , "电话号码" , "密码" };
	QStringList Consumers = { "CustomerID","Name","ID","CustomerPhone","Password" };
	QStringList orders = { "订单号","开始时间","完成时间","车牌号","商标","型号","账号","描述","工号","价格" };
	QStringList Orders = { "OrderID","LDate","EDate","CarID","Brand","Model","CustomerID","WorkerID","Pay" };
	QStringList Strs;
	QStringList workers = { "工号" , "姓名" , "身份证号" , "电话号码" , "工龄" , "业绩" , "状态" , "密码" };
	QStringList Workers = { "WorkerID","Name","WorkIDCard","WorkPhone","WorkAge","Experience","Statement","Password" };
	Ui::Administrator ui;
	void iniCarChart();
	void iniOrderChart();
	void iniWorkerChart();
	void buildCarChart();
	void buildOrderChart();
	void buildWorkerChart();
	void opentable(QSqlRelationalTableModel*&, QTableView*, QString, QItemSelectionModel*&);
private slots:
	void on_actCancel_triggered();
	void on_actInsert_triggered();
	void on_actDelete_triggered();
	void on_actExport_triggered();
	void on_actSave_triggered();
	void on_actSelect_triggered();
	void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
	void on_tabWidget_currentChanged(int num);
};