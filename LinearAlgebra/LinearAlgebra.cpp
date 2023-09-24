// LinearAlgebra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;
//#include"../libs/"

#pragma region Define FUnc Pointers to ConsoleLib.dll 

bool (*Init) (HANDLE);

void (*Print) (const string&);

void (*PrintColorMessage) (const string&, WORD, WORD);

HANDLE* const (*GetHandle)(void);

string(*Input) (const string&, WORD, WORD, bool (*) (const string&));

char (*InputKey) (const string&, WORD, WORD);

#pragma endregion

#pragma region Colors

WORD white = FOREGROUND_RED | FOREGROUND_GREEN |
FOREGROUND_BLUE | FOREGROUND_INTENSITY;

#pragma endregion


int main()
{
#pragma region Load Libraries

	auto ConsoleLib = LoadLibrary(L"../libs/ConsoleLib.dll");

	Init = (bool (*) (HANDLE))GetProcAddress(ConsoleLib, "Init");

	Print = (void (*) (const string&))GetProcAddress(ConsoleLib, "Print");

	PrintColorMessage = (decltype(PrintColorMessage))GetProcAddress(ConsoleLib, "PrintColorMsg");

	GetHandle = (decltype(GetHandle))GetProcAddress(ConsoleLib, "GetHandle");

	Input = (decltype(Input))GetProcAddress(ConsoleLib, "Input");

	InputKey = (decltype(InputKey))GetProcAddress(ConsoleLib, "InputKey");
		
#pragma endregion

#pragma region Main
	bool consoleInit;

	if (ConsoleLib != NULL)
	    consoleInit = Init(GetStdHandle(STD_OUTPUT_HANDLE));
	else
		cout << "Fail To Load ConsoleLib.dll" << endl;
	
	for (; consoleInit ;)
	{
		system("CLS");

		PrintColorMessage("Linear Algebra Calculation Suit... All rigts reserved.", 
			FOREGROUND_RED | FOREGROUND_GREEN,  white);

		break;
	}
#pragma endregion

	if (!consoleInit)
		cout << "Fail to initialize ConsoleLib!!!" << endl;

	system("Pause");

#pragma region Free Libraries
		FreeLibrary(ConsoleLib);
#pragma endregion
		return 0;
}


