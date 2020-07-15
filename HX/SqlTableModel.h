#pragma once
#include <QSqlTableModel>
class SqlTableModel :
    public QSqlTableModel
{
    Q_OBJECT
public:
    SqlTableModel(QObject* parent = nullptr, QSqlDatabase db = QSqlDatabase());
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index);
    QVariant data(const QModelIndex& idx, int role = Qt::DisplayRole);
};

