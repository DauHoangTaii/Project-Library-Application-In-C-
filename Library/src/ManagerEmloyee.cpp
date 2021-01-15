#include "ManagerEmloyee.h"

ManagerEmloyee::ManagerEmloyee()
{
     ifstream ifs;
     ifs.open(FILENAME, ios::in);
     if (!ifs.is_open())
     {
          this->numEmp = 0;  //Initial record the number of people
          this->listEmp = NULL; //Initialize the array pointer
          this->fileIsEmpty = true;  //Is the initialization file empty
          ifs.close();
          return;
     }
     //File exists, data is empty
     char ch;
     ifs >> ch;
     if (ifs.eof())
     {
          this->numEmp = 0;  //Initial record the number of people
          this->listEmp = NULL; //Initialize the array pointer
          this->fileIsEmpty = true;  //Is the initialization file empty
          ifs.close();
          return;
     }
     //When the file exists and records data
     int num = this->get_EmpNum();
     this->numEmp = num;
     this->listEmp = new People*[this->numEmp];
     this->init_Emp();
}

ManagerEmloyee::~ManagerEmloyee()
{
    //dtor
}
void ManagerEmloyee::addEmployee()
{
    cout << "Please enter the number of employees added:" << endl;
    int addNum = 0;  //Save the number of user input
    cin >> addNum;
    if(addNum > 0)
    {
        int newSize = this->numEmp + addNum;
        People ** newSpace = new People*[newSize];
        if (this->listEmp != NULL)
        {
            for (int i = 0; i < this->numEmp; i++)
            {
                newSpace[i] = this->listEmp[i];
            }
        }
        //Add new data in batch
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int age;
            string mail;
            float basic_salary;
            float cft_salary;
            int dSelect;

            cout << "Please select this employee position" << endl;
            cout << "1. Teacher" << endl;
            cout << "2. Accountant" << endl;
            cin >> dSelect;

            cout << "Employee " << i+1 << endl;
            cout << "Enter id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin,name);
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter mail: ";
            getline(cin,mail);
            cout << "Enter basic salary: ";
            cin >> basic_salary;
            cout << "Enter Coefficients salary: ";
            cin >> cft_salary;
            People * people = NULL;
            switch (dSelect)
            {
            case 1:
                people = new Teacher(1, id, name, age, mail, basic_salary, cft_salary);
                break;
            case 2:
                people = new Accountant(2, id, name, age, mail, basic_salary, cft_salary);
                break;
            default:
                break;
            }
        newSpace[this->numEmp + i] = people;
        }
        delete[] this->listEmp;
        this->listEmp = newSpace;
        this->numEmp = newSize;
        this->fileIsEmpty = false;  //The employee is not empty
        cout << "Successfully added :)" << endl;
        //Save data to file
        this->saveData();
    }
    else
    {
        cout << "Input error!" << endl;
    }
    system("pause");
    system("cls");
}

void ManagerEmloyee::showEmployee()
{
     if (this->fileIsEmpty)
     {
        cout << "The file does not exist or the record is empty!" << endl;
     }
     else
     {
        for (int i = 0; i < numEmp; i++)
          {
            this->listEmp[i]->showInfo();
          }
     }
     system("pause");
     system("cls");
}

void ManagerEmloyee::searchEmployee()
{

}

void ManagerEmloyee::deleteEmployee()
{
    if (this->fileIsEmpty)
     {
        cout << "The file does not exist or the record is empty!" << endl;
     }
     else
     {
          //Delete employees by number
          cout << "Please enter the employee number you want to delete:" << endl;
          int id = 0;
          cin >> id;
          int index = this->IsExist(id);
          if (index != -1) //The employee exists, and the employee at the index position is to be deleted
          {
           //Data forward
               for (int i = index; i < this->numEmp - 1; i++)
               {
                    this->listEmp[i] = this->listEmp[i + 1];
               }
               this->numEmp--;//Update the number of personnel recorded in the array
               //Sync update to file
               this->saveData();
               cout << "successfully deleted!" << endl;
        }
        else
        {
           cout << "Deletion failed! The employee was not found!" << endl;
        }
     }
     system("pause");
     system("cls");
}

int ManagerEmloyee::IsExist(int tempId)
{
     int index = -1;
     for (int i = 0; i < this->numEmp; i++)
     {
          if (this->listEmp[i]->id == tempId)
          {
               index = i;
               break;
          }
     }
     return index;
}


void ManagerEmloyee::updateEmployee()
{

}

int ManagerEmloyee::get_EmpNum()
{
     ifstream ifs;
     ifs.open(FILENAME, ios::in); // open file read file
     int option;
     int id;
     string name;
     int age;
     string mail;
     float basic_salary;
     float cft_salary;
     int num = 0;

     while (ifs >> option && ifs >> id && ifs >> name && ifs >> age && ifs >> mail && ifs >> basic_salary && ifs >> cft_salary)
     {
      //Count the number of people
      num++;
     }
    return num;
}

void ManagerEmloyee::saveData()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out | ios::app); //Open the file with output-write file
    //Write everyone's data to the file
    for (int i = 0; i < this->numEmp; i++)
    {
        ofs << this->listEmp[i]->option << ", " << this->listEmp[i]->id << ", "<< this->listEmp[i]->name << ", " << this->listEmp[i]->age << ", " << this->listEmp[i]->mail << ", " << this->listEmp[i]->basic_salary << ", " << this->listEmp[i]->cft_salary << endl;
    }
    //Close the file
    ofs.close();
}
void ManagerEmloyee::init_Emp()
{
     ifstream ifs;
     ifs.open(FILENAME, ios::in); // open file read file
     int option;
     int id;
     string name;
     int age;
     string mail;
     float basic_salary;
     float cft_salary;
     int index = 0;

     while (ifs >> option && ifs >> id && ifs >> name && ifs >> age && ifs >> mail && ifs >> basic_salary && ifs >> cft_salary)
     {
          People *peole = NULL;
          if (option == 1)
          {
            peole = new Teacher(option, id, name, age, mail, basic_salary, cft_salary);
          }
          else if (option == 2)
          {
            peole = new Accountant(option, id, name, age, mail, basic_salary, cft_salary);
          }
          this->listEmp[index] = peole;
          index++;
     }
     ifs.close();
}
