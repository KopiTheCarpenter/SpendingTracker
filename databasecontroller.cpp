#include "databasecontroller.h"

#include <QSqlDriver>
#include <QSqlQuery>

DatabaseController::DatabaseController()
{

}
DatabaseController::~DatabaseController(){
    closeDatabase();
}

bool DatabaseController::connectToDatabase(QString file_path){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(file_path);
    return db.open();
}

void DatabaseController::closeDatabase()
{
    db.close();
}


bool DatabaseController::createSchema(){
    if(db.isOpen()){
        QSqlQuery query;
        query.exec("create table expenditures (id integer primary key autoincrement, name varchar(50), item_type varchar(50), amount_description varchar(50), value int, amount int)");
        return true;
    }
    else{
        qDebug("Failed to open database.");
        return false;
    }
}

bool DatabaseController::addExpenditure(Expenditure exp)
{
    if(db.isOpen()){
        QSqlQuery query;
        query.exec("insert into expenditures values("+exp.toInstertString()+")");
        return true;
    }
    else{
        qDebug("Failed to open database.");
        return false;
    }
}

Expenditure *DatabaseController::listExpenditures()
{
    QSqlQuery query;
        int numRows;
        query.exec("SELECT * FROM expenditures");

        QSqlDatabase defaultDB = QSqlDatabase::database();
        if (defaultDB.driver()->hasFeature(QSqlDriver::QuerySize)) {
            numRows = query.size();
        } else {
            // this can be very slow
            query.last();
            numRows = query.at() + 1;
        }
        Expenditure expenditures[numRows];
        int i = 0;
        while (query.next()) {
                Expenditure exp;
                exp.setName(query.value(0).toString());
                exp.setItemType(query.value(1).toString());
                exp.setAmountDescription(query.value(2).toString());
                exp.setValue(query.value(1).toInt());
                exp.setAmount(query.value(1).toInt());
                expenditures[i] = exp;
                i++;
            }
        return expenditures;
}
