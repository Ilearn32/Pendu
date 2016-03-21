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
