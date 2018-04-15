#include <iostream>

int		main(void)
{
	using	namespace	std;

	short		snum;
	unsigned	uinum;
	long		lnum;

	snum = 80;
	uinum = 42.110;
	lnum = 3000000000;
	cout << snum << endl;
	cout << uinum << endl;
	cout << lnum << endl;
	cout << char(88) << endl;
	cout << (char)88 << endl;
	cout << 88 << endl;
	cout << sizeof lnum << endl;
	cout << sizeof (long) << endl;
	cout << sizeof (float) << endl;
	cout << sizeof (double) << endl;
	cout << sizeof (long double) << endl;
	cout << sizeof (long long) << endl;
	auto	crat = U'/U00002155'; // there is 'U' letter the type of var will be char32_t
				      // if there were 'u' it would be char16_t	
	cout << sizeof crat << endl;
	
	auto	double1 = 2.5;
	auto	double2 = 3.9;
	int	result;

	result = int(double2) + int(double1);
	cout << result << endl;
	result = double2 + double1;
	cout << result << endl;
	
	return (0);
}
