/*
 * Copyright (c) 2016 WU Zhenyu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
 * of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following 
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <vector>
#include <fstream>
#include "Random.hpp"
#include "randomWord.hpp"
#include "Console.hpp"

std::string Utilities::randomWordFromFile(std::string const& filename)
{
	std::vector<std::string> words;
	std::ifstream file{ filename };
	if (!file)
		throw std::runtime_error{ Console::accentPrintableStr("File cannot be opened").c_str() };

	std::string actualWord{};
	size_t filesize{};
	while (file >> actualWord)
	{
		words.emplace_back(actualWord);
		++filesize;
	}
	return words[Utilities::randomInt(0u, filesize)];
}
