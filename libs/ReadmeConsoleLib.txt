To use his lib.
1) Put ConsoleLib.dll into some folder in your solution where it will be used.
2) Using runtime Loading to load DLL into your programm.

auto ConsoleLib = LoadLibrary(L"../x64/Debug/ConsoleLib.dll");

3) Create Pointers to functions of the DLL or use typedef. Just select what is more suitable for you.

bool (*Init) (HANDLE);

void (*Print) (const string&);

void (*PrintColorMessage) (const string&, WORD, WORD);

HANDLE* const (*GetHandle)(void);

string(*Input) (const string&, WORD, WORD, bool (*) (const string&));

char (*InputKey) (const string&, WORD, WORD);

4) Get functions from the DLL:

Init = (bool (*) (HANDLE))GetProcAddress(ConsoleLib, "Init");

Print = (void (*) (const string&))GetProcAddress(ConsoleLib, "Print");

PrintColorMessage = (decltype(PrintColorMessage))GetProcAddress(ConsoleLib, "PrintColorMsg");

GetHandle = (decltype(GetHandle))GetProcAddress(ConsoleLib, "GetHandle");

Input = (decltype(Input))GetProcAddress(ConsoleLib, "Input");

InputKey = (decltype(InputKey))GetProcAddress(ConsoleLib, "InputKey");

5) Don't forget to clear library!.

FreeLibrary(ConsoleLib);