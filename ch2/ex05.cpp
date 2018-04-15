#include <iostream>

double		ft_to_fahrenheit(double celsius)
{
	return (1.8 * celsius + 32);
}

int		main(void)
{
	using		std::cout;
	using		std::cin;
	using		std::endl;

	double		celsius;

	cout << "Please enter a Celsius value: ";
	cin >> celsius;
	cout << celsius << " degrees Celsius is "
		<< ft_to_fahrenheit(celsius) << " degrees Fahrenheit." << endl; 
	return (0);
}
