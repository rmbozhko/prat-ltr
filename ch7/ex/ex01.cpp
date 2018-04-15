#include <iostream>

using	std::cout;
using	std::endl;
using	std::cin;

inline double		ft_calc_harmonic(int x, int y)
{
	return (double(2.0 * x * y / (x + y)));
}

void		ft_find_harmonic(void)
{
	int		x;
	int		y;

	cout << "Enter 2 numbers and find the harmonic of both: ";
	while (cin >> x >> y || !cin.good())
	{
		if (!cin.good())
		{
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			cout << "Enter 2 numbers and find the harmonic of both: ";
			continue ;
		}
		if (!x || !y)
			break ;
		cout << "Harmonic of passed numbers: " << ft_calc_harmonic(x, y) << endl;	
		cout << "Enter 2 numbers and find the harmonic of both: ";
	}
}

int		main(void)
{
	ft_find_harmonic();
	return (0);
}
