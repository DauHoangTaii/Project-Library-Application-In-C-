#include "System.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;


System::System()
{
    //ctor
}
void System::run()
{
    int choose;
    menu_main();
    cout << "Enter your choose: ";
    cin >> choose;
    switch (choose)
    {
    case 1: //login
        while (1)
        {
            while (!login())
            {
                cout << "Invalid username or password. Please try again!" << endl;
                system("pause");
            }
            menu_admin_manager();
            break;
        }
    }
}

bool System::login()
{
    char userAdmin[10];
    char passAdmin[10];
    cout << "-----------Admin Login----------" << endl;
    cout << "Enter username: ";
    cin >> userAdmin;
    cout << "Enter password: ";
    cin >> passAdmin;
    if( (strcmp(userAdmin, ADMINUSER) == 0) &&
	    ( strcmp(passAdmin, ADMINPASSWORD) == 0)) {
	        return true;
	    }
	    return false;
}

void System::menu_main()
{
    system("cls");
    cout << "---------------Library Management Version 1.0--------------"<<endl;
    cout << "[1]. Admin " << endl;
    cout << "[2]. User " << endl;
    cout << "[0]. Exit " << endl;
}

void System::menu_admin_manager()
{
    cout << "Admin Login is Successful !! Press any key to continue.."<<endl;
    system("pause");
    system("cls");
    cout << "[1]. Book Manager" << endl;
    cout << "[2]. User Manager" << endl;
    cout << "[3]. Worker Manager" << endl;
    cout << "[0]. Exit" << endl;
}

void System::menu_user_manager()
{
    system("cls");
    cout << "[1]. Add user" << endl;
    cout << "[2]. Update user" << endl;
    cout << "[3]. Delete user" << endl;
    cout << "[4]. Search user" << endl;
    cout << "[5]. Show user" << endl;
    cout << "[0]. Exit" << endl;
}

void System::menu_user()
{
    system("cls");
    cout << "[1]. Rent book" << endl;
    cout << "[2]. Return book" << endl;
    cout << "[3]. Show personal information" << endl;
    cout << "[0]. Exit" << endl;
}

void System::menu_book_manager()
{
    system("cls");
    cout << "[1]. Add book" << endl;
    cout << "[2]. Update book" << endl;
    cout << "[3]. Delete book" << endl;
    cout << "[4]. Search book" << endl;
    cout << "[5]. Show book" << endl;
    cout << "[0]. Exit" << endl;
}


System::~System()
{
    //dtor
}
