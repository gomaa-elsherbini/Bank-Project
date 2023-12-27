#pragma once





class clsDeleteClientScreen:protected clsScreen
{
private:
	static void DeleteClient()
	{
		char answer;

		string AccountNumber = "";
		cout << "Enter The Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsAddNewClientScreen::Print(Client);

		cout << "Are You Sure You To delete this Client y/n? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "Client Successfully Deleted! -:)\n";
				clsAddNewClientScreen::Print(Client);
			}
			else
				cout << "Client is not Deleted! -:(\n";
		}
	}
public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\tDelete Client Screen");
		DeleteClient();
	}


};

