#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
using namespace std;



class clsUpdateClientScreen:clsScreen
{
private:
	static void _UpdateClient()
	{
		string AccountNumber = "";

		cout << "Enter The Account Number for Client to update? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsAddNewClientScreen::Print(Client);

		cout << "\nUpdate Client Info:\n";
		cout << "_______________\n";

		clsAddNewClientScreen::ReadClientInfo(Client);

		clsBankClient::enSaveResult saveResult;

		saveResult = Client.Save();

		switch (saveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account was not saved because it is empty!\n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\n\nClient successfully Updated!\n\n";
			clsAddNewClientScreen::Print(Client);
			break;
		}
	}
public:
	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("\tUpdate Client Screen");
		_UpdateClient();
	}
};

