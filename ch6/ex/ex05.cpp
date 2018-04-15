#include <iostream>

int		main(void)
{
	using	namespace	std;

	double		tax;
	double		income;
	
	cout << "Enter the income amount: ";
	while (cin >> income && income > 0)
	{
		tax = 0.0;
		if (income > 5000)
		{
			income -= 5000;
		}
		if (income > 10000)
		{
			tax += 10000 * 0.1;
			income -= 10000;
		}
		if (income > 20000)
		{
			tax += 20000 * 0.15;
			income -= 20000;
		}
		if (income > 0)
		{
			tax += income * 0.2;
			income -= 35000;
		}
		cout << "Total taxation: " << tax << endl;
		cout << "Enter the income amount: ";
	}
	return (0);
}
