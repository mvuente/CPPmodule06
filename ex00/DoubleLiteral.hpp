
#ifndef DOUBLELITERAL_HPP
#define DOUBLELITERAL_HPP

#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "ILiteral.hpp"

class DoubleLiteral : public ILiteral
{
private:
	double	_literal;
	int 	_length;
	DoubleLiteral(void);
public:
	DoubleLiteral(char* literal);
	DoubleLiteral(const DoubleLiteral &cpDoubleLiteral);
	DoubleLiteral&	operator=(const DoubleLiteral &cpDoubleLiteral);
	virtual ~DoubleLiteral();
	virtual void charPrint() const;
	virtual void intPrint() const;
	virtual void floatPrint() const;
	virtual void doublePrint() const;
};

#endif