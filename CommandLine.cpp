// Standard Library
#include <iostream>
#include <string>

// Header
#include "function.h"

// using
using namespace std;

void li::CommandLine()
{
	while(true)
	{
		string command;
		cout << ">";
		getline(cin, command);

		CommandProcess(command);

		cout << endl;
	}
}
