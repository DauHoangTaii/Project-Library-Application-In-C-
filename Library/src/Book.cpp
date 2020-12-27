#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

Book::Book()
{
    id = 0;
    name = "N/A";
    brand = "N/A";
    author = "N/A";
    price = 0;
}
void Book::addBook()
{
    cout << "----------New Book----------" << endl;
    cout << "Enter id: ";
    cin >> id;
    fflush(stdin);
    cout << "Enter book name: ";
    getline(cin,name);
    cout << "Enter book brand: ";
    getline(cin,brand);
    cout << "Enter book author: ";
    getline(cin,author);
    cout << "Enter book price: ";
    cin >> price;
}

void Book::updateBook()
{

}

void Book::deleteBook()
{

}

void Book::searchBook()
{

}

void Book::showBook()
{
    cout << "----------Show book----------" << endl;
    cout << "Book ID: " << id << endl;
    cout << "Book name: " << name << endl;
    cout << "Book brand: " << brand << endl;
    cout << "Book author: " << author << endl;
    cout << "Book price: " << price << endl;
}
// write file
fstream fp,fp1;
Book bk;
void Book::wirteBook()
{
    char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		bk.addBook();
		fp.write((char*)&bk,sizeof(Book));
		cout << "\n\nDo you want to add more record..(y/n?)";
		cin >> ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void Book::display()
{
    fp.open("book.dat",ios::in);

	cout << "\t\t\t\t\t\t\tBook LIST" << endl;
	cout << "========================================================================================================\n";
	cout << "Book ID"<<setw(20)<<"Book Name"<<setw(25)<<"Book brand"<<setw(20)<<"Book Author"<<setw(20)<<"Book price" << endl;
	cout << "========================================================================================================\n";

	while(fp.read((char*)&bk,sizeof(Book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}
void Book::report()
{
    cout << id << setw(25) << name << setw(25) << brand << setw(20) << author << setw(25) << price << endl;
}

Book::~Book()
{
    //dtor
}
