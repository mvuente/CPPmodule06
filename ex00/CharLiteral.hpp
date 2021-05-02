
#ifndef CHARLITERAL_HPP
#define CHARLITERAL_HPP

#include <iostream>
#include "ILiteral.hpp"

class CharLiteral : public ILiteral
{
private:
	char	_literal;
	CharLiteral(void);
public:
	CharLiteral(char literal);
	CharLiteral(const CharLiteral &cpCharLiteral);
	CharLiteral&	operator=(const CharLiteral &cpCharLiteral);
	virtual ~CharLiteral();
	virtual void charPrint() const;
	virtual void intPrint() const;
	virtual void floatPrint() const;
	virtual void doublePrint() const;
};

#endif
