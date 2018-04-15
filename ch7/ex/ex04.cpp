#include <iostream>

using	std::cout;
using	std::endl;

int		ft_get_factorial(int num)
{
	if (num == 1)
		return (num);
	return (num * ft_get_factorial(num - 1));
}

double		ft_get_probability(int top_bound, size_t chances)
{
	size_t		del;
	int		numerator;
	
	del = ft_get_factorial(chances);
	cout << del << endl;
	numerator = 1;
	for (int i = 0; i < chances; i++)
		numerator *= (top_bound - i);
	return (numerator / double(del));		
}

int		main(void)
{
	cout << "The chance to win is: " << ft_get_probability(57, 6) * ft_get_probability(27, 1) << endl;
	return (0);
}
