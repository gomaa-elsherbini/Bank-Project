#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"
using namespace std;




class clsUpdateUserScreen : protected clsScreen
{
private:
	static void _UpdateUser()
	{
		string UserName = "";

		_DrawScreenHeader("\tUpdate User Screen");

		cout << "Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n\nUser Is Not Found, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		clsAddNewUserScreen::Print(User);

		cout << "\nUpdate User Info:\n";
		cout << "_______________\n";

		clsAddNewUserScreen::_ReadUserInfo(User);

		clsUser::enSaveResult saveResult = User.Save();

		switch (saveResult)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\nError Account was not saved because it is empty!\n";
			break;
		case clsUser::svSucceeded:
			cout << "\n\nClient successfully Updated!\n\n";
			clsAddNewUserScreen::Print(User);
			break;
		}
	}
public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate Client Screen");
		_UpdateUser();
	}
};



