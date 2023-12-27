#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMainScreen.h"
#include "clsManageUsersMainScreen.h"
#include "clsLoginScreen.h"
#include "clsAccessDenied.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
using namespace std;





class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister, eCurrencyExchange, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pListClients))
            clsClientListScreen::ShowClientsList();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowAddNewClientsScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pAddNewClient))
            clsAddNewClientScreen::AddNewClient();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowDeleteClientScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pDeleteClient))
            clsDeleteClientScreen::ShowDeleteClientScreen();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowUpdateClientScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pUpdateClient))
            clsUpdateClientScreen::ShowUpdateClientScreen();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowFindClientScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pFindClient))
            clsFindClientScreen::ShowFindClientScreen();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowTransactionsMenue()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pTransactions))
            clsTransactionsMainScreen::ShowTransactionsMainMenue();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowManageUsersMenue()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pManageUsers))
            clsManageUsersMainScreen::ShowManageUsersMainMenue();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowLoginRegisterScreen()
    {
        if (CurrentUser.ValidateUser(clsUser::enPermissions::pLoginRegistersList))
            clsLoginRegisterScreen::ShowLoginRegisterScreen();
        else
            clsAccessDenied::accessDenied();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMainMenue();
    }
    static void _LogOut()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            ShowMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        
        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _LogOut();
            break;
        }
    }

    
public:

    static void ShowMainMenue()
    {
        system("cls");

        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

