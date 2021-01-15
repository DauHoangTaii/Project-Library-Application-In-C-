#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
using namespace std;
#include <string>

class People
{
    public:
        People();
        virtual ~People();
        int option;
        int id;
        string name;
        int age;
        string mail;
        float basic_salary;
        float cft_salary;
        virtual void showInfo() = 0;
        virtual string getDeptName() = 0;
        void input();
    protected:

    private:
};

#endif // PEOPLE_H
