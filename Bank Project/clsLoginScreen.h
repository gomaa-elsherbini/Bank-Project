#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsLoginRegister.h"
#include "clsDate.h"




class clsLoginScreen:protected clsScreen
{
private:
    static void _Login()
    {
        string UserName, Password;
        //string Date;
        
        system("cls");
        _DrawScreenHeader("\t\tLogin Screen");

        for (short i = 3; i >= 1; i--)
        {
            cout << "Enter User Name? ";
            UserName = clsInputValidate::ReadString();
            cout << "Enter Password? ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            if (!CurrentUser.IsEmpty())
            {
                clsLoginRegister LoginRegister(clsDate::GetCurrentTime());
                LoginRegister.AddNewLoginRegister();
                return;
            }
            else
            {
                cout << "\n\nInvalid UserName/Password\n";
                cout << "You have " << i - 1 << " trials To login\n\n";
            }
        }
        cout << "\n\nYou are Lokced after 3 failed trials\n";
    }
public:

    static void ShowLoginScreen()
    {
        while (true)
        {
            _Login();

            if (!CurrentUser.IsEmpty())
                clsMainScreen::ShowMainMenue();
            else
                return;
        }
    }
};

