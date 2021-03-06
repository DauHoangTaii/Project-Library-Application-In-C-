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


Person::Person()
{
    //ctr
}
void Person::input()
{
    loop:
    cout << "Enter id: ";
    cin >> id;
    while(!cin.good() || id < 0 || id > 9999999)
    {
      cin.clear ();
      cin.ignore( 256, '\n' );
      cout << "Enter id: ";
      cin >> id;
    }
    fstream File;
    Person ps;
    File.open("user.dat",ios::binary|ios::in|ios::out);
	while(!File.eof())
	{
		File.read(reinterpret_cast<char *> (&ps), sizeof(Person));
		if(ps.getId()==id)
		{
		    cout << "This ID already exists :( " << endl;
		    goto loop;
        }
	}
	File.close();
    fflush(stdin);
    do
    {
        cout << "Enter name: ";
        cin.getline(name,50);
    }while(strlen(name) < 1);
    cout << "Enter age: ";
    cin >> age;
    while(!cin.good() || age < 0)
    {
      cin.clear ();
      cin.ignore( 256, '\n' );
      cout << "Enter age: ";
      cin >> age;
    }
    fflush(stdin);
    do
    {
        cout << "Enter mail: ";
        cin.getline(mail,50);
    }while(strlen(mail) < 1);
    format();
}

void Person::display()
{
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Mail: " << getMail() << endl;
}
void Person::report()
{
    cout << left << setw(20) << getId() << "\t" << left << setw(20) << getName() << "\t" << left << setw(20) << getAge() << "\t" << left << setw(35) << getMail() << "\t";
}
void Person::setValueDefaut()
{
    id = getId();
    *name = *getName();
    age = getAge();
    *mail = *getMail();
}

void Person::setId()
{
    this->id = id ;
}

int Person::getId()
{
    return id;
}

char* Person::getName()
{
    return name ;
}


int Person::getAge()
{
    return age ;
}

void Person::setAge()
{
    this->age = age ;
}

char* Person::getMail()
{
    return mail ;
}

void Person::format()
{
    char *s;
    s = General::format(this->name);
}

Person::~Person()
{
    //dtor
}
