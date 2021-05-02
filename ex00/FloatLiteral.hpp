
#ifndef FLOATLITERAL_HPP
#define FLOATLITERAL_HPP

#include <iostream>
#include <cctype>
#include <limits>
#include <iomanip>
#include "ILiteral.hpp"

class FloatLiteral : public ILiteral
{
private:
	double	_literal;
	int 	_length;
	FloatLiteral(void);
public:
	FloatLiteral(char* literal);
	FloatLiteral(const FloatLiteral &cpFloatLiteral);
	FloatLiteral&	operator=(const FloatLiteral &cpFloatLiteral);
	virtual ~FloatLiteral();
	virtual void charPrint() const;
	virtual void intPrint() const;
	virtual void floatPrint() const;
	virtual void doublePrint() const;
};

#endif
