#pragma once
#include <QMainWindow>
#include <QtCharts>
#include <QtSql>
#include "HX.h"
#include "ui_Worker.h"
using namespace QtCharts;
class Worker : public QMainWindow
{
	Q_OBJECT
public:
	Worker(QWidget* parent = Q_NULLPTR, QString name = "", QString password = "");
	~Worker();
private:
	QItemSelectionModel* select;
	QSqlRelationalTableModel* table;
	QString ID;
	QString Name;
	QString Password;
	QString phone;
	QString state;
	Ui::Worker ui;
	uint age;
	ulong time;
	ULONGLONG WorkerID;
	void opentable();
	void Show();
private slots:
	void on_Age_textEdited(const QString& arg);
	void on_Cancel_clicked();
	void on_comboBox_currentIndexChanged(const QString& arg);
	void on_Finish_clicked();
	void on_ID_textEdited(const QString& arg);
	void on_name_textEdited(const QString& arg);
	void on_orderCancel_clicked();
	void on_orderView_clicked();
	void on_phone_textEdited(const QString& arg);
	void on_Save_clicked();
};