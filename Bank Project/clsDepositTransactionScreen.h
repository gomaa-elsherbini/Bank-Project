#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"



class clsDepositTransactionScreen:protected clsScreen
{
public:
	static void depositTransaction()
	{
		string AccountNumber = "";
		double depositAmmount = 0;
		char answer;

		_DrawScreenHeader("\tDeposit Screen");

		cout << "Enter The Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsAddNewClientScreen::Print(Client);

		cout << "\nPlease enter deposit ammount? ";
		cin >> depositAmmount;

		cout<<"\n\nAre you sure you want to perform this transaction? y/n ? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			Client.Deposit(depositAmmount);
			cout << "\nDone successfully, New Balance is: " << Client.AccountBalance << endl;
		}
	}
};

