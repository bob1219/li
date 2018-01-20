#ifndef _CLASS_H_
#define _CLASS_H_

// Standard Library
#include <string>

namespace li
{
	class exception
	{
	public:
		exception(int _code, const std::string &_mess);
		int			getcode();
		const std::string	&getmess();

	private:
		int		code;
		std::string	mess;
	};
}

#endif
