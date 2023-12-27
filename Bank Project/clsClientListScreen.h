#pragma once
#include "clsMainScreen.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;



class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient C)
	{
		cout <<"\t"
			<< "| " << setw(15) << left << C.AccountNumber
			<< "| " << setw(20) << left << C.FullName()
			<< "| " << setw(12) << left << C.Phone
			<< "| " << setw(20) << left << C.Email
			<< "| " << setw(10) << left << C.PinCode
			<< "| " << setw(12) << left << C.AccountBalance;
	}
	static void _PrintClientsHeader(vector <clsBankClient> vClients)
	{
		string Title = "\t   Clients List Screen";
		string SubTitle = "\t	("+to_string(vClients.size()) + ") Clients";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout <<"\t" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ShowClientsList()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		_PrintClientsHeader(vClients);

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

