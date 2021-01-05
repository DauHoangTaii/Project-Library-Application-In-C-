#include "User.h"
#include "Person.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include<stdio.h>
#include <cstdio>

using namespace std;

User us;
fstream fp3;

User::User()
{
    username = "N/A";
    password = "N/A";
    clas = "N/A";
}

void User::show_user()
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    Person::display();
    cout << "Class: " << clas << endl;
}

void User::add_user()
{
    system("cls");
    cout << "----------------New user-----------------" << endl;
    cin.ignore();
    cout << "Enter username: ";
    getline(cin,username);
    cout << "Enter password: ";
    cin >> password;
    cin.ignore();
    Person::input();
    cout << "Enter class: ";
    getline(cin,clas);
}

void User::update_user()
{
    system("cls");
    fstream File;
    bool found=false;
    int n;
    string s;

	cout << "---------------UPDATE USER----------------" << endl;
	cout << "Enter id of user update: ";
	cin >> n;
	while(n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
    cout << "Enter username of user delete: ";
    cin >> s;

    File.open("user.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&us), sizeof(User));
		if(us.retId()==n && us.retUsername() == s)
		{
		    cout << "Current data" << endl;
			us.show_user();
			system("pause");
			cout << "Enter The New Details of User"<<endl;
			us.add_user();
			int pos=(-1)*static_cast<int>(sizeof(User));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&us), sizeof(User));
		    cout << "Update Successfully !!";
		    system("pause");
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"Record Not Found ";
}

void User::delete_user()
{
    system("cls");
    int n;
    string s;
	cout << "----------------DELETE USER----------------" << endl;
	cout << "Enter id of user delete: ";
	cin>>n;
	while(n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
	cout << "Enter username of user detele: ";
	cin >> s;
	ifstream inFile;
	ofstream outFile;
	inFile.open("user.dat",ios::binary);
	if(!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&us), sizeof(User)))
	{
		if(us.retId()!=n && us.retUsername()!=s)
		{
			outFile.write(reinterpret_cast<char *> (&us), sizeof(User));
		}
	}
    inFile.close();
	outFile.close();
	remove("user.dat");
	rename("Temp.dat","user.dat");
	cout << "Delete Successfully" << endl;
    system("pause");
}

void User::search_user()
{
    int n;
    string s;
    bool found=false;
	fstream File;
    system("cls");
	cout << "---------------Search User With ID-------------" << endl;
	cout << "Enter id of user: ";
	cin >> n;
	while(n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of user: ";
        cin >> n;
    }
    cout << "Enter username of user: ";
    cin >> s;
    File.open("user.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&us), sizeof(User));
		if(us.retUsername()==s && us.retId()==n)
		{
		    system("cls");
			us.show_user();
			system("pause");
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout << "Record Not Found " << endl;
		system("pause");
}
// save file
void User::write_user()
{
    char ch;
    ofstream outFile;
	do
	{
        outFile.open("user.dat",ios::binary|ios::app);
        us.add_user();
        outFile.write(reinterpret_cast<char *> (&us), sizeof(User));
		cout << "Add User Successfully !" << endl;
		system("pause");
		system("cls");
		cout << "Do you want to add more record..(y/n?)";
		cin >> ch;
	}while(ch=='y'||ch=='Y');
	outFile.close();
}

void User::report()
{
    cout << username <<setw(20) << password << setw(23);
    Person::report();
    cout << setw(23) << clas << endl;
//    cout << username << setw(20) << password << setw(23) << getId() << setw(25) << getName() << setw(20) << getAge() << setw(23) << getMail() << setw(20) << clas;
}

void User::display()
{
    system("cls");
    fp3.open("user.dat",ios::in);

	cout << "\t\t\t\t\t\t\t\t\tUser LIST" << endl;
	cout << "=================================================================================================================================================\n";
	cout << "Username"<<setw(20)<<"Password"<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(25)<<"Age"<<setw(20)<<"Mail"<<setw(20)<<"Class" << endl;
	cout << "=================================================================================================================================================\n";

	while(fp3.read(reinterpret_cast<char*>(&us),sizeof(User)))
	{
		us.report();
	}
     	fp3.close();
     	getch();
}
string User::retUsername()
{
    return username;
}

int User::retId()
{
    return Person::getId();
}

void User::format()
{

}

User::~User()
{
    //dtor
}
