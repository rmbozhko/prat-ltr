#include <iostream>

int		main(void)
{
	using	namespace std;
	const	auto	ltrs_to_gallons = 3.875F;
	const	auto	kms_to_miles = 62.14F;
	long	double	ltr_km;
	
	cout << "Please, enter litres of patrol per kilometer: ";
	cin >> ltr_km;
	ltr_km /= ltrs_to_gallons;
	cout << "Miles per gallon: " << static_cast<float> (kms_to_miles / ltr_km) << endl;
	
	return (0);
}
