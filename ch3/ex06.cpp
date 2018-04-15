#include <iostream>

int		main(void)
{
	using	namespace std;
	long	double	kms;
	long	double	liters;
	
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Please, enter number of driven kilometers: ";
	cin >> kms;
	cout << "Please, enter liters of patrol used: ";
	cin >> liters;
	cout << "Due to your data, you need " << static_cast<long double>(kms / liters) << " liters of patrol per kilometer." << endl;
	return (0);
}
