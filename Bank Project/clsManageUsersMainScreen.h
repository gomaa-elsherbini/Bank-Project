#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUsersListScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersMainScreen:protected clsScreen
{
    private:
        enum enMainMenueOptions {
            eListUsers = 1, eAddNewUser, eUpdateUser,
            eDeleteUser, eFindUser, eMainMenu};

        static short _ReadMainMenueOption()
        {
            cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
            return Choice;
        }
        static  void _GoBackToMainMenue()
        {
            cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...";

            system("pause>0");
            ShowManageUsersMainMenue();
        }

        static void _ShowUsersListScreen()
        {
            clsListUsersScreen::ShowUsersList();
        }
        static void _ShowAddNewUserScreen()
        {
            clsAddNewUserScreen::AddNewUser();
        }
        static void _ShowUpdateUserScreen()
        {
            clsUpdateUserScreen::ShowUpdateUserScreen();
        }
        static void _ShowDeleteUserScreen()
        {
            clsDeleteUserScreen::ShowDeleteUserScreen();
        }
        static void _ShowFindUserScreen()
        {
            clsFindUserScreen::ShowFindClientScreen();
        }

        static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListUsers:
            {
                system("cls");
                _ShowUsersListScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewUser:
                system("cls");
                _ShowAddNewUserScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateUser:
                system("cls");
                _ShowUpdateUserScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteUser:
                system("cls");
                _ShowDeleteUserScreen();
                _GoBackToMainMenue();
                break;
            case enMainMenueOptions::eFindUser:
                system("cls");
                _ShowFindUserScreen();
                _GoBackToMainMenue();
                break;
            case enMainMenueOptions::eMainMenu:
                break;
            }
        }

    public:

        static void ShowManageUsersMainMenue()
        {

            system("cls");
            _DrawScreenHeader("\Manage Users Main Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Update User.\n";
            cout << setw(37) << left << "" << "\t[4] Delete User.\n";
            cout << setw(37) << left << "" << "\t[5] Find User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }
    };



