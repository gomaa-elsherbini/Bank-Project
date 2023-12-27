#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"

using namespace std;


class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _PrintClientBalanceRecordLine(clsBankClient C)
	{
		cout << "\t\t| " << setw(15) << left << C.AccountNumber
			 << "| " << setw(40) << left << C.FullName()
			 << "| " << setw(20) << left << C.AccountBalance;
	}
	static void _PrintClientsBalancesHeader(vector <clsBankClient> vClients)
	{
		_DrawScreenHeader("\t Balances List Screen");

		cout << "\n\t\t\t\t\t\t\Balances List (" << vClients.size() << ") Client(s).";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t\t| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(20) << "Balance";
		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
public:
	static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = clsBankClient::GetTotalBalances(vClients);

		_PrintClientsBalancesHeader(vClients);

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient& Client : vClients)
			{
				_PrintClientBalanceRecordLine(Client);
				cout << endl;
			}

		cout << "\n\t\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t\t\t\tTotal Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t(" << clsUtil::numberToText(TotalBalances) << ")" << endl;
	}

};

