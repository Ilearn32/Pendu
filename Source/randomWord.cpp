#include <vector>
#include <fstream>
#include "Random.hpp"
#include "randomWord.hpp"
#include "Console.hpp"

std::string Utilities::randomWordFromFile(std::string const& filename)
{
	std::vector<std::string> words;
	words.reserve(350'000);

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
