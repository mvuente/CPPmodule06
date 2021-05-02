
#include "CharLiteral.hpp"

CharLiteral::CharLiteral(char literal) : _literal(literal)
{}

CharLiteral::CharLiteral(const CharLiteral &cpCharLiteral)
{
	*this = cpCharLiteral;
	return ;
}

CharLiteral&	CharLiteral::operator=(const CharLiteral &cpCharLiteral)
{
	if (this != &cpCharLiteral)
		return (*this);
	return (*this);
}

void 			CharLiteral::charPrint() const
{
	std::cout << "char: '" << this->_literal << "'" << std::endl;
}

void 			CharLiteral::intPrint() const
{
	std::cout << "int: " << static_cast<int>(this->_literal) << std::endl;
}

void 			CharLiteral::floatPrint() const
{
	std::cout << "float: " << static_cast<float>(this->_literal) << ".0f" << std::endl;
}

void 			CharLiteral::doublePrint() const
{
	std::cout << "double: " << static_cast<double>(this->_literal) << ".0" << std::endl;
}

CharLiteral::~CharLiteral()
{}
