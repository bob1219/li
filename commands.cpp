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

void li::command::i(int lineno)
{
	auto line = lines.begin();
	line += lineno + 1;

	string s;
	cout << "insert string: ";
	getline(cin, s);

	lines.insert(line, s);
}

void li::command::es(int lineno)
{
	cout << "fin: @" << endl;
	cout << endl;

	auto line = lines.begin();
	line += lineno;

	for(unsigned int i = lineno + 1 ;; i++)
	{
		cout << "before(" << i << "): " << *line << endl;

		string after;
		cout << "after: ";
		getline(cin, after);
		if(after == "@")
			break;

		*line = after;

		cout << endl;
		line++;
	}
}

void li::command::is(int lineno)
{
	cout << "fin: @" << endl;
	cout << endl;

	auto line = lines.begin();
	line += lineno + 1;

	for(unsigned int i = lineno + 1 ;; i++)
	{
		string s;
		cout << i << ":\t";
		getline(cin, s);
		if(s == "@")
			break;

		lines.insert(line, s);

		cout << endl;
		line++;
	}
}
