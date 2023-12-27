#pragma once
#include "clsScreen.h"
#include "clsLoginRegister.h"


class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintLoginRegisterRecordLine(clsLoginRegister LR)
	{
		cout << "\t"
			<< "| " << setw(33) << left << LR.Date
			<< "| " << setw(25) << left << LR.UserName
			<< "| " << setw(20) << left << LR.Password
			<< "| " << setw(20) << left << LR.Permissions;
	}
	static void _PrintLoginRegisterHeader(vector <clsLoginRegister> vLoginRegisters)
	{
		string Title = "\t   Login Registers List Screen";
		string SubTitle = "\t	(" + to_string(vLoginRegisters.size()) + ") Clients";

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t" << "| " << left << setw(33) << "Date/Time";
		cout << "| " << left << setw(25) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	static void ShowLoginRegistersList()
	{
		vector <clsLoginRegister> vLoginRegisters = clsLoginRegister::_LoadLoginRegistersDataFromFile();

		_PrintLoginRegisterHeader(vLoginRegisters);

		if (vLoginRegisters.size() == 0)
			cout << "\t\t\t\tNo Login Registers Available In the System!";
		else

			for (clsLoginRegister &LR : vLoginRegisters)
			{
				_PrintLoginRegisterRecordLine(LR);
				cout << endl;
			}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

public:
	static void ShowLoginRegisterScreen()
	{
		_DrawScreenHeader("\tLogin Register Screen");
		ShowLoginRegistersList();
	}


};

