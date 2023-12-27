#pragma once
#include "clsScreen.h"
#include <iostream>

using namespace std;

class clsAccessDenied : protected clsScreen
{
public:
	static void accessDenied()
	{
		system("cls");
		_DrawScreenHeader("  Access Denied! Contact your admin");
	}

};

