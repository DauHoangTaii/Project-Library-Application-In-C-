#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

namespace General
{
    string toLowerStr(string str);
    string toUpperStr(string str);
    void upper(char a[],int n);
    void remove(char a[], int k, int &n);
    void upperTitle(char a[],int n);
    char* format(char a[]);
    void clearStdin();
}

#endif // GENERAL_H
