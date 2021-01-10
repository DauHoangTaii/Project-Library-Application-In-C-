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
    cout << "Enter id: ";
    cin >> id;
    fflush(stdin);
    cout << "Enter name: ";
    cin.getline(name,50);
    cout << "Enter age: ";
    cin >> age;
    fflush(stdin);
    cout << "Enter mail: ";
    cin.getline(mail,50);
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

void Person::format()
{
//    this->name = General::format(this->name);
}

Person::~Person()
{
    //dtor
}
