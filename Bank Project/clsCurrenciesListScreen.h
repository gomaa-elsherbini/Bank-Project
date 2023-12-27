#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"



class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency C)
	{
		cout << "\t"
			<< "| " << setw(28) << left << C.Country
			<< "| " << setw(10) << left << C.Code
			<< "| " << setw(40) << left << C.Name
			<< "| " << setw(20) << left << C.Rate;
	}
	static void _PrintCurrencyHeader(vector <clsCurrency> vCurrencies)
	{
		string Title = "\t   Currencies List Screen";
		string SubTitle = "\t	(" + to_string(vCurrencies.size()) + ") Currencies";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t" << "| " << left << setw(28) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(20) << "Rate/($)";
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		_PrintCurrencyHeader(vCurrencies);

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

			for (clsCurrency &Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

