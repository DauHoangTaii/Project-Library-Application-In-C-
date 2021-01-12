#include "Book.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include<stdio.h>
#include <cstdio>
#include "Dohoa.h"

using namespace std;

Book::Book()
{

}

// write file
fstream fp,fp1;
Book bk;


void Book::addBook() //menu add book
{
    system("cls");
    cout << "----------New Book----------" << endl;
    cout << "Enter id: ";
    cin >> id;
    fflush(stdin);
    cout << "Enter book name: ";
    cin.getline(name,50);
    cout << "Enter book brand: ";
    cin.getline(brand,50);
    cout << "Enter book author: ";
    cin.getline(author,50);
    cout << "Enter book price: ";
    cin >> price;
    format();
}

void Book::updateBook() //update book with id and name in file
{
    system("cls");
    fstream File;
    bool found=false;
    int n;
    string s;

	cout << "---------------Update Book----------------" << endl;
	cout << "Enter id of book update: ";
	cin >> n;
	while(n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of book: ";
        cin >> n;
    }
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
		    system("pause");
		  }
	}
	File.close();
	if(found==false)
		cout<<"Record Not Found ";
		system("pause");
}

void Book::deleteBook() //delete book with id and name in file
{
    system("cls");
    int n;
    string s;

	cout << "----------------DELETE BOOK----------------" << endl;
	cout << "Enter id of book delete: ";
	cin>>n;
	while(n < 0 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of book delete: ";
        cin >> n;
    }
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

void Book::searchBook() //search book with id and name
{
    int n;
    string s;
    bool found=false;
	fstream File;
    system("cls");

	cout << "---------------Search Book With ID-------------" << endl;
	cout << "Enter id of book: ";
	cin >> n;
	while(n < 1 || n > 9999999)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error: Invalid Choice. Please try again!" << endl;
        system("pause");
        system("cls");
        cout << "Enter id of book: ";
        cin >> n;
    }
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

void Book::showBook() // menu show book
{
    cout << "----------Show book----------" << endl;
    cout << "Book ID: " << id << endl;
    cout << "Book name: " << name << endl;
    cout << "Book brand: " << brand << endl;
    cout << "Book author: " << author << endl;
    cout << "Book price: " << price << endl;
}
void Book::wirteBook() // save book in file
{
	ofstream outFile;
    outFile.open("book.dat",ios::binary|ios::app);
    bk.addBook();
    outFile.write(reinterpret_cast<char *> (&bk), sizeof(Book));
    cout << "Add Book Successfully !" << endl;
    system("pause");
    system("cls");
	outFile.close();
}
void Book::display()  //display book in screen
{
    ifstream inFile;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	//Dohoa::setColor(2);
	cout << "\t\t\t\t\t\t\tBook LIST" << endl;
	cout << "========================================================================================================\n";
	cout << left<<setw(10)<<"Book ID"<<left<<setw(25)<<"Book Name"<<left<<setw(15)<<"Book brand"<<left<<setw(20)<<"Book Author"<<left<<setw(10)<<"Book price" << endl;
	cout << "========================================================================================================\n";

	while(inFile.read(reinterpret_cast<char*>(&bk),sizeof(Book)))
	{
		bk.report();
	}
     	fp.close();
     	getch();
}

int Book::retId() // return id in class
{
    return id;
}

string Book::retName() //return name in class
{
    return name;
}

void Book::format() // format data
{
    char *s;
    s = General::format(name);
    s = General::format(brand);
    s = General::format(author);
}


void Book::report() // show book
{
    cout << left << setw(10) << id << left << setw(25) << name << left << setw(15) << brand << left << setw(20) << author << left << setw(10) << price << endl;
}
Book::~Book()
{
    //dtor
}
