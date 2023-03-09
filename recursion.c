
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int this_is_recursion(int *num)
{
	if (*num < 100)
	{
		(*num)++;
		this_is_recursion(num);
		printf("hello, my num is %d\n", *num);
		this_is_recursion(&(*num)-1);

	}
	printf("I am having a lot of fun! %d\n", *num);

	return(*num);
}

int main()
{
	int a = 0;
	printf("my return value is %d\n", this_is_recursion(&a));
	return(0);
}
