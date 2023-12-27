#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"

using namespace std;



class clsFindClientScreen:clsScreen
{
private:
	static void _FindClient()
	{
		string AccountNumber = "";

		cout << "Enter The Account Number for Client to Find? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		cout << "\nClient Info:\n";
		clsAddNewClientScreen::Print(Client);
	}

public:
	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("\tFind Client Screen");
		_FindClient();
	}
};

