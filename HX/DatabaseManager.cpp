#include "DatabaseManager.h"
#include "Config.h"

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager manager;
    return manager;
}

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

bool DatabaseManager::connect()
{
    Config& config = Config::instance();
    
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(config.dbHost());
    m_db.setPort(config.dbPort());
    m_db.setUserName(config.dbUser());
    m_db.setPassword(config.dbPassword());
    m_db.setDatabaseName(config.dbName());
    
    if (!m_db.open()) {
        m_lastError = m_db.lastError().text();
        m_connected = false;
        return false;
    }
    
    m_connected = true;
    return true;
}

void DatabaseManager::disconnect()
{
    if (m_connected && m_db.isOpen()) {
        m_db.close();
    }
    m_connected = false;
}

bool DatabaseManager::isConnected() const
{
    return m_connected;
}

QSqlDatabase DatabaseManager::database()
{
    return m_db;
}

QSqlQuery DatabaseManager::createQuery()
{
    return QSqlQuery(m_db);
}

bool DatabaseManager::executeQuery(QSqlQuery& query, const QString& sql, 
                                   const QVariantMap& params)
{
    if (!m_connected) {
        m_lastError = "数据库未连接";
        return false;
    }
    
    query.prepare(sql);
    
    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }
    
    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    
    return true;
}

QString DatabaseManager::lastError() const
{
    return m_lastError;
}
