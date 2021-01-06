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
        string getName();
        void setName();
        int getAge();
        void setAge();
        string getMail();
        void setMail();
    protected:

    private:
        void format();
        int id;
        string name;
        int age;
        string mail;
};

#endif // PERSON_H
