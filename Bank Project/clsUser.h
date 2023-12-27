#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;




class clsUser: public clsPerson
{
private:
	enum enMode{EmptyMode, UpdateMode, AddNewMode};

	enMode _Mode;
	
	string _UserName;
	string _Password;
	short  _Permissions;

	bool _markToDelete = false;

	static clsUser _ConvertLineToUserObject(string line, string separator = "#//#")
	{//  Admin#//#Saad#//#Ali#//#aLi@gmial.com#//#012546578866#//#1234#//#-1

		vector <string>vUser = clsString::splitString(line, separator);

		return clsUser(UpdateMode, vUser[1], vUser[2],  vUser[3], vUser[4], vUser[0], vUser[5], stoi(vUser[6]));
	}
	static string _convertUserObjectToLine(clsUser User, string separator = "#//#")
	{
		string line = "";

		line += User._UserName;
		line += separator + User.FirstName;
		line += separator + User.LastName;
		line += separator + User.Email;
		line += separator + User.Phone;
		line += separator + User._Password;
		line += separator + to_string(User._Permissions);

		return line;
	}
	static vector <clsUser> _LoadUsersDataFromFile()
	{
		fstream usersfile;
		string line;
		vector <clsUser> vUsers;

		usersfile.open("users.txt", ios::in);

		if (usersfile.is_open())
		{
			while (getline(usersfile, line))
			{
				if (line != "")
					vUsers.push_back(_ConvertLineToUserObject(line));
			}
			usersfile.close();
		}
		return vUsers;
	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream myfile;
	
		myfile.open("users.txt", ios::out);
	
		if (myfile.is_open())
		{
			for (clsUser& u : vUsers)
			{
				if (!u._markToDelete)
					myfile << _convertUserObjectToLine(u) << "\n";
			}
		}
		myfile.close();
	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode,"", "","", "","","", 0);
	}

	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U._Password == _Password)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		vUsers.push_back(*this);

		_SaveUsersDataToFile(vUsers);
	}

public:
	enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pUpdateClient = 4,
		pDeleteClient = 8, pFindClient = 16, pTransactions = 32,
		pManageUsers = 64, pLoginRegistersList =128
	};

	clsUser
	(enMode Mode,string FirstName, string LastName,string Email, string Phone,
		string UserName, string Password, short Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkToDelete()
	{
		return _markToDelete;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;
	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}
	short GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	static clsUser Find(string UserName)
	{
		vector <clsUser> vClsUsers = _LoadUsersDataFromFile();
	
		for (clsUser& User : vClsUsers)
		{
			if (User.UserName == UserName)
				return User;
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password)
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		
		Password = clsUtil::EncryptText(Password);

		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName && User._Password == Password)
				return User;
		}
		return _GetEmptyUserObject();
	}
	
	static bool IsUserExist(string UserName)
	{
		return !clsUser::Find(UserName).IsEmpty();
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded, svFaildUserExist };
	
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
				return enSaveResult::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewMode:
			if (clsUser::IsUserExist(_UserName))
				return enSaveResult::svFaildUserExist;
			else
			{
				_AddNew();

				enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
		}
	}

	static bool IsUserExist(string Name, string Password)
	{
		return !clsUser::Find(Name, Password).IsEmpty();
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
	
		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._markToDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode,"", "", "", "", UserName,"", 0);
	}

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	bool ValidateUser(enPermissions AccessTo)
	{
		return AccessTo & Permissions;
	}
};

