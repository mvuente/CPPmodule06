
#include "DoubleLiteral.hpp"

DoubleLiteral::DoubleLiteral(char* literal) : _literal(strtod(literal, NULL))
{
	std::string str(literal);
	this->_length = str.length() - str.find(".");
}

DoubleLiteral::DoubleLiteral(const DoubleLiteral &cpDoubleLiteral)
{
	*this = cpDoubleLiteral;
	return ;
}

DoubleLiteral&	DoubleLiteral::operator=(const DoubleLiteral &cpDoubleLiteral)
{
	if (this != &cpDoubleLiteral)
		this->_length = cpDoubleLiteral._length;
	return (*this);
}

void 			DoubleLiteral::charPrint() const
{
	if (this->_literal < -128 || this->_literal > 127 || this->_literal != this->_literal)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(this->_literal)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->_literal) << "'" << std::endl;
}

void 			DoubleLiteral::intPrint() const
{
	if (this->_literal < std::numeric_limits<int>::min() || this->_literal > std::numeric_limits<int>::max() || this->_literal != this->_literal)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_literal) << std::endl;
}

void 			DoubleLiteral::floatPrint() const
{
	if (this->_literal < -std::numeric_limits<float>::max() || this->_literal > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	else
	{
		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(this->_length - 1) << static_cast<float>(this->_literal) << "f" << std::endl;
	}
}

void 			DoubleLiteral::doublePrint() const
{
	std::cout << std::fixed;
	std::cout << "double: " << std::setprecision(this->_length - 1) << static_cast<double>(this->_literal) << std::endl;
}

DoubleLiteral::~DoubleLiteral()
{}
