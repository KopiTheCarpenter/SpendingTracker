#ifndef ITEMLIST_H
#define ITEMLIST_H


#include <string>
#include <item.h>

class ItemList
{
private:
    int id;
    //Item[] items;
    float valueSumm;
    std::string name;
    std::string location; //location of purchase
    std::string date; //Date of transaction
public:
    ItemList();
};

#endif // ITEMLIST_H
