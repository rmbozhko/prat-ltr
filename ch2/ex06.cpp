#include <iostream>

double		ft_to_astro_units(double l_years)
{
	return (l_years * 63240);
}

int		main(void)
{
	using		std::cin;
	using		std::cout;
	using		std::endl;
	
	double		light_years;

	cout << "Enter the number of light years: ";
	cin >> light_years;
	cout << light_years << " light years = " << ft_to_astro_units(light_years)
		<< " astronomical units." << endl;
	return (0);
}
