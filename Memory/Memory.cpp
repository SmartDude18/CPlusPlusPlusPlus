#include <iostream>;

void set(int i);
void display(int i1, int i2);
void forceSet(int& i);
void swap(int& a, int& b);
void swap(int* a, int* b);
void override(int* a, int* b);

int main()
{
	int val1 = 10;
	int val2 = 20;

	display(val1, val2);

	set(val1);

	display(val1, val2);

	int& point = val1;
	//std::cout << point << std::endl;

	point = 30;

	display(val1, val2);

	forceSet(val2);

	display(val1, val2);

	int* pointerPointer;

	pointerPointer = &val1;

	*pointerPointer = 99;

	display(val1, val2);

	swap(val1, val2);

	display(val1, val2);

	swap(&val1, &val2);

	display(val1, val2);

	override(&val1, &val2);

	display(val1, val2);
}

void set(int i)
{
	i = 123;
}

void display(int i1, int i2)
{
	std::cout << "value 1: " << i1 << std::endl;
	std::cout << "value 2: " << i2 << std::endl;
	std::cout << std::endl;
}

void forceSet(int& num)
{
	num = 22;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void override(int* a, int* b)
{
	a = b;
}
