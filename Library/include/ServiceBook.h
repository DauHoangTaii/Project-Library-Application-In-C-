#ifndef SERVICEBOOK_H
#define SERVICEBOOK_H
#include <iostream>
#include "User.h"
#include "Book.h";
using namespace std;


class ServiceBook:public User,public Book
{
    public:
        ServiceBook();
        virtual ~ServiceBook();
        void rentBook();
        void returnBook();

    protected:

    private:
};

#endif // SERVICEBOOK_H
