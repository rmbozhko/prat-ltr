#include <iostream>

using	std::cin;
using	std::cout;
using	std::endl;

int		ft_get_factorial(int num)
{
	if (num == 1 || !num)
		return (1);
	return (num * ft_get_factorial(num - 1));
}

void		ft_review_factorial(void)
{
	int		num;

	cout << "Enter a number to find its factorial: ";
	while (cin >> num || !cin.good())
	{
		while (!(cin.good()))
		{
			if (cin.eof())
				return ;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			cout << "enter a number to find its factorial: ";
			cin >> num;
		}
		cout << "And a factorial of " << num << " is " << ft_get_factorial(num) << endl;
		cout << "enter a number to find its factorial: ";
	}
}

int		main(void)
{
	ft_review_factorial();
	return (0);
}
