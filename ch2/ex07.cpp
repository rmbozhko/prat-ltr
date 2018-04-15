#include <iostream>

using		std::endl;
using		std::cout;

void		ft_display_time(int hours, int minutes)
{
	cout << "Time: " << hours << ":" << minutes << endl;
}

int		main(void)
{
	using		std::cin;
	
	int		hours;
	int		minutes;

	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	ft_display_time(hours, minutes);
}
