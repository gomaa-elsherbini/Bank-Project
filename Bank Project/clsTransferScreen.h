#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsTransferLog.h"


class clsTransferScreen : protected clsScreen
{
private:
	static clsBankClient _GetClientToTransfer(string msg)
	{
		cout << msg;
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return clsBankClient::Find(AccountNumber);
	}
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________________________";
		cout << "\nFullName   : " << Client.FullName();
		cout << "\nAcc. Number: " << Client.AccountNumber;
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n__________________________________________\n";
	}

public:
	static void ShowTransferScreen()
	{
		char answer='n';
		double Amount = 0;

		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient CToTransferFrom = 
			_GetClientToTransfer("\n\nEnter The Account Number To Transfer From? ");
		_Print(CToTransferFrom);

		clsBankClient CToTransferTo =
			_GetClientToTransfer("\n\nEnter The Account Number To Transfer To? ");
		_Print(CToTransferTo);
		
		cout << "\n\nEnter The Transfer Amount? ";
		cin >> Amount;

		while (Amount > CToTransferFrom.AccountBalance)
		{
			cout << "\n\nAmount Exceeds the Available balance, Enter another withdraw ammount? ";
			cin >> Amount;
		}

		cout << "\nAre you sure you want to perform this transaction? y/n ? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			CToTransferFrom.Withdraw(Amount);
			CToTransferTo.Deposit(Amount);

			clsTransferLog TR
			(clsDate::GetCurrentTime(), CToTransferFrom.AccountNumber,CToTransferTo.AccountNumber, Amount,
			CToTransferFrom.AccountBalance, CToTransferTo.AccountBalance, CurrentUser.UserName);
			
			TR.AddNewTransferLog();
			
			cout << "\nTransfer Done successfully"<< endl;
		}
		_Print(CToTransferTo);
		_Print(CToTransferTo);
	}
};
