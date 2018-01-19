// Standard Library
#include <string>
#include <regex>

// Header
#include "extern.h"
#include "function.h"
#include "constant.h"

// using
using namespace std;

void li::CommandProcess(const string &command)
{
	if(command == "f")
		cout << filename << endl;
	else if(command == "w")
	{
		if(filename == "")
			cerr << "Error: Please tell me output filename" << endl;
		else
			command::w(filename);
	}
	else if(regex_match(command, regex("w .+")))
	{
		char format[FORMAT_MAX], _filename[FILENAME_MAX];
		sprintf(format, "w %%%us", (sizeof(_filename) / sizeof(char)));
		sscanf(command, format, _filename);

		command::w(_filename);
	}
	else if(regex_match(command, regex("e \\d+")))
	{
		int lineno;
		sscanf(command, "e %d", &lineno);

		command::e(--lineno);
	}
	else if(regex_match(command, regex("r \\d+")))
	{
		int lineno;
		sscanf(command, "r %d", &lineno);

		command::r(--lineno);
	}
	else if(regex_match(command, regex("i \\d+")))
	{
		int lineno;
		sscanf(command, "i %d", &lineno);

		command::i(--lineno);
	}
	else if(regex_match(command, regex("es \\d+")))
	{
		int lineno;
		sscanf(command, "es %d", &lineno);

		command::es(--lineno);
	}
	else if(regex_match(command, regex("is \\d+")))
	{
		int lineno;
		sscanf(command, "is %d", &lineno);

		command::is(--lineno);
	}
	else if(command == "o")
	{
		if(filename == "")
			cerr << "Error: Please tell me open filename" << endl;
		else
			command::o(filename);
	}
	else if(regex_match(command, regex("o .+")))
	{
		char format[FORMAT_MAX], _filename[FILENAME_MAX];
		sprintf(format, "o %%%us", (sizeof(_filename) / sizeof(char)));
		sscanf(command, format, _filename);

		command::o(_filename);
	}
	else if(command == "p")
		command::p(0, lines.size() - 1);
	else if(regex_match(command, regex("p \\d+")))
	{
		int lineno;
		sscanf(command, "p %d", &lineno);
		lineno--;

		command::p(lineno, lineno);
	}
	else if(regex_match(command, regex("p \\d+ \\d+")))
	{
		int from, to;
		sscanf(command, "p %d %d", &from, &to);

		command::p(--from, --to);
	}
	else if(command == "q")
		exit(EXIT_SUCCESS);
	else
		throw li::exception(0x2, "unknown command");

	return;
}
