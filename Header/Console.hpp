#ifndef DEF_CONSOLE_HPP
#define DEF_CONSOLE_HPP

#include <string>
#include <memory>
#if defined _WIN32 || defined WIN32 || defined __WIN32__ 
#	include <Windows.h>
#endif

namespace Console
{
	inline std::string accentPrintableStr(std::string const& text)
	{
	#if defined _WIN32 || defined WIN32 || defined __WIN32__ 
		std::unique_ptr<char[]> buf{ new char[text.size() + 1]{} };
		CharToOemBuffA(text.c_str(), buf.get(), text.size());
		std::string tmp{ buf.get() };
		return tmp;
	#else
		return text;
	#endif
	}
}


#endif
