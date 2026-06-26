#pragma once
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QRandomGenerator>

class CryptoHelper
{
public:
    // 生成随机盐
    static QString generateSalt(int length = 32)
    {
        QByteArray salt;
        salt.resize(length);
        for (int i = 0; i < length; ++i) {
            salt[i] = static_cast<char>(QRandomGenerator::global()->bounded(256));
        }
        return salt.toHex();
    }
    
    // 使用 SHA-256 哈希密码
    static QString hashPassword(const QString& password, const QString& salt)
    {
        QByteArray data = (password + salt).toUtf8();
        return QString(QCryptographicHash::hash(data, QCryptographicHash::Sha256).toHex());
    }
    
    // 验证密码
    static bool verifyPassword(const QString& password, const QString& storedHash, const QString& salt)
    {
        QString computedHash = hashPassword(password, salt);
        return computedHash.compare(storedHash, Qt::CaseInsensitive) == 0;
    }
};
