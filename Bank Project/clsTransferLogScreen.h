#pragma once
#include "clsScreen.h"
#include "clsTransferLog.h"


class clsTransferLogScreen : protected clsScreen
{

private:
	static void _PrintTransferLogRecordLine(clsTransferLog TR)
	{
		cout << "\t"
			<< "| " << setw(23) << left << TR.Date
			<< "| " << setw(8) << left << TR.AccoountOne
			<< "| " << setw(8) << left << TR.AccoountTwo
			<< "| " << setw(8) << left << TR.Ammount
			<< "| " << setw(13) << left << TR.AccoountOneBalance
			<< "| " << setw(13) << left << TR.AccoountTwoBalance
			<< "| " << setw(15) << left << TR.UserName;
	}
	static void _PrintTransferLogHeader(vector <clsTransferLog> vTransferLogs)
	{
		string Title = "\t   Transfer Log List Screen";
		string SubTitle = "\t	(" + to_string(vTransferLogs.size()) + ") Clients";

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "Acc.One";
		cout << "| " << left << setw(8) << "Acc.Two";
		cout << "| " << left << setw(8) << "Ammount";
		cout << "| " << left << setw(10) << "AccOneBalance";
		cout << "| " << left << setw(10) << "AccTwoBalance";
		cout << "| " << left << setw(15) << "UserName";
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	static void ShowTransferLogsList()
	{
		vector <clsTransferLog> vTransferLogs = clsTransferLog::_LoadTransferLogsFromFile();

		_PrintTransferLogHeader(vTransferLogs);

		if (vTransferLogs.size() == 0)
			cout << "\t\t\t\tNo Transfer Logs Available In the System!";
		else
			for (clsTransferLog& TR : vTransferLogs)
			{
				_PrintTransferLogRecordLine(TR);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

public:
	static void ShowTransferLogScreen()
	{
		_DrawScreenHeader("\tLogin Register Screen");
		ShowTransferLogsList();
	}
};

