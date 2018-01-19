// Standard Library
#include <string>
#include <iostream>
#include <fstream>

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
