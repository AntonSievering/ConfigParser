#include "ConfigParser.h"
#include "Parser.h"
#include <iostream>

int main()
{
	parser::Parser parser = parser::Parser("");

	std::cout << parser.startsWith('a') << std::endl;
	std::cout << parser.startsWith("Dat") << std::endl;
	std::cout << parser.endsWith('a') << std::endl;
	std::cout << parser.endsWith("Test") << std::endl;

	return 0;
}