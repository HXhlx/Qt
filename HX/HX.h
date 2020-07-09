#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QtSql>
#include <QtWidgets>
#include "MySQL.h"
#include "ui_HX.h"
#include "Administrator.h"
#include "Consumer.h"
#include "Worker.h"
class HX : public QMainWindow
{
	Q_OBJECT
public:
	static MySQL* mysql;
	HX(QWidget* parent = Q_NULLPTR);
private:
	QString table = "administrator";
	Ui::HXClass ui;
	void openWedget();
private slots:
	void on_Login_clicked();
	void on_Register_clicked();
	void on_authority_currentIndexChanged(const QString& arg1);
};
