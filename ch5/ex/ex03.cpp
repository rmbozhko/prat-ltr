#include <iostream>

int		main(void)
{
	using	std::cout;
	using	std::cin;
	using	std::endl;

	int		num;
	int		summ;
	
	summ = 0;
	do
	{
		cout << "Enter number please: ";
		cin >> num;
		summ += num;
	} while (num != 0);
	cout << "Sum of entered numbers is: " << summ << endl;
	return (0);
}
