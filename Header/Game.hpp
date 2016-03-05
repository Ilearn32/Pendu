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

#ifndef DEF_GAME_HPP
#define DEF_GAME_HPP

#include <string>
#include <vector>

namespace Game
{
	class Game
	{
	public:
		Game(std::string const& word, unsigned int counter);
		bool runGame();
	private:
		std::string m_word{};
		unsigned int m_counter{};
		std::vector<bool> m_found{};

		void printWord() const;
		char getChar() const;
		bool updateFounded(char c);
		bool isAllWordFound() const;

		Game(Game const&) = delete;
		Game& operator=(Game const&) = delete;
	};
}

#endif
