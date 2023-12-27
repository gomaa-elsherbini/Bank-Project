#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
using namespace std;




class clsFindCurrencyScreen:protected clsScreen
{
private:
	enum enFindBy{eCode=1, eCounrty};

	
	static clsCurrency _GetCurrency()
	{
		string CodeOrCountry = clsInputValidate::ReadString();
		
		return clsCurrency::Find(CodeOrCountry);
	}
	
	static void _FindCurrency()
	{
		short choice;
		enFindBy eFindByOption;

		choice = clsInputValidate::ReadShortNumberBetween(1,2, "\n\nFind By: [1] Code or [2] Country ? ");

		eFindByOption = (enFindBy) choice;
		clsCurrency Currency = clsCurrency::Find("");

		switch (eFindByOption)
		{
		case clsFindCurrencyScreen::eCode:
			cout << "Enter The CurrencyCode to Find? ";
			Currency = _GetCurrency();
			break;
		
		case clsFindCurrencyScreen::eCounrty:
			cout << "Enter The Country of Currency? ";
			Currency = _GetCurrency();
			break;
		}

		if (Currency.IsEmpty())
			cout << "Currency Is Not Found :-(\n\n";
		else
			_Print(Currency);
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		_FindCurrency();
	}

	static void _Print(clsCurrency C)
	{
		cout << "\n__________________________________________";
		cout << "\nCountry  : " << C.Country;
		cout << "\nName     : " << C.Code;
		cout << "\nFullName : " << C.Name;
		cout << "\nRate(1$)    : " << C.Rate;
		cout << "\n__________________________________________\n";
	}
};

//static clsCurrency _FindCurrencyByCouontry()
	//{
	//	cout << "Enter The Country of Currency? ";
	//	string Country = clsInputValidate::ReadString();
	//	clsCurrency Currency = clsCurrency::Find(Country);
	//	while (Currency._Country == "")
	//	{
	//		cout << "Currency Is Not Found, Choose Another One: ";
	//		Country = clsInputValidate::ReadString();
	//	}
	//	return Currency;
	//}