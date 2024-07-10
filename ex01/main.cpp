#include "main.hpp"

int main()
{
	int			c;
	Data 		a;
	Data		*b;
	uintptr_t	test;

	std::cout << &a << std::endl;
	test = Serializer::serialize(&a);
	b = Serializer::deserialize(test);
	std::cout << std::hex << test << '\n' << b << std::endl;
}
