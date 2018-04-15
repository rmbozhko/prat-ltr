#include <iostream>

using	std::cout;
using	std::endl;
using	std::cin;

void		ft_show_array(const double *arr, const size_t len)
{
	for (size_t i = 0; i < len; i++)
		cout << "Element\'s #" << i + 1<< " value: " << arr[i] << endl;
}

void		ft_reverse_array(double *arr, const size_t len)
{
	double		temp;
	size_t		i;
	size_t		j;

	i = 0;
	j = len - 1;
	cout << j << endl;
	if (len > 1)
	{
		while (i < j)//len - 1)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
}

size_t		ft_fill_array(double *arr, const size_t len)
{
	size_t		i;

	for (i = 0; i < len; i++)
	{
		cout << "Please enter next value: ";
		if (!(cin >> arr[i]))
		{
			if (cin.eof() || cin.bad())
				break ;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			break ;
		}
		cout << "Element\'s #" << i + 1 << " value: " << arr[i] << endl;
	}
	return (i);
}

int		main(void)
{
	const size_t	exp_len = 10;
	double		arr[exp_len];
	size_t		len;

	len = ft_fill_array(arr, exp_len);
	cout << "The length of read array: " << len << endl;
	ft_show_array(arr, len);
	ft_reverse_array(arr, len);
	ft_show_array(arr, len);
	return (0);
}
