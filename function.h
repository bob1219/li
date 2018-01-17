#ifndef _FUNCTION_H_
#define _FUNCTION_H_

// Standard Library
#include <iostream>

// Header
#include "constant.h"

namespace li
{
	void CommandLine();

	inline void PrintVersion()
	{
		std::cout << "li Version " << VERSION << std::endl;
	}
}

#endif
