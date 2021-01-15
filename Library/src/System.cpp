#include "System.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Book.h"
#include "User.h"

using namespace std;

HANDLE color;
System::System()
{
    //ctor
}
void System::run()
{
    menu_main();
}
void System::HideCursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

bool System::login()
{
    char userAdmin[10];
    char passAdmin[10];
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 4);
    cout << "-----------Admin Login----------" << endl;
    cout << "Enter username: ";
    cin >> userAdmin;
    cout << "Enter password: ";
    cin >> passAdmin;
    system("cls");
    if( (strcmp(userAdmin, ADMINUSER) == 0) &&
	    ( strcmp(passAdmin, ADMINPASSWORD) == 0)) {
	        return true;
	    }
	    return false;
}
bool System::login_user()
{
    User us;
    fstream File;
    char user[15];
    char passwd[20];
    int n;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 3);
    cout << "------------------User Login-----------------" << endl;
    cout << "Enter username: ";
    cin.getline(user,15);
    cout << "Enter password: ";
    cin.getline(passwd,20);
    File.open("user.dat",ios::binary|ios::in|ios::out);
	while(!File.eof())
	{
		File.read(reinterpret_cast<char *> (&us), sizeof(User));
		//us.show_user();
		if(strcmp(us.retUsername(),user)==0 && strcmp(us.retPassword(),passwd) == 0)
		{
		    return true;
        }
	}
	return false;
	File.close();

}

