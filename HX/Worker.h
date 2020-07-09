#pragma once

#include <QMainWindow>
#include <QtSql>
#include <QtCharts>
#include "ui_Worker.h"
#include "HX.h"
using namespace QtCharts;
class Worker : public QMainWindow
{
	Q_OBJECT

public:
	Worker(QWidget* parent = Q_NULLPTR, QString name = "", QString password = "");
	~Worker();

private:
	ULONGLONG WorkerID;
	uint age;
	ulong time;
	QString Name;
	QString Password;
	QString ID;
	QString state;
	QString phone;
	QSqlTableModel* tableorder;
	QSqlTableModel* tableperformance;
	QItemSelectionModel* selectorder;
	QItemSelectionModel* selectperformance;
	Ui::Worker ui;
	void Show();
	void iniPieChart();
	void buildPieChart();
private slots:
	void on_name_textEdited(const QString& arg);
	void on_ID_textEdited(const QString& arg);
	void on_phone_textEdited(const QString& arg);
	void on_Age_textEdited(const QString& arg);
	void on_comboBox_currentIndexChanged(const QString& arg);
	void on_Save_clicked();
	void on_Cancel_clicked();
};
