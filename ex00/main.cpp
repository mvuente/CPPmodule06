#include <iostream>
#include <cstdlib>
#include <string>
#include "ILiteral.hpp"
#include "CharLiteral.hpp"
#include "IntLiteral.hpp"
#include "FloatLiteral.hpp"
#include "DoubleLiteral.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "There wrong number of literals is offered." << std::endl;
		return 0;
	}
	ILiteral*	lit;
	std::string literal(argv[1]);
	std::size_t pointFound;
	std::size_t fFound;
	if (literal.length() == 1 && (argv[1][0] < 48 || argv[1][0] > 57))
		lit = new CharLiteral(argv[1][0]);
	else if (literal.length() == 1 && argv[1][0] >= 48 && argv[1][0] <= 57)
		lit = new IntLiteral(static_cast<double>(argv[1][0] - 48));
	else if ((pointFound = literal.find(".")) != std::string::npos)
	{
		if ((fFound = literal.find("f")) != std::string::npos)
			lit = new FloatLiteral(argv[1]);
		else
			lit = new DoubleLiteral(argv[1]);
	}
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		lit = new FloatLiteral(argv[1]);
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
		lit = new DoubleLiteral(argv[1]);
	else
		lit = new IntLiteral(atof(argv[1]));
	lit->charPrint();
	lit->intPrint();
	lit->floatPrint();
	lit->doublePrint();
	delete lit;
	return 0;
}
