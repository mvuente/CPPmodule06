
#ifndef INTLITERAL_HPP
#define INTLITERAL_HPP

#include <iostream>
#include <cctype>
#include <limits>
#include <iomanip>
#include "ILiteral.hpp"

class IntLiteral : public ILiteral
{
private:
	double	_literal;
	IntLiteral(void);
public:
	IntLiteral(double literal);
	IntLiteral(const IntLiteral &cpIntLiteral);
	IntLiteral&	operator=(const IntLiteral &cpIntLiteral);
	virtual ~IntLiteral();
	virtual void charPrint() const;
	virtual void intPrint() const;
	virtual void floatPrint() const;
	virtual void doublePrint() const;
};

#endif
