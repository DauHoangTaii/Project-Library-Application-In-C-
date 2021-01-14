#ifndef PERSON_H
#define PERSON_H
#include <string.h>
#include <iostream>
#include "General.h"
using namespace std;

class Person
{
    public:
        Person();
        virtual ~Person();
        void input();
        void display();
        void report();
        void setId();
        int getId();
        char* getName();
        void setName();
        int getAge();
        void setAge();
        char* getMail();
        void setMail();
        void setValueDefaut();
    protected:

    private:
        void format();
        int id;
        char name[50];
        int age;
        char mail[50];
};

#endif // PERSON_H
