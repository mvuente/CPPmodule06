#include <iostream>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int		randomInt(void)
{
	int 	a = 2;
	int* 	ptr = &a;
	size_t 	rand = (size_t)ptr;
	return static_cast<int>(rand%3);
}

void	identify_from_pointer(Base * p)
{
	A*		test_a;
	B*		test_b;
	C*		test_c;

	if ((test_a = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((test_b = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((test_c = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
}

void 	identify_from_reference(Base & p)
{
	try {A & test_a = dynamic_cast<A &>(p);
			std::cout << "A" << std::endl;
			test_a.~A();
		}
	catch (std::exception& e) {
		try {
			B & test_b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			test_b.~B();
		}
		catch (std::exception &e) {
			try {
				C & test_c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				test_c.~C();
			}
			catch (std::exception &e) {
				std::cout << "wrong" << std::endl;
			}
		}
	}
}

Base*	generate(void)
{
	Base* 	smth;
	int 	rand = randomInt();

	if (rand == 0)
	{
		std::cout << "A is initialised." << std::endl;
		return smth = new A;
	}
	else if (rand == 1)
	{
		std::cout << "B is initialised." << std::endl;
		return smth = new B;
	}
	else
	{
		std::cout << "C is initialised." << std::endl;
		return smth = new C;
	}
}

int		main()
{
	Base*	smth;

	smth = generate();
	std::cout << "identified from pointer : ";
	identify_from_pointer(smth);
	std::cout << "identified from reference : ";
	identify_from_reference(*smth);
	std::cout << "Bye-bye, World!" << std::endl;
	delete smth;
	return 0;
}
