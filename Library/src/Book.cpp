#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include<stdio.h>
#include <cstdio>

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
    fstream File;
    bool found=false;
    int n;
    string s;

	cout << "---------------Update Book----------------" << endl;
	cout << "Enter id of book update: ";
	cin >> n;
	cin.ignore();
    cout << "Enter name of book update: ";
    getline(cin,s);

    File.open("book.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&bk), sizeof(Book));
		if(bk.retId()==n && bk.retName()==s)
		{
		    cout << "Current data" << endl;
			bk.showBook();
			system("pause");
			cout << "Enter The New Details of Book"<<endl;
			bk.addBook();
			int pos=(-1)*static_cast<int>(sizeof(Book));
			File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&bk), sizeof(Book));
		    cout << "Update Successfully !!";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"Record Not Found ";
}

void Book::deleteBook()
{
    system("cls");
    int n;
    string s;

	cout << "----------------DELETE BOOK----------------" << endl;
	cout << "Enter id of book delete: ";
	cin>>n;
	cin.ignore();
	cout << "Enter name of book delete: ";
	getline(cin,s);

	ifstream inFile;
	ofstream outFile;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&bk), sizeof(Book)))
	{
		if(bk.retId()!=n && bk.retName() != s)
		{
			outFile.write(reinterpret_cast<char *> (&bk), sizeof(Book));
		}
	}
    inFile.close();
	outFile.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout << "Delete Successfully" << endl;
    system("pause");
}

void Book::searchBook()
{
    int n;
    string s;
    bool found=false;
	fstream File;
    system("cls");

	cout << "---------------Search Book With ID-------------" << endl;
	cout << "Enter id of book: ";
	cin >> n;
	cin.ignore();
    cout << "Enter name of book: ";
    getline(cin,s);

    File.open("book.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&bk), sizeof(Book));
		if(bk.retId()==n)
		{
		    system("cls");
			bk.showBook();
			system("pause");
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout << "Record Not Found " << endl;
		system("pause");
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
		fp.write(reinterpret_cast<char*>(&bk),sizeof(Book));
		cout << "Add Book Successfully !" << endl;
		system("pause");
		system("cls");
		cout << "Do you want to add more record..(y/n?)";
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

string Book::retName()
{
    return name;
}

void Book::format()
{

}


void Book::report()
{
    cout << id << setw(25) << name << setw(25) << brand << setw(20) << author << setw(25) << price << endl;
}
Book::~Book()
{
    //dtor
}
