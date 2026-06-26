#pragma once
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

class Config
{
public:
    static Config& instance();
    
    bool load(const QString& filePath = "config.json");
    
    QString dbHost() const { return m_dbHost; }
    int dbPort() const { return m_dbPort; }
    QString dbUser() const { return m_dbUser; }
    QString dbPassword() const { return m_dbPassword; }
    QString dbName() const { return m_dbName; }
    
private:
    Config();
    ~Config() = default;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    
    QString m_dbHost = "192.168.31.9";
    int m_dbPort = 5432;
    QString m_dbUser = "root";
    QString m_dbPassword = "7RN5xdebb17LhlPolWBu4A";
    QString m_dbName = "fix_system";
};
