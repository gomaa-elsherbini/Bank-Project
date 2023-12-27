#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
using namespace std;





class clsFindUserScreen : protected clsScreen
{
private:
	static void _FindUser()
	{
		char answer;

		string UserName = "";
		cout << "Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Is Not Found, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		cout << "\nClient Info:\n";
		clsAddNewUserScreen::Print(User);
	}

public:
	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("\tFind Client Screen");
		_FindUser();
	}
};



