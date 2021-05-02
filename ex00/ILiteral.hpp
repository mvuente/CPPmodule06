
#ifndef ILITERAL_HPP
#define ILITERAL_HPP

class ILiteral
{
public:
	virtual ~ILiteral() {}
	virtual void charPrint() const = 0;
	virtual void intPrint() const = 0;
	virtual void floatPrint() const = 0;
	virtual void doublePrint() const = 0;
};

#endif
