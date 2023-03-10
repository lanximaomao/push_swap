#include <stdio.h>

int this_is_recursion_p(int* num)
{

	if (*num < 100)
	{
		printf("hello, ");
		(*num)++;
		printf("my num is %d\n", *num);
		this_is_recursion_p(num);
	}
	printf("what? %d\n", *num);
	return(*num);
}

int this_is_recursion(int num)
{
	if (num < 100)
	{
		num++;
		this_is_recursion(num);
	}
	printf("what?? %d\n", num);
	return(num);
}

int main()
{
	int a;

	a = 0;
	printf("i am returning %d\n", this_is_recursion(a));
	return(0);
}
