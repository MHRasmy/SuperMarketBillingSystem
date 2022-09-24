#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <ctime>
/*
#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);

   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;
The local date and time is: Sat Jan  8 20:07:41 2011
*/

using namespace std;

#define product_file "product.txt"
#define temp_file "temp.txt"
#define bell_file "bell.txt"


struct marketitem{
    int num, quantity;
    string name;
    string manufacture_name;
    float price, weight;


    void add_item(){
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

    void display_item(){
        cout << "The item Number: " << num << "\n";
        cout << "The item Name: " << name << "\t\t\t";
        cout << "The item Manufacture Name: " << manufacture_name << "\n";
        cout << "The item Price: " << price << "\t\t\t";
        cout << "The item Quantity: " << quantity << "\n";
        cout << "The item Weight: " << weight<< "\n";
    }
    int item_num(){
        return num;
    }
    string item_name(){
        return name;
    }
    float item_price(){
        return price;
    }
    int item_quantity(){
        return quantity;
    }
    string item_manufacture_name(){
        return manufacture_name;
    }

};


marketitem item;
fstream pf;
fstream tf;
fstream bf;

void entry_hello()
{
    cout << "Hi :)" << endl;
    cout << "This is my super Market program"<<endl;
    cout << "It is very easy to use" << endl;
    cout << "1. Customer Panel: " << endl;
    cout << "2. Admin Panel: " << endl<< endl;
    cout << "------------------------"<<endl;
    cout << "Enter your choice (1-2)" << endl;

}

void admin_hello(){
    cout << "\n\nIt is very easy to use" << endl;
    cout << "1. Create products: " << endl;
    cout << "2. View products list: " << endl;
    cout << "3. Search for product: " << endl ;
    cout << "4. Delete item: " << endl << endl;
    cout << "------------------------"<<endl;
    cout << "Enter your choice (1-4)" << endl;
}


void create_item(){
    pf.open(product_file, ios::out|ios::app);
    if(pf.fail()){
        cout << "Error opening the file...\n";
        exit(1);
    }
    item.add_item();
    pf.write((char*)&item, sizeof(marketitem));
    pf.close();
    cout << "Item Created successfully" << endl;
    getch();

}

void display_all_items(){
    pf.open(product_file, ios::in);
    if(pf.fail()){
        cout << "Error opening the file...\n";
        exit(1);
    }
    cout << "\nAll market items is here: \n\n";
    while(pf.read((char*)&item, sizeof(marketitem))){
        item.display_item();
        cout << endl;
    }
    pf.close();
    getch();
}

void search_item(int inum){
    pf.open(product_file, ios::in);
    if(pf.fail()){
        cout << "Error opening the file...\n";
        exit(1);
    }
    int count=0;
    while(pf.read((char*)&item, sizeof(marketitem))){

            if(item.item_num()==inum){
                item.display_item();
                cout << "\n";
                count++;

        }

    }
    if(count==0){
        cout << "ERROR_404: Item not found" << endl;
        getch();
    }
    pf.close();
}

void delete_item()
{
    int no;
    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete: ";
    cin >> no;
    pf.open(product_file, ios:: in | ios::out);
    tf.open(temp_file, ios::out);
    while (pf.read((char * ) & item, sizeof(marketitem)))
    {
        if (item.item_num() != no)
        {
            tf.write((char * ) & item, sizeof(marketitem));
        }
    }
    tf.close();
    pf.close();
    remove(product_file);
    rename(temp_file, product_file);
    cout << "\n\n\tItem Deleted ..";
    getch();
}

void bill()
{
    int order_arr[50], quan[50], c = 0;
    float amt, total = 0;
    char ch = 'Y';
    display_all_items();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();
    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \n ";
    for (int x = 0; x <= c; x++)
    {
        pf.open(product_file, ios:: in );
        pf.read((char * ) & item, sizeof(marketitem));
        while (!pf.eof())
        {
            if (item.item_num() == order_arr[x])
            {

                amt = item.item_price() * quan[x];
                cout << "\n" << order_arr[x] << "\t" << item.item_name() <<
                    "\t" << quan[x] << "\t\t" << item.item_price() << "\t" << amt;
                total += amt;

            }
            pf.read((char * ) & item, sizeof(marketitem));
        }
        pf.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total << endl;
    //--------------------------------
    // current date/time based on current system
   time_t now = time(0);

   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

    //-----------------------------------
    getch();
}

void admin_panel(){
    char ch;
    do{
        admin_hello();
        ch=getche();
        switch(ch){
        case'1':
            cout << "\n";
            create_item();
            cout << "\n";
            break;
        case'2':
            cout << "\n";
            display_all_items();
            break;
        case'3':
            int i_num;
            cout << "\n";
            cout << "Enter the item number: " << endl;
            cin >>i_num;
            cout << "\n";
            search_item(i_num);
            break;
        case'4':
            cout << "\n";
            delete_item();
            break;
        }
    }while(ch>'0'&&ch<'5');

}

// Declaration of the 4 functions that are used in the login system.
void main_login();
void login();
void registration();
void forgot();

int main()
{

    char ch;
    do{
        entry_hello();
        ch=getche();
        switch(ch){
        case'1':
            cout << "\n";
            bill();
            cout << "\n";
            break;
        case'2':
            cout << "\n";
            main_login();
            cout << "\n";
            break;
        default:
            cout << "\n";
            cout << "Invalid number...try again." << endl;
            continue;

        }
        //cont(bX);
    }while(ch>'0'&&ch<'5');
    system("pause");

    return 0;

}


void main_login()
{
    // login page, should be removed when adding the GUI.
    int choice;
    cout << "\t_____________________________________________________________\n\n\n";
    cout << "\t                 Welcome to the login page                   \n\n\n";
    cout << "\t___________________         Menu        _____________________\n\n";
    cout << "                                                                       \n\n";
    cout << "\t| Press 1 to LOGIN                                           |" << endl;
    cout << "\t| Press 2 to REGISTER                                        |" << endl;
    cout << "\t| Press 3 if you forgot your password                        |" << endl;
    cout << "\t| Press 4 to EXIT                                            |" << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> choice;
    cout << endl;

    switch(choice)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout << "\t\t\t Thank you! \n\n";
            exit(0);

        default:
            //system("cls");
            cout << "\033[2J\033[1;1H";
            cout << "\t\t\t ERROR!! not a choice\n\n";
            break;
            main_login();

    }

}
// login function definition
void login()
{
    int count = 0;
    string userID, ID, password, pass;
    //system("cls");
    cout << "\033[2J\033[1;1H";
    cout << "\t\t\t Enter Username and Password : " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    // User inputs username and password, then using ifstream class from fstream library the function opens the file "users.txt" then check if it matches.
    ifstream input("users.txt");

    while(input >> ID >> pass)
    {
        if(ID == userID && pass == password)
        {
            count++;
            //system("cls");
            cout << "\033[2J\033[1;1H";

        }
    }
    // close function closes the "users.txt" file
    input.close();

    if(count == 1)
    {
        cout << userID << "\n LOGIN successful!! \n";
        admin_panel();
    }
    else{
        cout << "\n LOGIN ERROR \n";
        main_login();
    }
}

// registration function definition.
void registration()
{
    string regUserID, regID, regpassword, regpass;
    //system("cls");
    cout << "\033[2J\033[1;1H";
    cout << "\t\t\t Enter the UserName: ";
    cin >> regUserID;
    cout << "\t\t\t Enter the Password: ";
    cin >> regpassword;

    // ofstream class to write inside the "users.txt" file, f1 is the object name, ios means input output stream, app mode opens the file and appends the output at the end.
    ofstream f1("users.txt", ios::app);
    f1 << regUserID << ' ' << regpassword << endl;
    //system("cls");
    cout << "\033[2J\033[1;1H";
    cout << "\n\t\t Registration successful!! \n";
    main_login();

}
// forgot password function definition
void forgot()
{
    int option;
    //system("cls");
    cout << "\033[2J\033[1;1H";
    cout << "\t\t\t Forgot your password? \n";
    cout << "Press 1 to search the ID by UserName " << endl;
    cout << "Press 2 to go back to the Main Menu " << endl;
    cin >> option;

    switch(option)
    {
        case 1:
        {
            int count = 0;
            string sUserID, sID, sPass;
            cout << "\n\t\t\t Enter the UserName you remember: ";
            cin >>sUserID;

            // ifstream class, created the f2 object, where it checks for the username in the "users.txt" file then displays the password.
            ifstream f2("users.txt");

            while(f2 >> sID >> sPass)
            {
                if(sID == sUserID)
                {
                    count = 1;
                }
            }
            // close function to close the object.
            f2.close();

            if (count == 1)
            {
                cout << "\n\n Account FOUND!! \n ";
                cout << "\n\n Your Password is: " << sPass;
            }
            else{
                cout << "\n\t Account NOT FOUND! \n";
                main_login();
            }
            break;
        }
        case 2:
        {
            cout << "\033[2J\033[1;1H";
            main();
        }
        default:
            cout << "\t\t\t Wrong choice! try again " << endl;
            break;
            forgot();
    }
}

