#include <iostream>

using	std::cout;
using	std::endl;
using	std::cin;

void		ft_show_array(double *begin, const double *end)
{
	for (double *i = begin; i != end; i++)
		cout << "Element\'s #" << (i - begin) + 1 << " value: " << *i << endl;
}

void		ft_revalue(double factor, double *begin, const double *end)
{
	for (double *temp = begin; temp != end; temp++)
		*temp *= factor;
}

double		*ft_fill_array(double *begin, const double *end)
{
	double		*i;

	for (i = begin; i != end; i++)
	{
		cout << "Please enter next value: ";
		if (!(cin >> *i))
		{
			if (cin.eof() || cin.bad())
				break ;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			break ;
		}
		cout << "Element\'s #" << (i - begin) + 1 << " value: " << *i << endl;
	}
	return (i);
}

int		main(void)
{
	const size_t	exp_len = 10;
	double		arr[exp_len];
	double		*len;

	len = ft_fill_array(arr, arr + 10);
	cout << "The address of last array\'s element: " << len << endl;
	ft_show_array(arr, len);
	ft_revalue(7.0, arr, len);
	ft_show_array(arr, len);
	return (0);
}
