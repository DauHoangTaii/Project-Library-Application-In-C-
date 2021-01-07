#ifndef SYSTEM_H
#define SYSTEM_H
#define ADMINUSER "admin"
#define ADMINPASSWORD "admin"

#define USER "user"
#define USERPASSWORD "user123"
#include "General.h"
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
        void login_user();
        void menu_main();
        void menu_admin_manager();
        void menu_user_manager();
        void menu_book_manager();
        void menu_user();
        void menu_worker_manager();
        void format();
};

#endif // SYSTEM_H
