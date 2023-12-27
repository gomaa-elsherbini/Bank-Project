#pragma once
#pragma warning(disable : 4996) 
#include <ctime>
#include <string>
#include <fstream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
#include "clsString.h"
using namespace std;



class clsLoginRegister
{
private:
	string _Date;
	string _UserName;
	string _Password;
	short  _Permissions;

	static clsLoginRegister _ConvertLineToLoginRegisterObject(string line, string separator = "#//#")
	{//  22/12/2022 - 18:8:3#//#user1#//#1234#//#-1

		vector <string>strLoginRegister = clsString::splitString(line, separator);

		return clsLoginRegister(strLoginRegister[0], strLoginRegister[1],
								strLoginRegister[2], stoi(strLoginRegister[3]));
	}
	static string _convertLoginRegisterObjectToLine(clsLoginRegister LoginRegister, string separator = "#//#")
	{
		string line = "";
	
		line += LoginRegister._Date + separator;
		line += LoginRegister._UserName + separator;
		line += LoginRegister._Password + separator;
		line += to_string(LoginRegister._Permissions);

		return line;
	}
	static void _SaveUsersDataToFile(vector <clsLoginRegister> vLoginRegister)
	{
		fstream myfile;

		myfile.open("loginRegisters.txt", ios::out);

		if (myfile.is_open())
		{
			for (clsLoginRegister& LR : vLoginRegister)
				myfile << _convertLoginRegisterObjectToLine(LR) << "\n";
		}
		myfile.close();
	}

	void _AddNew()
	{
		vector <clsLoginRegister> vLoginRegister = _LoadLoginRegistersDataFromFile();

		vLoginRegister.push_back(*this);

		_SaveUsersDataToFile(vLoginRegister);
	}
	
public:
	clsLoginRegister(string Date, string UserName = CurrentUser.UserName,
		string Password = CurrentUser.Password, short Permissions = CurrentUser.Permissions)
	{
		_Date = Date;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	string GetDate()
	{
		return _Date;
	}
	string GetUserName()
	{
		return _UserName;
	}
	string GetPassword()
	{
		return _Password;
	}
	short GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetDate)) string Date;
	__declspec(property(get = GetUserName)) string UserName;
	__declspec(property(get = GetPassword)) string Password;
	__declspec(property(get = GetPermissions)) short Permissions;

	void AddNewLoginRegister()
	{
		_AddNew();
	}

	static vector <clsLoginRegister> _LoadLoginRegistersDataFromFile()
	{
		fstream LoginRegistersFile;
		string line;
		vector <clsLoginRegister> vLoginRegister;

		LoginRegistersFile.open("loginRegisters.txt", ios::in);

		if (LoginRegistersFile.is_open())
		{
			while (getline(LoginRegistersFile, line))
			{
				if (line != "")
					vLoginRegister.push_back(_ConvertLineToLoginRegisterObject(line));
			}
			LoginRegistersFile.close();
		}
		return vLoginRegister;
	}
};

