#include "SqlTableModel.h"

QMap<int, Qt::CheckState> check;

SqlTableModel::SqlTableModel(QObject* parent, QSqlDatabase db) :QSqlTableModel(parent, db)
{
}

bool SqlTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (!index.isValid())return false;
	else if (role == Qt::CheckStateRole && index.column() == 0)
	{
		check[index.row()] = value == Qt::Checked ? Qt::Checked : Qt::Unchecked;
		return true;
	}
	else return QSqlTableModel::setData(index, value, role);
}

Qt::ItemFlags SqlTableModel::flags(const QModelIndex& index)
{
	if (!index.isValid())return 0;
	else if (index.column() == 0)return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
	else return QSqlTableModel::flags(index);
	return  Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant SqlTableModel::data(const QModelIndex& idx, int role)
{
	if (!idx.isValid())return QVariant();
	else if (idx.column())return QSqlTableModel::data(idx, role);
	else if (role == Qt::CheckStateRole)
	{
		if (check.contains(idx.row()))return check[idx.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked;
		else return Qt::Unchecked;
	}
	else return QVariant();
}