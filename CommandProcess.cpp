// Standard Library
#include <string>
#include <regex>

// Header
#include "extern.h"
#include "function.h"
#include "constant.h"
#include "class.h"

// using
using namespace std;

void li::CommandProcess(const string &command)
{
	if(command == "f") // Print current filename
	{
		if(filename != "")
			cout << filename << endl;
	}
	else if(command == "w") // Write to current file
	{
		if(filename == "")
			cerr << "Error: Please tell me output filename" << endl;
		else
			command::w(filename);
	}
	else if(regex_match(command, regex("w .+"))) // Write to a file
	{
		char format[FORMAT_MAX], _filename[FILENAME_MAX];
		sprintf(format, "w %%%us", (sizeof(_filename) / sizeof(char)));
		sscanf(command.c_str(), format, _filename);

		command::w(_filename);
	}
	else if(regex_match(command, regex("e \\d+"))) // Edit a line
	{
		int lineno;
		sscanf(command.c_str(), "e %d", &lineno);

		command::e(--lineno);
	}
	else if(regex_match(command, regex("r \\d+"))) // Remove a line
	{
		int lineno;
		sscanf(command.c_str(), "r %d", &lineno);

		command::r(--lineno);
	}
	else if(regex_match(command, regex("i \\d+"))) // Insert a line
	{
		int lineno;
		sscanf(command.c_str(), "i %d", &lineno);

		command::i(--lineno);
	}
	else if(regex_match(command, regex("es \\d+"))) // Edit lines
	{
		int lineno;
		sscanf(command.c_str(), "es %d", &lineno);

		command::es(--lineno);
	}
	else if(regex_match(command, regex("is \\d+"))) // Insert lines
	{
		int lineno;
		sscanf(command.c_str(), "is %d", &lineno);

		command::is(--lineno);
	}
	else if(command == "o") // Open current file again
	{
		if(filename == "")
			cerr << "Error: Please tell me open filename" << endl;
		else
			command::o(filename);
	}
	else if(regex_match(command, regex("o .+"))) // Open a file
	{
		char format[FORMAT_MAX], _filename[FILENAME_MAX];
		sprintf(format, "o %%%us", (sizeof(_filename) / sizeof(char)));
		sscanf(command.c_str(), format, _filename);

		command::o(_filename);
	}
	else if(command == "p") // Print all lines
		command::p(0, lines.size() - 1);
	else if(regex_match(command, regex("p \\d+"))) // Print a line
	{
		int lineno;
		sscanf(command.c_str(), "p %d", &lineno);
		lineno--;

		command::p(lineno, lineno);
	}
	else if(regex_match(command, regex("p \\d+ \\d+"))) // Print lines
	{
		int from, to;
		sscanf(command.c_str(), "p %d %d", &from, &to);

		command::p(--from, --to);
	}
	else if(command == "q") // quit
		exit(EXIT_SUCCESS);
	else
		throw li::exception(0x2, "unknown command");

	return;
}
