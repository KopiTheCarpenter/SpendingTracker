#include "myconfig.cpp"
#include "databasecontroller.h"

#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseController::DatabaseController()
{

}
DatabaseController::~DatabaseController(){
    closeDatabase();
}

bool DatabaseController::connectToDatabase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(MyConfig::DB_URL);
    return db.open();
}

void DatabaseController::closeDatabase()
{
    db.close();
}


bool DatabaseController::createSchema(){
    connectToDatabase();
    if(db.isOpen()){
        QSqlQuery query;
        query.exec("create table expenditures (id integer primary key, name varchar(50), item_type varchar(50), amount_description varchar(50), value int, amount int)");
        return true;
    }
    else{
        qDebug("Failed to open database.");
        return false;
    }
    closeDatabase();
}

bool DatabaseController::addExpenditure(Expenditure exp)
{
    connectToDatabase();
    if(db.isOpen()){
        QSqlQuery query;
        /*query.prepare("insert into expenditures (name, item_type, amount_description, value,amount)"
                   "values(:name, :item_type, :amount_description, :value, :amount);");
        query.bindValue("name",exp.getName());
        query.bindValue("item_type",exp.getItemType());
        query.bindValue("amount_description",exp.getAmountDescription());
        query.bindValue("value",exp.getValue());
        query.bindValue("amount",exp.getAmount());
        */
        query.prepare("insert into expenditures (name, item_type, amount_description, value,amount)"
                      "values (?, ?, ?, ?, ?)");
        query.addBindValue(exp.getName());
        query.addBindValue(exp.getItemType());
        query.addBindValue(exp.getAmountDescription());
        query.addBindValue(exp.getValue());
        query.addBindValue(exp.getAmount());
        //return query.exe();
        if(query.exec()){
            return true;
        }
        else{
            //qDebug() << db.driver()->hasFeature(QSqlDriver::NamedPlaceholders);
            qDebug() << query.lastError();
            qDebug() << query.lastQuery();
            return false;
        }

    }
    else{
        qDebug("Failed to open database.");
        return false;
    }
    closeDatabase();
}

Expenditure *DatabaseController::listExpenditures()
{
    //connectToDatabase();
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
        //closeDatabase();
        return expenditures;
}
