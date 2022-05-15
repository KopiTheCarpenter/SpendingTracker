    #ifndef ITEM_H
#define ITEM_H

#include <string>



class Item
{
private:
    int id;
    std::string name;
    int amount; //or weight
    std::string amount_type; //kg,db,csomag,zsák
    float value; //gain or loss
    std::string something; //Neccessity, food, cleaning product, toy, other...
public:
    Item();
};

#endif // ITEM_H
