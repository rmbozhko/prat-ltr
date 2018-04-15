#include <iostream>

using	std::cout;
using	std::cin;
using	std::endl;

double		ft_from_yards_to_meters(int yards)
{
	return (yards * 914.5);
}

int		ft_from_farlongs_to_yards(int farlongs)
{
	return (farlongs * 220);
}

int		main(void)
{
	int		farlong;
	
	cout << "Type distance in farlongs to be converted to yards and meters." << endl;
	cin >> farlong;
	cout << "Your distance in yards: " << ft_from_farlongs_to_yards(farlong) << ", your distance in meters: " << ft_from_yards_to_meters(ft_from_farlongs_to_yards(farlong)) << "." << endl;
}
