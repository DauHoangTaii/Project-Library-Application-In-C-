#ifndef USER_H
#define USER_H
#include "Person.h"
#include "Date.h"
#include "General.h"
#include <iostream>
using namespace std;

class User:public Person
{
    public:
        User();
        virtual ~User();
        void add_user();
        void update_user();
        void delete_user();
        void search_user();
        void show_user();
        void write_user();
        void display();
        void report();
        int retId();
        string retUsername();
        string retPassword();
    protected:
    private:
        string username;
        string password;
        string clas;
        Date birthDate;
        void format();
};

#endif // USER_H
