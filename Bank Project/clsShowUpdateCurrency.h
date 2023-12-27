#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsShowUpdateCurrency:protected clsScreen
{
private:
	static void _Print(clsCurrency C)
	{
		cout << "\nCurrency Card:\n";
		cout << "\n__________________________________________";
		cout << "\nCountry  : " << C.Country;
		cout << "\nCode     : " << C.Code;
		cout << "\nName : " << C.Name;
		cout << "\nRate/($)     : " << C.Rate;
		cout << "\n__________________________________________\n";
	}
	static void _UpdateRate()
	{
		float NewRate;
		char answer = 'n';

		cout << "Enter The Currency Code? ";
		string Name = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::Find(Name);

		while (Currency.Code =="")
		{
			cout << "Currency Is Not Found, Choose Another One: ";
			Name = clsInputValidate::ReadString();
		}

		_Print(Currency);

		cout << "\n\nAre you sure you want to update the Rate of this Currency? y/n ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "_______________\n";

			cout << "\n\nEnter New Rate: ";
			NewRate = clsInputValidate::ReadFloatNumber();

			Currency.UpdateRate(NewRate);

			cout << "\n\nCurrency Rate Updated Successfully :-)!\n\n";
			
			_Print(Currency);
		}
	}
public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");
		_UpdateRate();
	}
};

