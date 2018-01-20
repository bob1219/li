// Standard Library
#include <iostream>
#include <fstream>
#include <string>

// Header
#include "extern.h"
#include "function.h"

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
	for(unsigned int i = 1 ; i <= lineno ; i++)
		line++;

	cout << "before: " << *line << endl;

	string after;
	cout << "after: ";
	getline(cin, after);

	*line = after;
}

void li::command::r(int lineno)
{
	auto line = lines.begin();
	for(unsigned int i = 1 ; i <= lineno ; i++)
		line++;

	lines.erase(line);
}

void li::command::i(int lineno)
{
	auto line = lines.begin();
	for(unsigned int i = 1 ; i <= lineno ; i++)
		line++;
	line++;

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
	for(unsigned int i = 1 ; i <= lineno ; i++)
		line++;

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
	for(unsigned int i = 1 ; i <= lineno ; i++)
		line++;
	line++;

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

void li::command::o(const string &filename)
{
	ifstream ifs(filename);
	if(ifs.fail())
	{
		cerr << "Error: Cannot open file." << endl;
		return;
	}

	lines.clear();

	string line;
	while(getline(ifs, line))
		lines.push_back(line);
}

void li::command::p(int from, int to)
{
	int i = 0;
	for(auto line : lines)
	{
		if(i >= from && i <= to)
			cout << i << ":\t" << line << endl;
		i++;
	}
}
