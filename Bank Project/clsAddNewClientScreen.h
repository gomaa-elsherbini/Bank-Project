#pragma once
#include "clsScreen.h"

class clsAddNewClientScreen:protected clsScreen
{
public:
	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName? ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Please enter LastName? ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Please enter Email? ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Please enter Phone? ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Please enter pinCode? ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Please enter AccountBalance? ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void AddNewClient()
	{
		_DrawScreenHeader("\tAdd New Client Screen");

		string AccountNumber = "";
		cout << "Enter The Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Already used, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient newClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(newClient);

		clsBankClient::enSaveResult saveResult;

		saveResult = newClient.Save();

		switch (saveResult)
		{
		
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError Account was not saved because it is empty!\n";
			Print(newClient);
			break;
		
		case clsBankClient::svSucceeded:
			cout << "\n\nClient successfully Added!\n";
			break;
		
		case clsBankClient::svFaildAccountNumberExist:
			cout << "\n\nError Account was not saved because it is Already Exists!\n";
			break;
		}

		Print(newClient);
	}
	
	static 	void Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________________________";
		cout << "\nFirstName  : " << Client.FirstName;
		cout << "\nLastName   : " << Client.LastName;
		cout << "\nFullName   : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email;
		cout << "\nPhone      : " << Client.Phone;
		cout << "\nAcc. Number: " << Client.AccountNumber;
		cout << "\nPassword   : " << Client.PinCode;
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n__________________________________________\n";
	}

};

