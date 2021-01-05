#ifndef GENERAL_H
#define GENERAL_H

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

namespace General
{
    // https://stackoverflow.com/questions/11188952/why-does-codeblocks-show-multiple-definition-of-error
    string toLowerStr(string str);
    string toUpperStr(string str);
    long long findInLower(string haystack, string needle);
    bool choice(string question);
    int choice(string question, int maxChoice);

    char toUpperChar(char ch);
    char toLowerChar(char ch);
    string format(string name);
    void clearStdin();
}

#endif // GENERAL_H
