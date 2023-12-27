#pragma once
#include "Global.h"
#include "clsBankClient.h"
#include "clsDate.h"




class clsTransferLog
{
private:
	
	static clsTransferLog _ConvertLineToTransferLogObject(string line, string separator = "#//#")
	{//  22/12/2022 - 18:8:3#//#A101#//#A109#//#100.000#//#1500.000#//#2000.000#//#user2

		vector <string>strTransferLog = clsString::splitString(line, separator);

		return clsTransferLog(strTransferLog[0], strTransferLog[1],
			strTransferLog[2], stod(strTransferLog[3]), stod(strTransferLog[4]),
			stod(strTransferLog[5]), strTransferLog[6]);
	}

	static string _convertTransferLogObjectToLine(clsTransferLog TransferLog, string separator = "#//#")
	{
		string line = "";

		line += TransferLog.Date + separator;
		line += TransferLog.AccoountOne + separator;
		line += TransferLog.AccoountTwo + separator;
		line += to_string(TransferLog.Ammount) + separator;
		line += to_string(TransferLog.AccoountOneBalance) + separator;
		line += to_string(TransferLog.AccoountTwoBalance) + separator;
		line += TransferLog.UserName;

		return line;
	}

	static void _SaveTransferLogsToFile(vector <clsTransferLog> vTransferLogs)
	{
		fstream myfile;

		myfile.open("transferLogs.txt", ios::out);

		if (myfile.is_open())
		{
			for (clsTransferLog& TR : vTransferLogs)
				myfile << _convertTransferLogObjectToLine(TR) << "\n";
		}
		myfile.close();
	}

	void _AddNew()
	{
		vector <clsTransferLog> vTransferLogs = _LoadTransferLogsFromFile();

		vTransferLogs.push_back(*this);

		_SaveTransferLogsToFile(vTransferLogs);
	}

public:
	string Date;
	string AccoountOne;
	string AccoountTwo;
	double Ammount;
	double AccoountOneBalance;
	double AccoountTwoBalance;
	string UserName;

	clsTransferLog(string date, string accoountNumOne, string accoountNumTwo,
					double ammount, double accoountOneBalance,
					double accoountTwoBalance, string userName)
	{
		Date = date;
		AccoountOne = accoountNumOne;
		AccoountTwo = accoountNumTwo;
		Ammount = ammount;
		AccoountOneBalance = accoountOneBalance;
		AccoountTwoBalance = accoountTwoBalance;
		UserName = userName;
	}



	static vector <clsTransferLog> _LoadTransferLogsFromFile()
	{
		fstream TranferLogsFile;
		string line;
		vector <clsTransferLog> vTransferLogs;

		TranferLogsFile.open("transferLogs.txt", ios::in);

		if (TranferLogsFile.is_open())
		{
			while (getline(TranferLogsFile, line))
			{
				if (line != "")
					vTransferLogs.push_back(_ConvertLineToTransferLogObject(line));
			}
			TranferLogsFile.close();
		}
		return vTransferLogs;
	}

	void AddNewTransferLog()
	{
		_AddNew();
	}





};

