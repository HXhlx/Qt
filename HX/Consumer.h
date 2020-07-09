#pragma once

#include <QMainWindow>
#include <QtSql>
#include <QtCharts>
#include "ui_Consumer.h"
#include "HX.h"
using namespace QtCharts;
class Consumer : public QMainWindow
{
	Q_OBJECT

public:
	Consumer(QWidget* parent = Q_NULLPTR, QString name = "", QString password = "");
	~Consumer();

private:
	ULONGLONG CustomerID;
	QString Name;
	QString Password;
	QString Phone;
	QString ID;
	QSqlTableModel* tableorder;
	QItemSelectionModel* selectorder;
	Ui::Consumer ui;
	void Show();
private slots:
	void on_name_textEdited(const QString& arg);
	void on_ID_textEdited(const QString& arg);
	void on_phone_textEdited(const QString& arg);
	void on_Save_clicked();
	void on_Cancel_clicked();
};
