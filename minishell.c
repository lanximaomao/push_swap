//check the arguments

#include <stdio.h>

int main(int argc, char** argv)
{
	int i;

	i = 1;
	printf("argc: %d\n", argc);
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	return(0);
}
