
#include "IntLiteral.hpp"

IntLiteral::IntLiteral(double literal) : _literal(literal)
{}

IntLiteral::IntLiteral(const IntLiteral &cpIntLiteral)
{
	*this = cpIntLiteral;
	return ;
}

IntLiteral&	IntLiteral::operator=(const IntLiteral &cpIntLiteral)
{
	if (this != &cpIntLiteral)
		return (*this);
	return (*this);
}

void 			IntLiteral::charPrint() const
{
	if (this->_literal < -128 || this->_literal > 127 || this->_literal != this->_literal)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<int>(this->_literal)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(this->_literal) << "'" << std::endl;
}

void 			IntLiteral::intPrint() const
{
	if (this->_literal < std::numeric_limits<int>::min() || this->_literal > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(this->_literal) << std::endl;
}

void 			IntLiteral::floatPrint() const
{
	if (this->_literal < std::numeric_limits<int>::min() || this->_literal > std::numeric_limits<int>::max())
		std::cout << "float: " << static_cast<float>(this->_literal) << "f" << std::endl;
	else
	{
		std::cout << std::fixed;
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(this->_literal) << "f" << std::endl;
	}
}

void 			IntLiteral::doublePrint() const
{
	if (this->_literal < std::numeric_limits<int>::min() || this->_literal > std::numeric_limits<int>::max())
		std::cout << "double: " << this->_literal << std::endl;
	else
	{
		std::cout << std::fixed;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(this->_literal) << std::endl;
	}
}

IntLiteral::~IntLiteral()
{}

