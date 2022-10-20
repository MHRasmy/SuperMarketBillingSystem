#ifndef MARKETITEM_H_INCLUDED
#define MARKETITEM_H_INCLUDED

#include <iostream>

using namespace std;

class marketitem{
private:
    int num;
    int quantity;
    string name;
    string manufacture_name;
    float price;
    float weight;

public:
    void add_item();

    void display_item();

    int item_num();

    string item_name();

    float item_price();

    int item_quantity();

    string item_manufacture_name();

};

#endif // MARKETITEM_H_INCLUDED
