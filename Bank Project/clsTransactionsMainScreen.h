#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositTransactionScreen.h"
#include "clsWithdrawTransactionScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;



class clsTransactionsMainScreen:protected clsScreen
{
private:
    enum enMainMenueOptions {eDeposit = 1, eWithdraw, eTotalBalances, eTransfer, eTransferLog, eMainMenu};

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
        ShowTransactionsMainMenue();
    }
    static void _ShowDepositTransactionScreen()
    {
        clsDepositTransactionScreen::depositTransaction();
    }
    static void _ShowWithdrawTransactionScreen()
    {
        clsWithdrawTransactionScreen::WithDrawTransaction();
    }
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eDeposit:
            system("cls");
            _ShowDepositTransactionScreen();
            _GoBackToMainMenue();
            break;
        
        case enMainMenueOptions::eWithdraw:
            system("cls");
            _ShowWithdrawTransactionScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToMainMenue();
            break;
        
        case enMainMenueOptions::eTransferLog:
        system("cls");
        _ShowTransferLogScreen();
        _GoBackToMainMenue();
        break;

        case enMainMenueOptions::eMainMenu:
        {
        }
        }
    }
    
public:

    static void ShowTransactionsMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\tTransactions Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};

