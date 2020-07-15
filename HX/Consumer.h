#pragma once
#include <QMainWindow>
#include <QtCharts>
#include <QtSql>
#include "HX.h"
#include "ui_Consumer.h"
using namespace QtCharts;
class Consumer : public QMainWindow
{
	Q_OBJECT
public:
	Consumer(QWidget* parent = Q_NULLPTR, QString name = "", QString password = "");
	~Consumer();
private:
	QItemSelectionModel* select;
	QSqlRelationalTableModel* table;
	QString ID;
	QString Name;
	QString Password;
	QString Phone;
	ULONGLONG CustomerID;
	Ui::Consumer ui;
	void opentable();
	void Show();
private slots:
	void on_Cancel_clicked();
	void on_Delete_clicked();
	void on_currentChanged(const QModelIndex& current, const QModelIndex& previous);
	void on_ID_textEdited(const QString& arg);
	void on_Insert_clicked();
	void on_Logout_clicked();
	void on_name_textEdited(const QString& arg);
	void on_orderSave_clicked();
	void on_orderCancel_clicked();
	void on_phone_textEdited(const QString& arg);
	void on_Save_clicked();
};