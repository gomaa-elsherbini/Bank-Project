#pragma once
#include <iostream>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;






class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode, UpdateMode, AddNewMode};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	bool _MarkToDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator="#//#")
	{
		vector <string>vClient = clsString::splitString(Line, Separator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static string _ConvertClientObjectToline(clsBankClient Client, string Separator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName;
		Line += Separator + Client.LastName;
		Line += Separator + Client.Email;
		Line += Separator + Client.Phone;
		Line += Separator + Client._AccountNumber;
		Line += Separator + Client._PinCode;
		Line += Separator + to_string(Client.AccountBalance);

		return Line;
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		fstream ClientsFile;
		string line;
		vector <clsBankClient> vClsClients;
		
		ClientsFile.open("clients.txt", ios::in);

		if (ClientsFile.is_open())
		{
			while (getline(ClientsFile, line))
			{
				if (line != "")
					vClsClients.push_back(_ConvertLineToClientObject(line));
			}
			ClientsFile.close();
		}
		return vClsClients;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream myFile;

		myFile.open("clients.txt", ios::out);

		if (myFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if(!C._MarkToDelete)
					myFile << _ConvertClientObjectToline(C) << "\n";
			}
			myFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

	void _AddNew()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFile();

		vClients.push_back(*this);
		
		_SaveClientsDataToFile(vClients);
	}



public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;
	__declspec(property(get = GetAccountNumber))string AccountNumber;


	string FullName()
	{
		return FirstName + " " + LastName;
	}

	static clsBankClient Find(string AccountNumber)
	{
		string fileName = "clients.txt";
		vector <clsBankClient> vClsClients = _LoadClientDataFromFile();

		for (clsBankClient& Client : vClsClients)
		{
			if (Client.AccountNumber == AccountNumber)
				return Client;
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		string fileName = "clients.txt";
		vector <clsBankClient> vClsClients = _LoadClientDataFromFile();

		for (clsBankClient& Client : vClsClients)
		{
			if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				return Client;
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		return !clsBankClient::Find(AccountNumber).IsEmpty();
	}
	
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFile();
		
		for (clsBankClient& C : vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C._MarkToDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	
	enum enSaveResult {svFaildEmptyObject=0, svSucceeded, svFaildAccountNumberExist};
	
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if(IsEmpty())
				return enSaveResult::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResult::svFaildAccountNumberExist;
			else
				_AddNew();
			enMode::UpdateMode;
			return enSaveResult::svSucceeded;
		}
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances(vector <clsBankClient> vClients)
	{
		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
			TotalBalances += Client.AccountBalance;

		return TotalBalances;
	}

	void Deposit(double amount)
	{
		_AccountBalance += amount;
		Save();
	}

	void Withdraw(double amount)
	{
		/*if (amount > _AccountBalance)
			return false;
		else
		{
		}*/
			_AccountBalance -= amount;
			Save();
	}


};

