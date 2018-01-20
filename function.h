#ifndef _FUNCTION_H_
#define _FUNCTION_H_

// Standard Library
#include <iostream>
#include <string>

// Header
#include "constant.h"

namespace li
{
	void CommandLine();
	void CommandProcess(const std::string &command);

	inline void PrintVersion()
	{
		std::cout << "li Version " << VERSION << std::endl;
	}

	namespace command
	{
		void w(const std::string &filename);
		void e(int lineno);
		void r(int lineno);
		void i(int lineno);
		void es(int lineno);
		void is(int lineno);
		void o(const std::string &filename);
		void p(int from, int to);
		void c(int from, int to);
	}
}

#endif
