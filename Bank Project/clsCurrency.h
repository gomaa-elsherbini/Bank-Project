#pragma once
#include <iostream>
#include <fstream>
#include "clsString.h"
using namespace std;



class clsCurrency
{
private:
	enum enMode {EmptyMode, UpdateMode};
	enMode _Mode;
	
	string _Country;
	string _Code;
	string _Name;
	float  _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator="#//#")
	{
		vector <string>vCurrency = clsString::splitString(Line, Separator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	
	static string _ConvertCurrencyObjectToline(clsCurrency Currency, string Separator = "#//#")
	{
		string Line = "";

		Line += Currency._Country + Separator;
		Line += Currency._Code + Separator;
		Line += Currency._Name + Separator;
		Line += to_string(Currency._Rate);

		return Line;
	}

	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{
		fstream CurrenciesFile;
		string line;
		vector <clsCurrency> vClsCurrencis;
		
		CurrenciesFile.open("Currencies.txt", ios::in);

		if (CurrenciesFile.is_open())
		{
			while (getline(CurrenciesFile, line))
			{
				if (line != "")
					vClsCurrencis.push_back(_ConvertLineToCurrencyObject(line));
			}
			CurrenciesFile.close();
		}
		return vClsCurrencis;
	}

	static void _SaveClientsDataToFile(vector <clsCurrency> vClsCurrencis)
	{
		fstream myFile;

		myFile.open("Currencies.txt", ios::out);

		if (myFile.is_open())
		{
			for (clsCurrency& C : vClsCurrencis)
				myFile << _ConvertCurrencyObjectToline(C) << "\n";
			
			myFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> vClsCurrencis = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vClsCurrencis)
		{
			if (C._Code == _Code)
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClsCurrencis);
	}

	static clsCurrency _GetEmptyCurrency()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:
	
	clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code  = Code;
		_Name = Name;
		_Rate = Rate;
	}

	string GetCountry()
	{
		return _Country;
	}
	__declspec(property(get = GetCountry))string Country;
	
	string GetCode()
	{
		return _Code;
	}
	__declspec(property(get = GetCode))string Code;
	
	string GetName()
	{
		return _Name;
	}
	__declspec(property(get = GetName))string Name;
	
	void UpdateRate(float Rate)
	{
		_Rate=Rate;
		_Update();
	}
	float GetRate()
	{
		return _Rate;
	}
	__declspec(property(get = GetRate, put= UpdateRate))float Rate;

	static clsCurrency Find(string CodeOrCountry)
	{
		fstream CurrenciesFile;
		string line;

		CodeOrCountry = clsString::upperAllLettersOfString(CodeOrCountry);

		CurrenciesFile.open("Currencies.txt", ios::in);

		if (CurrenciesFile.is_open())
		{
			while (getline(CurrenciesFile, line))
			{
				if (line != "")
				{
					clsCurrency C = _ConvertLineToCurrencyObject(line);
					
					if (CodeOrCountry.length() > 3)
					{
						if (clsString::upperAllLettersOfString(C.Country) == CodeOrCountry)
						{
							CurrenciesFile.close();
							return C;
						}
					}
					else
					{
						if (C.Code == CodeOrCountry)
						{
							CurrenciesFile.close();
							return C;
						}
					}
				}
			}
		}
		return _GetEmptyCurrency();
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	static double _ConvertCurrency(clsCurrency C1, clsCurrency C2, int Amount)
	{
		return (C2._Rate / C1._Rate) * Amount;
	}

	bool IsEmpty()
	{
		return _Mode==enMode::EmptyMode;
	}

};