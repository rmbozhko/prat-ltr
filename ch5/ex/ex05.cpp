#include <iostream>
#include <array>
#include <string>

int		main(void)
{
	using	namespace	std;

	const	unsigned		months_num = 12;
	const	char			*months_name[months_num]
	{
		"February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November",
		"December", "January"
	};
	array<int, months_num>		bid_arr;
	int				summ;

	summ = 0;
	for (int i = 0; i < months_num; i++)
	{
		cout << "Enter the summ of books sold in ";
		cout << months_name[i] << ": ";
		cin >> bid_arr[i];
		summ += bid_arr[i];
	}
	cout << "Amount of books sold this year is " << summ << "!" << endl;
	return (0);
}
