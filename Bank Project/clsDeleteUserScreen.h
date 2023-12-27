#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteUserScreen :protected clsScreen
{
private:
	static void DeleteUser()
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
		clsAddNewUserScreen::Print(User);

		cout << "Are You Sure You To delete this User y/n? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "User Successfully Deleted! -:)\n";
				clsAddNewUserScreen::Print(User);
			}
			else
				cout << "User is not Deleted! -:(\n";
		}
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete Client Screen");
		DeleteUser();
	}


};


