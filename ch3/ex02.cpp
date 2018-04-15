#include <iostream>

int		main(void)
{
	using	namespace	std;
	float			inches_height;
	float			foots_height;
	float			pounds_weight;
	const	auto		inches_to_meters = 0.0254;
	const	auto		pounds_to_kilo = 2.2;
	const	auto		feet_to_inches = 12.0;

	cout << "Please, enter your height in inches and feet:_________\b\b\b\b\b\b\b\b\b";
	cin >> inches_height >> foots_height;	
	cout << "Please, enter your weight in pounds:______\b\b\b\b\b\b";
	cin >> pounds_weight;
	inches_height += foots_height * feet_to_inches;
	inches_height *= inches_to_meters;
	pounds_weight /= pounds_to_kilo;
	cout << "Your BMI: " << (pounds_weight) / (inches_height * inches_height) << endl; 	
	return (0);
}
