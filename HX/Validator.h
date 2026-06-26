#pragma once
#include <QString>

class Validator
{
public:
    static bool isValidUsername(const QString& username)
    {
        return !username.isEmpty() && username.length() <= 30;
    }
    
    static bool isValidPassword(const QString& password)
    {
        return password.length() >= 1;
    }
    
    static bool isValidPhone(const QString& phone)
    {
        return phone.length() >= 6 && phone.length() <= 15;
    }
    
    static bool isValidIDCard(const QString& id)
    {
        return id.length() >= 6 && id.length() <= 18;
    }
    
    static QString escapeForDisplay(const QString& input)
    {
        QString result = input;
        result.replace("&", "&amp;");
        result.replace("<", "&lt;");
        result.replace(">", "&gt;");
        result.replace("\"", "&quot;");
        result.replace("'", "&#39;");
        return result;
    }
};
