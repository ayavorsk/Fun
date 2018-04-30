#include <stdio.h>
#include <stdbool.h>

bool f0(int nb)
{
	printf("0: %i\n", nb);
	return (true);
}

bool f1(int nb)
{
	printf("1: %i\n", nb);
	return (false);
}

bool f2(int nb)
{
	printf("2: %i\n", nb);
	return (false);
}

int main()
{
	bool (*func_ptr[3])(int nb) = {f0, f1, f2};
	int option;
	int arg;

	printf("Enter function number you want\n");
	printf("You should not enter other than 0, 1, 2: ");
	scanf("%d",&option);
	printf("Enter int which will become argument of a function: ");
	scanf("%d",&arg);

	if (option >= 0 && option <= 2)
	{
		if ((*func_ptr[option])(arg))
			printf("Function returned true\n");
	}
	return 0;
}
