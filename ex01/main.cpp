#include <iostream>

struct Data {
	std::string s1;
	int			n;
	std::string s2;
};

int*	randomInt(char c)
{
	int		tmp = c;
	int		res1 = tmp%48;
	double	res = 1;
	int* 	ptr;

	for (int i = 0; i < res1; ++i)
	{
		if (res < INT_MAX / res1)
			res = res * res1;
		else
		{
			int resfin = static_cast<int>(res);
			std::cout << "Random int is " << resfin << std::endl;
			return (ptr = &resfin);
		}
	}
	int resfin = static_cast<int>(res);
	std::cout << "Random int is " << resfin << std::endl;
	return (ptr = &resfin);
}

char 	randomChar(int i)
{
	int a = 2;
	int* ptr = &a;
	size_t rand = (size_t)ptr;
	if (i > 1)
		rand = rand/i;
	else if (i == 1)
		rand = rand * rand;
	int tmp = static_cast<int>(rand%3);
	if (tmp == 0)
		return ('0' +  rand%10);
	else if (tmp == 1)
		return ('A' + rand%26);
	else
		return ('a' + rand%26);
}

void*	serialize(void)
{
	void* ptr;
	char* consq = new char[20];

	for (int i = 0; i < 8; ++i)
		consq[i] = randomChar(i);
	ptr = reinterpret_cast<void*>(randomInt(consq[7]));
	consq[8] = *reinterpret_cast<char*>(ptr);
	consq[9] = *(reinterpret_cast<char*>(ptr) + 1);
	consq[10] = *(reinterpret_cast<char*>(ptr) + 2);
	consq[11] = *(reinterpret_cast<char*>(ptr) + 3);
	for (int i = 12; i < 20; ++i)
		consq[i] = randomChar(i);
	ptr = reinterpret_cast<void*>(consq);
	delete[] consq;
	return ptr;
}

Data*	deserialize(void* raw)
{
	Data*	data = new Data;
	std::cout << sizeof(*data);
	char*	ptr = reinterpret_cast<char*>(raw);
	char*	ptr1 = new char[9];
	void*	ptr2;
	int*	tmp;

	for (int i = 0; i < 8; ++i)
		ptr1[i] = ptr[i];
	data->s1 = std::string(ptr1);
	for (int i = 0; i < 4; ++i)
		ptr1[i] = ptr[8 + i];
	ptr2 = reinterpret_cast<void*>(ptr1);
	tmp = reinterpret_cast<int*>(ptr2);
	data->n = *tmp;
	for (int i = 0; i < 8; ++i)
		ptr1[i] = ptr[12 + i];
	data->s2 = std::string(ptr1);
	delete[] ptr1;
	return (data);
}

int		main() {
	void	*res = serialize();
	Data	*data;
	char 	*tmp = reinterpret_cast<char*>(res);
	for (int i = 0; i < 20; ++i)
		std::cout << tmp[i] << std::endl;
	data = deserialize(res);
	std::cout << "String1 is " << data->s1 << std::endl;
	std::cout << "Int is " << data->n << std::endl;
	std::cout << "String2 is " << data->s2 << std::endl;
	std::cout << sizeof(*data);
	delete data;
	return 0;
}
