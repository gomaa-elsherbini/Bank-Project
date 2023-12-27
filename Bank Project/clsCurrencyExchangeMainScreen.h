#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsShowUpdateCurrency.h"
#include "clsCurrencyCalculatorScreen.h"



class clsCurrencyExchangeMainScreen:protected clsScreen
{
private:
    enum enMainMenueOptions { eListCurrencies = 1, eFindCurrecy, eUpdateRate, eCurCalculator, eMainMenu };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\n\tPress any key to go back to Currencies Main Menue...";

        system("pause>0");
        ShowCurrencyExchangeMainMenue();
    }

    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesList();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsShowUpdateCurrency::ShowUpdateCurrencyScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::CurrencyCalculate();
    }
    
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListCurrencies:
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindCurrecy:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eMainMenu: {}
        }
    }

public:
	static void ShowCurrencyExchangeMainMenue()
	{
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

