#include "General.h"


string General::toLowerStr(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    return str;
}

string General::toUpperStr(string str)
{
    for(int i=0; i<str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return str;

}

long long General::findInLower(string haystack, string needle)
{
    haystack = toLowerStr(haystack);
    needle = toLowerStr(needle);
    return haystack.find(needle);
}

bool General::choice(string question)
{
    char choice;
    cout << question << " (Y/n): ";
    cin >> choice;
    while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'))
    {
        fflush(stdin);
        cout << "Your choice is invalid! Please choice again." << endl;
        cout << question << " (Y/n): ";
        cin >> choice;
    }
    if (choice == 'y' || choice == 'Y')
    {
        return true;
    }
    return false;
}

int General::choice(string question, int maxChoice)
{
    int choice;
    cout << question;
    cin >> choice;
    while (choice <0 || choice > maxChoice)
    {
        fflush(stdin);
        cout << "Your choice is invalid! Please choice again." << endl;
        cout << question;
        cin >> choice;
    }
    return choice;

}

char General::toUpperChar(char ch)
{
    if ('a' <= ch && ch <= 'z')
        ch = ch - 32;
    return ch;
}

char General::toLowerChar(char ch)
{
    if ('A' <= ch && ch <= 'Z')
        ch = ch + 32;
    return ch;
}

string General::format(string name)
{
    // Create new name string
    string newName;
    // Duyet cac ky tu trong name
    for(int i=0; i<name.length(); i++)
    {
        // Lay ky tu hien tai
        char ch = name[i];
        // Kiem tra ky tu do co phai la khoang trang hay khong
        bool isWhiteSpace = ch == ' ' || ch == '\t';
        if (isWhiteSpace)
        {
            // When begin char(s) is a white space
            if (newName.length() == 0)
                continue;
            // Check the last char of new name is a space
            bool isEndBySpace = newName[newName.length() - 1] == ' ';
            if (isEndBySpace)
                continue;
            else
                newName += ' ';
        }
        else
        {
            if (newName.length() == 0 || newName[newName.length()-1] == ' ')
                newName += toUpperChar(ch);
            else
                newName += toLowerChar(ch);
        }
    }
    return newName;
}

void General::clearStdin()
{
    cin.clear();
    fflush(stdin);
}
