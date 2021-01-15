#include "Accountant.h"

Accountant::Accountant()
{
    //ctor
}

Accountant::~Accountant()
{
    //dtor
}
void Accountant::showInfo()
{
    cout << "-------------INFORMATION ACCOUNTANT--------------" << endl;
    cout << " - Accountant ID: " << this->id << endl;
    cout << " - Accountant Name: " << this->name << endl;
    cout << " - Accountant Age: " << this->age << endl;
    cout << " - Accountant Mail: " << this->mail << endl;
    cout << " - Post: " << this->getDeptName() << endl;
    cout << " - Basic Salary: " << this->basic_salary << endl;
    cout << " - Coefficients salary: " << this->cft_salary << endl;
    cout << " - Total Salary: " << this->basic_salary * this->cft_salary << endl;
}

string Accountant::getDeptName()
{
    return string("Accountant");
}

Accountant::Accountant(int option, int id, string name, int age, string mail, float basic_salary, float cft_salary)
{
    this->option = option;
    this->id = id;
    this->name = name;
    this->age = age;
    this->mail = mail;
    this->basic_salary = basic_salary;
    this->cft_salary = cft_salary;
}
