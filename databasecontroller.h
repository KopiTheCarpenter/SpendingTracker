#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include "expenditure.h"

#include <QSqlDatabase>

class DatabaseController
{
private:
    QSqlDatabase db;
public:
    DatabaseController();
    ~DatabaseController();
    bool connectToDatabase();
    void closeDatabase();
    bool createSchema();
    bool addExpenditure(Expenditure exp);
    Expenditure* listExpenditures();
};

#endif // DATABASECONTROLLER_H
