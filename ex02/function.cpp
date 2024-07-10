#include "function.hpp"

Base	*generate(void)
{
	int	random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "A" <<std::endl;
			return (new A);
		case 1:
			std::cout << "B" <<std::endl;
			return (new B);
		case 2:
			std::cout << "C" <<std::endl;
			return (new C);
		default:
			return (new A);
	}
}

void	identify(Base *p)
{
	if (A *pt = dynamic_cast<A*>(p))
		std::cout << "actual type : A" <<std::endl;
	else if (B *pt = dynamic_cast<B*>(p))
		std::cout << "actual type : B" <<std::endl;
	else if (C *pt = dynamic_cast<C*>(p))
		std::cout << "actual type : C" <<std::endl;
	else
		std::cout << "actual type : not usual" << std::endl;
}

void	identify(Base &p)
{
	identify(&p);
}