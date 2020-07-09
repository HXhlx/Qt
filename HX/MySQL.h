#pragma once
#include <QtSql>
#include <QtWidgets>
class MySQL
{
	QSqlDatabase Database;
public:
	MySQL(QWidget* parent, QString Databasename, QString username, QString password, QString host = "localhost", int port = 3306);
	void opentable(QWidget*, QSqlTableModel*&, QTableView*, QString, QItemSelectionModel*&, QString = "");
};

