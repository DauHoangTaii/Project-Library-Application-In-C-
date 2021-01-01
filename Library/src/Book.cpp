#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include<stdio.h>

using namespace std;

Book::Book()
{
    id = 0;
    name = "N/A";
    brand = "N/A";
    author = "N/A";
    price = 0;
}

// write file
fstream fp,fp1;
Book bk;


void Book::addBook()
{
    system("cls");
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
    system("cls");
    int n;
	int found=0;
	cout << "---------------Update Book----------------" << endl;
	cout << "Enter id of book update: ";
	cin >> n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(Book)) && found==0)
	{
		if(strcmpi((char*)bk.retId(),(char*)n)==0)
		{
			bk.showBook();
			cout << "Enter The New Details Of Book" << endl;
			bk.addBook();
			int pos=-1*sizeof(bk);
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&bk,sizeof(Book));
		    	cout << "Update Successfully";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout << "Book not found";
    	getch();
}

void Book::deleteBook()
{
    system("cls");
    int n;
	cout << "----------------DELETE BOOK----------------" << endl;
	cout << "Enter id of book delete: ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(1,ios::beg);
	while(fp.read((char*)&bk,sizeof(Book)))
	{
		if(strcmpi((char*)bk.retId(),(char*)n)!=0)
		{
			fp2.write((char*)&bk,sizeof(Book));
		}
	}

	fp2.close();
    	fp.close();
    	remove("book.dat");
    	rename("Temp.dat","book.dat");
    	cout << "Deleted Successfully" << endl;
    	system("pause");
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
int Book::retId()
{
    return id;
}
void Book::report()
{
    cout << id << setw(25) << name << setw(25) << brand << setw(20) << author << setw(25) << price << endl;
}
Book::~Book()
{
    //dtor
}
