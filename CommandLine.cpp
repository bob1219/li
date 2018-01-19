// Standard Library
#include <iostream>
#include <string>
#include <regex>
#include <cstdio>
#include <cstdlib>

// Header
#include "function.h"
#include "extern.h"
#include "constant.h"
#include "class.h"

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
