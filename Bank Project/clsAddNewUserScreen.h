#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"




class clsAddNewUserScreen :protected clsScreen
{
private:
	static short _ReadPermissions(clsUser& User)
	{
		char answer; 
		User.Permissions = 0;

		cout<<("\nDo you want to give full access? y/n");
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
			return -1;

		cout << "\nDo you want to give access to: \n";

		cout<<"\nShow Client List? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pListClients);

		cout<<"\nAdd Client? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pAddNewClient);

		cout<<"\nUpdate Client? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pUpdateClient);

		cout<<"\nDelete Client? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pDeleteClient);

		cout<<"\nFind Client? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pFindClient);

		cout<<"\nTransactions? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pTransactions);

		cout<<"\nManage Users? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pManageUsers);
		
		cout<<"\nShow Login Registers Screen? y/n ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
			User.Permissions += short(clsUser::enPermissions::pLoginRegistersList);
		
		return User.Permissions;
	}

public:
	static void _ReadUserInfo(clsUser& User)
	{
		//User.UserName = User.UserName;

		cout << "\nEnter FirstName? ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Please enter LastName? ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Please enter Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "Please enter Phone? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Please enter Password? ";
		User.Password = clsUtil::EncryptText(clsInputValidate::ReadString());

		User.Permissions = _ReadPermissions(User);
	}

	static void AddNewUser()
	{
		_DrawScreenHeader("\tAdd New User Screen");

		string UserName = "";
		cout << "Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Is Already Exist, Choose Enter another One: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser newUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(newUser);

		clsUser::enSaveResult saveResult;

		saveResult = newUser.Save();

		switch (saveResult)
		{

		case clsUser::svFaildEmptyObject:
			cout << "\n\nUser was not saved because it is empty!\n";
			Print(newUser);
			break;

		case clsUser::svSucceeded:
			cout << "\n\nUser successfully Added!\n";
			break;

		case clsUser::svFaildUserExist:
			cout << "\n\nError User was not saved because it is Already Exists!\n";
			break;
		}

		Print(newUser);
	}

	static 	void Print(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n__________________________________________";
		cout << "\nUserName   : " << User.UserName;
		cout << "\nFirstName  : " << User.FirstName;
		cout << "\nLastName   : " << User.LastName;
		cout << "\nEmail      : " << User.Email;
		cout << "\nPhone      : " << User.Phone;
		cout << "\nPassword   : " << User.Password;
		cout << "\nPermissions: " << User.Permissions;
		cout << "\n__________________________________________\n";
	}
};



