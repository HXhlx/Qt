#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include <QtSql>
#include <QtWidgets>
#include "Administrator.h"
#include "Consumer.h"
#include "Worker.h"
#include "ui_HX.h"

class HX : public QDialog
{
	Q_OBJECT
public:
	static QSqlDatabase Database;
	HX(QWidget *parent = Q_NULLPTR);
	~HX();
private:
	QString table = "administrator";
	Ui::HX ui;
	void openWedget();
private slots:
	void on_authority_currentIndexChanged(const QString& arg1);
	void on_Login_clicked();
	void on_Register_clicked();
	void on_username_textEdited();
	void on_password_textEdited();
};
