#include <iostream>
# define PLAYS_NUM 10


using	std::cout;
using	std::cin;
using	std::endl;


int		*ft_get_input(size_t *len)
{
	int		*results = new int[PLAYS_NUM];
	int		i;
	
	for (i = 0; i < PLAYS_NUM; i++)
	{
		cout << "Enter result of game #" << i
		<< ":(to quit the input mode enter Ctrl+D or \'q\'" ": ";
		if (!(cin >> results[i]))
		{
			if (cin.eof())
				break ;
			cin.clear();
		 	if (cin.get() == 'q')
				break ;
			while (cin.get() != '\n')
				continue ;
			
		}
		cout << "Element #" << i << " is " << results[i] << endl;
	}
	*len = i;
	return (results);	
}

double		ft_get_avg(int *begin, const int *end)
{
	int		total;

	total = 0;	
	for (int *temp = begin; temp != end; temp++)
		total += *temp;
	return (double(total / int(end - begin)));
}

void		ft_show_arr(const int *arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
		cout << "Element #" << i << " is: " << arr[i] << endl;
}

int		main(void)
{
	size_t		len;
	int		*arr;

	arr = ft_get_input(&len);
	cout << "The avg of whole array is: " << ft_get_avg(arr, arr + len) << endl;
	ft_show_arr(arr, len);
	return (0);
}
