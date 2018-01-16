// Standard Library
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstdlib>
#include <list>
#include <exception>

// Header
#include "class.h"
#include "function.h"

// using
using namespace std;
using namespace li;

// Gloval variable
list<string> lines;

int main(int argc, char **argv)
{
	try
	{
		string filename;
		if(argc == 1)
		{
			cout << "open file?(Y/N)" << endl;
			while(true)
			{
				cout << ">";
				char YorN = getchar();
				if(YorN == EOF)
					continue;

				YorN = static_cast<char>(tolower(static_cast<int>(YorN)));
				switch(YorN)
				{
				case 'y':
					cout << "filename: ";
					getline(cin, filename);
					break;

				case 'n':
					filename = "";
					break;

				default:
					continue;
				}

				break;
			}
		}
		else if(argc == 2)
			filename = argv[1];
		else
		{
			cerr << "Usage: " << argv[0] << " <filename>" << endl;
			return EXIT_FAILURE;
		}

		if(filename != "")
		{
			ifstream ifs(filename);
			if(ifs.fail())
				throw li::exception(0x1, "Cannot open file");

			string line;
			while(getline(ifs, line))
				lines.push_back(line);
		}

		PrintVersion();
		cout << endl;
		CommandLine();
	}
	catch(li::exception &e)
	{
		cerr << "error code:\t" << e.getcode() << endl;
		cerr << "error message:\t" << e.getmess() << endl;
		return EXIT_FAILURE;
	}
	catch(std::exception &e)
	{
		cerr << "error message: " << e.what() << endl;
		return EXIT_FAILURE;
	}
	catch(...)
	{
		cerr << "error." << endl;
		return EXIT_FAILURE;
	}
}
