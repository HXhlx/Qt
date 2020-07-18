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
	QSqlRelationalTableModel* tableorder;
	QSqlTableModel* tableconsumer;
	QSqlTableModel* table;
	QSqlTableModel* tableadmin;
	QSqlTableModel* tablecar;
	QSqlTableModel* tableworker;
	QStringList admins = { "�û���" , "����" };
	QStringList Admins = { "Name","Password" };
	QStringList cars = { "�̱�" , "�ͺ�" , "����" , "�۸�" };
	QStringList Cars = { "Brand","Model","Type","Price" };
	QStringList consumers = { "�˺�" , "�û���" , "���֤��" , "�绰����" , "����" };
	QStringList Consumers = { "CustomerID","Name","ID","CustomerPhone","Password" };
	QStringList orders = { "������","��ʼʱ��","���ʱ��","���ƺ�","�̱�","�ͺ�","�˺�","����","����","�۸�" };
	QStringList Orders = { "OrderID","LDate","EDate","CarID","Brand","Model","CustomerID","WorkerID","Pay" };
	QStringList Strs;
	QStringList workers = { "����" , "����" , "���֤��" , "�绰����" , "����" , "ҵ��" , "״̬" , "����" };
	QStringList Workers = { "WorkerID","Name","WorkIDCard","WorkPhone","WorkAge","Experience","Statement","Password" };
	Ui::Administrator ui;
	void iniCarChart();
	void iniOrderChart();
	void iniWorkerChart();
	void buildCarChart();
	void buildOrderChart();
	void buildWorkerChart();
	void opentable(QSqlRelationalTableModel*&, QTableView*, QString, QItemSelectionModel*&);
	void opentable(QSqlTableModel*&, QTableView*, QString, QItemSelectionModel*&);
private slots:
	void on_actCancel_triggered();
	void on_actInsert_triggered();
	void on_actDelete_triggered();
	void on_actSave_triggered();
	void on_actSelect_triggered();
	void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
	void on_tabWidget_currentChanged(int num);
};