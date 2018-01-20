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

	string before = "";
	if(!lines.empty())
		before = *line;

	cout << "before:\t" << before << endl;

	string after;
	cout << "after:\t";
	getline(cin, after);

	if(lines.empty())
	{
		while(lines.size() < lineno)
			lines.push_back("");
		lines.push_back(after);
	}
	else
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

	bool IsEmpty = lines.empty();
	for(unsigned int i = lineno + 1 ;; i++)
	{
		string before = "";
		if(!IsEmpty)
			before = *line;

		cout << "before(" << i << "):\t" << before << endl;

		string after;
		cout << "after:\t\t";
		getline(cin, after);
		if(after == "@")
			break;

		if(IsEmpty)
		{
			if(lines.empty())
				while(lines.empty() < lineno)
					lines.push_back("");
			lines.push_back(after);
		}
		else
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

	for(unsigned int i = lineno + 2 ;; i++)
	{
		string s;
		cout << i << ":\t";
		getline(cin, s);
		if(s == "@")
			break;

		lines.insert(line, s);

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
			cout << i + 1 << ":\t" << line << endl;
		i++;
	}
}