void System::menu_main()
{
    loop:
    system("cls");
    fflush(stdin);
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, rand()%15);
    cout << " _     _ _" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |   (_) |__   __ _ _ __ __ _ _   _" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |   | | '_ \\ / _` | '__/ _` | | | |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "| |___| | |_) | (_| | | | (_| | |_| |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "|_____|_|_.__/ \\__,_|_|  \\__,_|\\__, |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "                               |___/" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "    _                _ _           _   _" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "   / \\   _ __  _ __ | (_) ___ __ _| |_(_) ___  _ __" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "  / _ \\ | '_ \\| '_ \\| | |/ __/ _` | __| |/ _ \\| '_ \\" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << " / ___ \\| |_) | |_) | | | (_| (_| | |_| | (_) | | | |" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "/_/   \\_\\ .__/| .__/|_|_|\\___\\__,_|\\__|_|\\___/|_| |_|" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "        |_|   |_|" << endl;
    SetConsoleTextAttribute(color, 3);
    cout << "\n";
    cout << "***************************" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*  [1]. Login With Admin  *" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*-------------------------*" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*  [2]. Login With User   *" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*-------------------------*" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*  [3]. Exit              *" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "*-------------------------*" << endl;
    SetConsoleTextAttribute(color, rand()%15);
    cout << "***************************" << endl;

    int choice = -1;
    SetConsoleTextAttribute(color, 14);
    cout << "Enter your choice: ";
    cin >> choice;
    while(choice < 1 || choice > 3)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    switch(choice)
    {
    case 1: // login with admin
        system("cls");
        while(!login())
        {
            cout << "Invalid username or password. Please try again!" << endl;
            system("pause");
            system("cls");
        }
        system("cls");
        menu_admin_manager();
        break;
    case 2: //login with user
        system("cls");
        cin.ignore();
        while(!login_user())
        {
            cout << "Invalid username or password. Please try again!" << endl;
            system("pause");
            system("cls");
        }
        system("cls");
        menu_user();
        break;
    case 3:
        cout << "Thank you for using it!!";
        exit(0);
    }
}

void System::menu_admin_manager() // menu of admin
{
    int choice;

    cout << "Admin Login is Successful !!"<<endl;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 14);
    system("pause");
    system("cls");
    loop:
    cout << "---------------Admin Manager-----------------" << endl;
    cout << "[1]. Book Manager" << endl;
    cout << "[2]. User Manager" << endl;
    cout << "[3]. Employee Manager" << endl;
    cout << "[4]. Logout" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 4)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    switch(choice)
    {
    case 1:
        menu_book_manager();
        break;
    case 2:
        menu_user_manager();
        break;
    case 3:
        menu_employee_manager();
        break;
    case 4:
        menu_main();
    }
}

void System::menu_user_manager() // menu manager user
{
    loop:
    int choice = -1;
    system("cls");

    cout << "[1]. Add user" << endl;
    cout << "[2]. Update user" << endl;
    cout << "[3]. Delete user" << endl;
    cout << "[4]. Search user" << endl;
    cout << "[5]. Show user" << endl;
    cout << "[6]. Back" << endl;
    cout << "[7]. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 7)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    User us;
    switch(choice)
    {
    case 1:
        char c;
        do
        {
        system("cls");
         us.write_user();
         cout << "Do you add more user..(y/n?): ";
         cin >> c;
        }while(c=='y'||c=='Y');
        goto loop;
    case 2:
        us.update_user();
        goto loop;
    case 3:
        us.delete_user();
        goto loop;
    case 4:
        us.search_user();
        goto loop;
    case 5:
        us.display();
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "Thank you for using it !!";
        exit(0);
    }
}

void System::menu_user() // menu to rent book
{
    loop:
    int choice;

    system("cls");

    cout << "[1]. Rent book" << endl;
    cout << "[2]. Return book" << endl;
    cout << "[3]. Show list book" << endl;
    cout << "[4]. Logout" << endl;
    cout << "[5]. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 5)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    ServiceBook sv;
    Book bk;
    switch(choice)
    {
    case 1:
        sv.rentBook();
        goto loop;
    case 2:
        sv.returnBook();
        goto loop;
    case 3:
        bk.display();
        system("pause");
        goto loop;
    case 4:
        menu_main();
    case 5:
        cout << "Thank you for using it ! " << endl;
        system("pause");
        exit(0);
    }
}

void System::menu_book_manager()
{
    loop:
    int choice;

    system("cls");

    cout << "[1]. Add book" << endl;
    cout << "[2]. Update book" << endl;
    cout << "[3]. Delete book" << endl;
    cout << "[4]. Search book" << endl;
    cout << "[5]. Show book" << endl;
    cout << "[6]. Back" << endl;
    cout << "[7]. Exit" << endl;

    cout << "Enter your choice: ";
    cin >>choice;

    while(choice < 1 || choice > 7)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    Book bk;
    switch(choice)
    {
    case 1:
        char c;
        do
        {
            system("cls");
            bk.wirteBook();
            cout << "Do you add more book..(y/n?): ";
            cin >> c;
        }while(c=='y' || c=='Y');
        goto loop;
    case 2:
        bk.updateBook();
        goto loop;
    case 3:
        bk.deleteBook();
        goto loop;
    case 4:
        bk.searchBook();
        goto loop;
        break;
    case 5:
        system("cls");
        bk.display();
        cout << "Press any key to return menu book. " << endl;
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "Thank you for using it !!";
        exit(0);
    }

}
void System::menu_employee_manager()
{
    loop:
    int choice;

    system("cls");
    cout << "[1]. Add employee" << endl;
    cout << "[2]. Update employee" << endl;
    cout << "[3]. Delete employee" << endl;
    cout << "[4]. Show employee" << endl;
    cout << "[5]. Search employee" << endl;
    cout << "[6]. Back" << endl;
    cout << "[7]. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice < 1 || choice > 7)
    {
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        goto loop;
        cout << "Enter your choice: ";
        cin >> choice;
    }
    ManagerEmloyee mne;
    switch(choice)
    {
    case 1:
        mne.addEmployee();
        goto loop;
    case 2:
        mne.updateEmployee();
        goto loop;
    case 3:
        mne.deleteEmployee();
        goto loop;
    case 4:
        mne.showEmployee();
        goto loop;
    case 5:
        mne.searchEmployee();
        goto loop;
    case 6:
        menu_admin_manager();
        break;
    case 7:
        cout << "Thank you for using it !!";
        exit(0);
    }
}

System::~System()
{
    //dtor
}
