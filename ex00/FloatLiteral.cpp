
#include "FloatLiteral.hpp"

FloatLiteral::FloatLiteral(char* literal) : _literal(atof(literal))
{
	std::string str(literal);
	this->_length = str.length() - str.find(".");
}

FloatLiteral::FloatLiteral(const FloatLiteral &cpFloatLiteral)
{
	*this = cpFloatLiteral;
	return ;
}

FloatLiteral&	FloatLiteral::operator=(const FloatLiteral &cpFloatLiteral)
{
	if (this != &cpFloatLiteral)
		this->_length = cpFloatLiteral._length;
	return (*this);
}

void 			FloatLiteral::charPrint() const
{
	if (this->_literal < -128 || this->_literal > 127 || this->_literal != this->_literal)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(this->_literal)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->_literal) << "'" << std::endl;
}

void 			FloatLiteral::intPrint() const
{
	if (this->_literal < std::numeric_limits<int>::min() || this->_literal > std::numeric_limits<int>::max() || this->_literal != this->_literal)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_literal) << std::endl;
}

void 			FloatLiteral::floatPrint() const
{
	std::cout << std::fixed;
	std::cout << "float: " << std::setprecision(this->_length - 2) << static_cast<float>(this->_literal) << "f" << std::endl;
}

void 			FloatLiteral::doublePrint() const
{
	std::cout << "double: " << this->_literal << std::endl;
}

FloatLiteral::~FloatLiteral()
{}

