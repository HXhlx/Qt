#include "MySQL.h"

MySQL::MySQL(QWidget* parent, QString Databasename, QString username, QString password, QString host, int port)
{
	Database.setHostName(host);
	Database.setDatabaseName(Databasename);
	Database.setUserName(username);
	Database.setPassword(password);
	Database.setPort(port);
	if (!Database.open())
	{
		QMessageBox::critical(parent, "´íÎó", Database.lastError().text());
		return;
	}
}

void MySQL::opentable(QWidget* widget, QSqlTableModel*& table, QTableView* tableView, QString tablename, QItemSelectionModel*& select, QString filter)
{
	table = new QSqlTableModel(widget, Database);
	table->setTable(tablename);
	table->setEditStrategy(QSqlTableModel::OnManualSubmit);
	table->setFilter(filter);
	if (!(table->select()))
	{
		QMessageBox::critical(widget, "´íÎó", table->lastError().text());
		return;
	}
	select = new QItemSelectionModel(table);
	tableView->setModel(table);
	tableView->setSelectionModel(select);
}
