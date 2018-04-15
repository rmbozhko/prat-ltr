#include <iostream>

int		main(void)
{
	using namespace std;
	long double	worlds_population;
	long double		usa_population;
	long double			part;

	cout.setf(ios_base::fixed, ios_base::floatfield);	
	cout << "Enter the world\'s population: ";
	cin >> worlds_population;
	cout << "Enter the population of the US: ";
	cin >> usa_population;
	cout << "The population of the US is " <<
	static_cast<long double>((usa_population * 100) / worlds_population)
	<< "\% of the world population." << endl;
	return (0);
}
