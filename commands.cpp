// Standard Library
#include <string>
#include <iostream>
#include <fstream>
#include <string>

// Header
#include "extern.h"

// using
using namespace std;

void li::command::w(const string &filename)
{
	ofstream ofs(filename);
	if(ofs.fail())
	{
		cerr << "Error: Cannot open file." << endl;
		return;
	}

	for(auto line : lines)
		ofs << line << endl;
}

void li::command::e(int lineno)
{
	auto line = lines.begin();
	line += lineno;

	cout << "before: " << *line << endl;

	string after;
	cout << "after: ";
	getline(cin, after);

	*line = after;
}

void li::command:r(int lineno)
{
	auto line = lines.begin();
	line += lineno;

	lines.erase(line);
}
