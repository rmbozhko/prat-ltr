#include <iostream>
#include <array>
#include <string>

const	unsigned		months_num = 12;
const	unsigned		years_amount = 3;

int		ft_yearly_sold(void)
{
	using	namespace	std;
	const	char			*months_name[months_num]
	{
		"February", "March", "April", "May", "June", 
		"July", "August", "September", "October", "November",
		"December", "January"
	};
	array<int, months_num>		year_amount;
	int				summ;

	summ = 0;
	for (int i = 0; i < months_num; i++)
	{
		cout << "Enter the summ of books sold in ";
		cout << months_name[i] << ": ";
		cin >> year_amount[i];
		summ += year_amount[i];
	}
	return (summ);
}

int		main(void)
{
	using	namespace	std;
	int			summ;
	array<int, years_amount>		amount_pro_year;
			
	summ = 0;
	for (int i = 0; i < years_amount; i++)
	{
		cout << "Enter num of books sold during year #" << i + 1;
		cout << ":\n";
		amount_pro_year[i] = ft_yearly_sold();
		summ += amount_pro_year[i];
		cout << "And result of books sold during year #" << i + 1;
		cout << " is " << amount_pro_year[i] << endl;
	}
	cout << "Total amount of sold boks during last " << years_amount;
	cout << " years is " << summ << endl;
	return (0);
}
