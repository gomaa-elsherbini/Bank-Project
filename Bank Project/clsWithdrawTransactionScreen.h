#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"




class clsWithdrawTransactionScreen:protected clsScreen
{
public:
	static void WithDrawTransaction()
	{
		string AccountNumber = "";
		double WithdrawAmmount = 0;
		char answer;

		_DrawScreenHeader("\Withdraw Screen");

		cout << "Enter The Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsAddNewClientScreen::Print(Client);

		cout << "\nPlease enter Withdraw ammount? ";
		cin >> WithdrawAmmount;

		while (WithdrawAmmount > Client.AccountBalance)
		{
			cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;

			cout << "\nPlease enter another withdraw ammount? ";
			cin >> WithdrawAmmount;
		}

		cout << "\nAre you sure you want to perform this transaction? y/n ? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			Client.AccountBalance -= WithdrawAmmount;

			Client.Save();

			cout << "\nDone successfully, New Balance is: " << Client.AccountBalance << endl;
		}
	}
};

