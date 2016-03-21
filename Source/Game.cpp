#include <iostream>
#include <cctype>
#include "Game.hpp"
#include "Console.hpp"

#undef max
#undef min

Game::Game::Game(std::string const& word, unsigned int counter) : m_word{ word }, m_counter{ counter }, m_found(word.size(), false)
{

}

bool Game::Game::runGame()
{
	while (m_counter > 0)
	{
		std::cout << Console::accentPrintableStr("Vous avez ") << m_counter << Console::accentPrintableStr(" chances.") << std::endl;
		std::cout << Console::accentPrintableStr("Trouvez le mot: ") << std::endl;
		printWord();
		std::cout << Console::accentPrintableStr("Veuillez entrer une lettre : ");
		char c = getChar();
		std::cout << std::endl;
		if (!updateFounded(c)) // the character isn't in the word
		{
			std::cout << Console::accentPrintableStr("\"") << c << 
				Console::accentPrintableStr("\"") << Console::accentPrintableStr(" ne se trouve pas dans le mot ou a déjà été trouvé.") << 
				std::endl;

			--m_counter;
		}
		if (isAllWordFound())
			return true;
	}

	return false;
}

void Game::Game::printWord() const
{
	for (unsigned int i{}; i < m_word.size(); ++i)
	{
		if (m_found[i])
			std::cout << m_word[i];
		else
			std::cout << '*';
	}
	std::cout << std::endl;
}

char Game::Game::getChar() const
{
	char c{};
	while (!(std::cin >> c) || (!std::isalpha(c) && c != '-'))
	{
		std::cerr << Console::accentPrintableStr("Erreur de saisis !") << std::endl;
		if (std::cin.eof())
		{
			throw std::runtime_error{ Console::accentPrintableStr("stdin end of file").c_str() };
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cout << Console::accentPrintableStr("Entrez un caractère (pas de chiffres, de dièses ...) : ");
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	c = std::toupper(c);
	return c;
}

bool Game::Game::updateFounded(char c)
{
	bool changedSomething = false;
	for (unsigned int i{}; i < m_word.size(); ++i)
	{
		if (m_word[i] == c && !m_found[i])
		{
			m_found[i] = true;
			changedSomething = true;
		}
	}
	return changedSomething;
}

bool Game::Game::isAllWordFound() const
{
	for (auto b : m_found)
	{
		if (!b)
			return false;
	}
	return true;
}
