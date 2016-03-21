#include <iostream>
#include "randomWord.hpp"
#include "Game.hpp"
#include "Console.hpp"

int main()
{
	std::cout << Console::accentPrintableStr("--------------- Pendu --------------") << std::endl;
	std::cout << Console::accentPrintableStr("Chargement ...");
	const std::string word{ Utilities::randomWordFromFile("Dictionnary.txt") };
	
	std::cout << std::endl;
	Game::Game game{ word, 10 };
	if (game.runGame())
	{
		std::cout << word << std::endl;
		std::cout << Console::accentPrintableStr("Gagné !") << std::endl;
	}
	else
	{
		std::cout << Console::accentPrintableStr("Perdu. Le mot était : ") << word << std::endl;
	}

	return EXIT_SUCCESS;
}
