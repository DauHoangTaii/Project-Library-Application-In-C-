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

}

void User::show_user() //show user
{
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    Person::display();
    cout << "Class: " << clas << endl;
    cout << "Book renting: " << rentBook << endl;
}

void User::add_user() //menu add user
{
    char null[1] = {'\x00'};
    system("cls");
    cout << "----------------New user-----------------" << endl;
    cin.ignore();
    cout << "Enter username: ";
    cin.getline(username,15);
    cout << "Enter password: ";
    cin.getline(password,20);
    Person::input();
    cout << "Enter class: ";
    cin.getline(clas,15);
    status = 0;
    strcpy(rentBook,null);
    format();
}

void User::update_user() //update user in file
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
    cout << "Enter username of user update: ";
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

void User::delete_user() // delete user in file
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

void User::search_user() // search user in file
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
    ofstream outFile;
    outFile.open("user.dat",ios::binary|ios::app);
    us.add_user();
    outFile.write(reinterpret_cast<char *> (&us), sizeof(User));
    cout << "Add User Successfully !" << endl;
    system("pause");
    system("cls");
	outFile.close();
}

bool User::updateUserRent(char s[]) //rent book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    bool found = false;
    cout << "Enter username of you (username as registered): ";
    cin.getline(tempName,50);
    cout << "Enter password of you: ";
    cin.getline(tempPass,50);

    File.open("user.dat",ios::binary|ios::in|ios::out);
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (this), sizeof(User));
        if(strcmp(tempName, retUsername())==0 && strcmp(tempPass,retPassword()) == 0)
        {
          if(status==1)
          {
            return false;
          }
          else
          {
            *username = *retUsername();
            *password = *retPassword();
            Person::setValueDefaut();
            for (int i = 0; i < strlen(s); i++)
            {
              rentBook[i] = s[i];
            }
            *clas = *retClass();
            status = 1;
            int pos=(-1)*static_cast<int>(sizeof(User));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (this), sizeof(User));
            return true;
          }
        }
    }
    File.close();
    return false;
}
bool User::updateUserReturn(char s[]) // return book
{
    fstream File;
    char tempName[50];
    char tempPass[50];
    char null[1] = {'\x00'};
    bool found = false;

    cout << "Enter username of you (username as registered): ";
    cin.getline(tempName,50);
    cout << "Enter password of you: ";
    cin.getline(tempPass,50);

    File.open("user.dat",ios::binary|ios::in|ios::out);
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (this), sizeof(User));
        if(strcmp(tempName, retUsername())==0 && strcmp(tempPass,retPassword())==0)
        {
          if(status==0)
          {
            return false;
          }
          else
          {
            *username = *retUsername();
            *password = *retPassword();
            Person::setValueDefaut();
            strcpy(rentBook,null);
            *clas = *retClass();
            status = 0;
            int pos=(-1)*static_cast<int>(sizeof(User));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (this), sizeof(User));
            return true;
          }
        }
    }
    File.close();
    return false;
}


void User::report() //template display
{
    cout << left << setw(20) << username << "\t" << left << setw(20) << password << "\t" << left << setw(20);
    Person::report();
    cout << left << setw(20) << clas << left << setw(2) << status << left << setw(20) << " " << rentBook << endl;
//    cout << username << setw(20) << password << setw(23) << getId() << setw(25) << getName() << setw(20) << getAge() << setw(23) << getMail() << setw(20) << clas;
}

void User::display()
{
    system("cls");
    fp3.open("user.dat",ios::in);

	cout << "\t\t\t\t\t\t\t\t\tUser LIST" << endl;
	cout << "=================================================================================================================================================================================================================\n";
	cout << left<<setw(20)<<"Username\t"<<left<<setw(20)<<"Password\t"<<left<<setw(20)<<"ID\t"<<left<<setw(20)<<"Name\t"<<left<<setw(20)<<"Age\t"<<left<<setw(35)<<"Mail\t"<<left<<setw(20)<<"Class" << left << setw(2) << "Status" << left << setw(20) << "\t\tRent Book" << endl;
	cout << "=================================================================================================================================================================================================================\n";

	while(fp3.read(reinterpret_cast<char*>(&us),sizeof(User)))
	{
		us.report();
	}
     	fp3.close();
     	getch();
}
char* User::retUsername()
{
    return username;
}

char* User::retPassword()
{
    return password;
}


int User::retId()
{
    return Person::getId();
}
char* User::retClass()
{
    return clas;
}

void User::format()
{
    char *s;
    s = General::format(clas);
}

User::~User()
{
    //dtor
}
