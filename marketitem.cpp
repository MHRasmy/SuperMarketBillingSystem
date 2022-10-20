#include "marketitem.h"

void marketitem::add_item(){
    cout << "Enter the item Number: ";
    cin >> num;

    cout << "Enter the item Name: ";
    cin >> name;

    cout << "Enter the item Manufacture Name: ";
    cin >> manufacture_name;

    cout << "Enter product Weight :";
    cin >> weight;

    cout << "Enter the item Price: ";
    cin >> price;

    cout << "Enter the item Quantity: ";
    cin >> quantity;
}

void marketitem::display_item(){
    cout << "The item Number: " << num << "\n";
    cout << "The item Name: " << name << "\t\t\t";
    cout << "The item Manufacture Name: " << manufacture_name << "\n";
    cout << "The item Price: " << price << "\t\t\t";
    cout << "The item Quantity: " << quantity << "\n";
    cout << "The item Weight: " << weight<< "\n";
}

int marketitem::item_num(){
    return num;
}

string marketitem::item_name(){
    return name;
}

float marketitem::item_price(){
    return price;
}

int marketitem::item_quantity(){
    return quantity;
}

string marketitem::item_manufacture_name(){
    return manufacture_name;
}
