#include "function.hpp"
void	test1()
{
	Base	*t = generate();
	Base	&a = *t;

	identify(t);
	identify(a);
	delete t;
}

void	test2()
{
	Base	i;
	Base	*t = &i;
	Base	&a = *t;

	identify(t);
	identify(a);
}

int main()
{
	srand(time(NULL));
	try
	{
		test1();
		test2();
	}
	catch(...)
	{
		std::cerr << "exception throw" << '\n';
	}

}
