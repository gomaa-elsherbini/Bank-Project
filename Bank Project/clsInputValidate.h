#pragma once
#include "clsDate.h"
#include "clsString.h"
class clsInputValidate
{
public:

	template<typename T>T static IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	/*static bool IsNumberBetween(short num, short from, short to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(int num, int from, int to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float num, float from, float to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(double num, double from, double to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	*/	

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::CompareTwoDates(DateFrom, DateTo) == 1)
			clsDate::SwapDates(DateFrom, DateTo);

		if (clsDate::IsDateWithinPeriod(DateFrom, DateTo, Date))
			return true;
		else
			return false;
	}


	template<typename T> T static ReadTypteNumber()
	{
		T Number;
		cout << "Please enter a number? ";
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//cout << wrongMsg;

			cin >> Number;
		}
		return Number;
	}
	//static int ReadIntNumber(string wrongMsg = "Invalid Number, Enter again\n")
	//{
	//	int Number;
	//	cout << "Please enter a number? ";
	//	cin >> Number;
	//	while (cin.fail())
	//	{
	//		// user didn't input a number
	//		cin.clear();
	//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//		cout << wrongMsg;
	//		cin >> Number;
	//	}
	//	return Number;
	//}

	static double ReadDblNumber(string wrongMsg)
	{
		double Number;
		cout << "Please enter a number? ";
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << wrongMsg;
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string wrongMsg)
	{
		int Number;
		cout << "Please enter a number? ";
		cin >> Number;

		while (cin.fail() || Number < From || Number > To)
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << wrongMsg;

			cin >> Number;
		}
		return Number;
	}
	
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string Msg)
	{
		short Number;
		cout <<"\n\n" << Msg <<"\n";
		cin >> Number;

		while (cin.fail() || Number < From || Number > To)
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "\nIvalid Number, " << Msg<<" ";

			cin >> Number;
		}
		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string wrongMsg)
	{
		double Number;
		cout << "Please enter a number? ";
		cin >> Number;

		while (cin.fail() || Number < From || Number > To)
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << wrongMsg;

			cin >> Number;
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValid(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};

