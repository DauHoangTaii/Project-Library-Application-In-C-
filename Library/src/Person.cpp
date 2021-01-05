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
    id = 0;
    name = "N/A";
    age = 0;
    mail = "N/A";
}
void Person::input()
{
    cout << "Enter id: ";
    cin >> id;
    fflush(stdin);
    cout << "Enter name: ";
    getline(cin,name);
    cout << "Enter age: ";
    cin >> age;
    fflush(stdin);
    cout << "Enter mail: ";
    getline(cin,mail);
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
    cout << getId() << setw(25) << getName() << setw(23) << getAge() <<  setw(23) << getMail();
}
void Person::setId()
{
    this->id = id ;
}

int Person::getId()
{
    return id;
}

string Person::getName()
{
    return name ;
}

void Person::setName()
{
    this->name = name ;
}

int Person::getAge()
{
    return age ;
}

void Person::setAge()
{
    this->age = age ;
}

string Person::getMail()
{
    return mail ;
}

void Person::setMail()
{
    this->mail = mail ;
}

Person::~Person()
{
    //dtor
}
