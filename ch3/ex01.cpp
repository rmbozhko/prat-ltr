#include <iostream>

double		ft_get_foots(double num)
{
	return (num * 12);
}

int		main(void)
{
	using	namespace	std;
	double			height_in_inchs;
	double			height_in_feet;
	cout << "Please, enter your height in inches and feet:_________\b\b\b\b\b\b\b\b\b";
	cin >> height_in_inchs >> height_in_feet;
	const	double			result = ft_get_foots(height_in_inchs);
	cout << "Your height in foots: " << result << endl;
	return (0);
}
