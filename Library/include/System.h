#ifndef SYSTEM_H
#define SYSTEM_H
#define ADMINUSER "admin"
#define ADMINPASSWORD "admin123"

#define USER "user"
#define USERPASSWORD "user123"
#include <iostream>
using namespace std;
class System
{
    public:
        System();
        virtual ~System();
        void run();
    protected:
    private:
        bool login();
        void menu_main();
        void menu_admin_manager();
        void menu_user_manager();
        void menu_book_manager();
        void menu_user();
        string username;
        string password;
};

#endif // SYSTEM_H
