#include "Config.h"
#include <QCoreApplication>
#include <QDir>

Config& Config::instance()
{
    static Config config;
    return config;
}

Config::Config()
{
}

bool Config::load(const QString& filePath)
{
    QString fullPath = filePath;
    
    // 如果是相对路径，尝试从应用程序目录加载
    if (QDir::isRelativePath(filePath)) {
        fullPath = QCoreApplication::applicationDirPath() + "/" + filePath;
    }
    
    QFile file(fullPath);
    if (!file.open(QIODevice::ReadOnly)) {
        // 如果配置文件不存在，使用默认值
        return true;
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        return false;
    }
    
    QJsonObject root = doc.object();
    QJsonObject dbObj = root["database"].toObject();
    
    if (!dbObj.isEmpty()) {
        m_dbHost = dbObj["host"].toString(m_dbHost);
        m_dbPort = dbObj["port"].toInt(m_dbPort);
        m_dbUser = dbObj["user"].toString(m_dbUser);
        m_dbPassword = dbObj["password"].toString(m_dbPassword);
        m_dbName = dbObj["database"].toString(m_dbName);
    }
    
    return true;
}
