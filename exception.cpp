// Standard Library
#include <string>

// Header
#include "class.h"

// using
using namespace std;

li::exception::exception(int _code, const string &_mess)
	:code(_code), mess(_mess)
{}

int li::exception::getcode()
{
	return code;
}

const string &li::exception::getmess()
{
	return mess;
}
