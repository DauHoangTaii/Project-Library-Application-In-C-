#ifndef MANAGEREMLOYEE_H
#define MANAGEREMLOYEE_H
#include <iostream>
#include <fstream>
#include <string>
#include "People.h"
#include "Teacher.h"
#include "Accountant.h"
#include <stdlib.h>
#define FILENAME "empFile.txt"
using namespace std;

class ManagerEmloyee
{
    public:
        ManagerEmloyee();
        virtual ~ManagerEmloyee();
        void addEmployee();
        void showEmployee();
        void searchEmployee();
        void deleteEmployee();
        void updateEmployee();
        int get_EmpNum();
        void init_Emp();
        void saveData();
        int IsExist(int id);
        bool fileIsEmpty = false;
        int numEmp;
        void loadData(ifstream &fi);
        People ** listEmp;
    protected:

    private:
};

#endif // MANAGEREMLOYEE_H
