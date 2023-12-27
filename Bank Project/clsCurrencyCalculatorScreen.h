#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsFindCurrencyScreen.h"





class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCalculationResult(clsCurrency C1, clsCurrency C2, int Amount)
	{
		cout << "\n\n" << Amount << " " << C1.Code << " = "
			<< clsCurrency::_ConvertCurrency(C1, C2, Amount)
			<< " " << C2.Code;
	}
	static clsCurrency _GetCurrency()
	{
		string CCode = clsInputValidate::ReadString();

		clsCurrency C = clsCurrency::Find(CCode);

		while (C.Code == "")
		{
			cout << "Currency Is Not Found, Choose Another One: ";

			CCode = clsInputValidate::ReadString();
		}
		return C;
	}

public:
	static void CurrencyCalculate()
	{
		clsCurrency C1 = clsCurrency::Find("");
		clsCurrency C2 = clsCurrency::Find("");
		int Amount;
		char answer = 'n';

		do
		{
			system("cls");

			_DrawScreenHeader("\tCurrency Calculator");
			
			cout << "\n\nPlease Enter Currency1 Code: ";
			C1 = _GetCurrency();

			cout << "\n\nPlease Enter Currency2 Code: ";
			C2 = _GetCurrency();

			cout << "\n\nEnter Amount To Exchange: ";
			cin >> Amount;

			cout << "\n\nConvert From:\n";
			clsFindCurrencyScreen::_Print(C1);

			_PrintCalculationResult(C1, clsCurrency::Find("USD"), Amount);
			
			cout << "\n\nConverting From: "<<C1.Code<<" to:\n\n";
			clsFindCurrencyScreen::_Print(C2);
			
			_PrintCalculationResult(C1, C2, Amount);

			cout << "\n\nDo you want to do another calculatio? y/n ";
			cin >> answer;

		} while (answer=='y'|| answer=='Y');
	}
};

