#include <iostream>

double findProbability(double m, double n)
{
	if (n == 0)
		return 1;
	else if (n > 0)
		return (m / (m + n)) + (n / (m + n)) * (1 - findProbability(m, n - 1));
	else
		return -1;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "Two arguments required: m (number of winning balls) and n (number of non-winning balls)" << std::endl;
		return 1;
	}
	std::cout << findProbability(atoi(argv[1]), atoi(argv[2])) << std::endl;
	return 0;
}
