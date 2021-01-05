#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string.h>
#include "General.h"
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
        string name;
        string brand;
        string author;
        int year,month,day;
        long long price;
};

#endif // BOOK_H
