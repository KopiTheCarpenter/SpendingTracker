#include <QCoreApplication>
#include <QString>

class MyConfig
{
public:
    MyConfig();
    inline static QString DB_URL = "";
    inline static const QString APPLICATION_LOCATION = QString(QCoreApplication::applicationDirPath());
};

