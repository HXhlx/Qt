#pragma once
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QMessageBox>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    
    bool connect();
    void disconnect();
    bool isConnected() const;
    
    QSqlDatabase database();
    
    // 创建参数化查询
    QSqlQuery createQuery();
    
    // 执行参数化查询
    bool executeQuery(QSqlQuery& query, const QString& sql, 
                     const QVariantMap& params = QVariantMap());
    
    // 获取最后错误信息
    QString lastError() const;
    
private:
    DatabaseManager();
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    
    QSqlDatabase m_db;
    bool m_connected = false;
    QString m_lastError;
};
