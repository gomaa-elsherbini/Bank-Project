#pragma once
#include "clsScreen.h"
#include "clsUser.h"




class clsListUsersScreen:protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << "\t"
			<< "| " << setw(15) << left << User.UserName
			<< "| " << setw(15) << left << User.FullName()
			<< "| " << setw(15) << left << User.Phone
			<< "| " << setw(15) << left << User.Email
			<< "| " << setw(20) << left << User.Password
			<< "| " << setw(12) << left << User.Permissions;
	}
	static void _PrintUsersHeader(vector <clsUser> vUsers)
	{
		string Title = "\t   Users List Screen";
		string SubTitle = "\t	(" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;

		cout << "\t" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(15) << "Full Name";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(15) << "Email";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;
	}
public:
	static void ShowUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		_PrintUsersHeader(vUsers);

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "__________________________________________________\n" << endl;
	}
};

