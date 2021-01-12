#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string.h>
#include "General.h"
#include "Dohoa.h"
using namespace std;

class Book
{
    public:
        Book();
        virtual ~Book();
        void addBook();
        void updateBook();
        void deleteBook();
        void searchBook();
        void showBook();
        void wirteBook();
        void display();
        void report();
        int retId();
        string retName();
        void format();
    protected:

    private:
        int id;
        char name[50];
        char brand[50];
        char author[50];
        char status[15];
        int year,month,day;
        long long price;
};

#endif // BOOK_H
