#include <iostream>

// The whole thing showed восходящее програмирование, от дателей к общей идее(основы ООП)
// в отличие от нисходящего процедурного, где от идеи к деталям

void		ft_display_arr(const int arr[], const int arr_size)
{
	using	namespace	std;

	// default pointer size will be displayed, as we don't get the copy of first arg, as it's an array
	// we get its address, and variable 'arr' is pointing to that address
	// Besides, no metter in what conditions we pass an array to this function
	// the size of pointer is constant
	cout << "Sizeof an array ptr: " << sizeof arr << '\n';
	cout << "The address of passed array: " << arr << endl;
	for (int i = 0; i < arr_size; i++)
		cout << "Array\'s #" << i + 1 << " element: " << arr[i] << endl;	
}

void		ft_display_arr(const int *begin, const int *end)
{
	using	namespace	std;
	
	// displaying content of an array with pointers only
	// 1st arg - the beginning of an array
	// 2nd arg - the end of an array
	// actually the last arg is not the end, but the address in memory after array
	int		i;
	
	cout << "The beginning of passed array: " << begin << endl;
	cout << "The end of passed array: " << end << endl;
	cout << "Calculating amount of elems: " << (end - begin) << endl;
	i = 0;
	for (const int *ptr = begin; ptr != end; ptr++, i++)
		cout << "Array\'s #" << i + 1 << " element: " << *ptr << endl;	
}

void		ft_modify_arr(int arr[], unsigned arr_size, int coef)
{
	using		namespace	std;
	
	cout << "All elements of passed array will be multiplied by " << coef << ".\n";
	for (int i = 0; i < arr_size; i++)
		arr[i] *= coef;
}

int		ft_fillin_arr(int arr[], unsigned arr_size)
{
	using		namespace	std;

	int		temp;
	int		i;

	for (i = 0; i < arr_size; i++)
	{
		cout << "Enter the element #" << i + 1 << ": " << endl;
		// handle input
		if (!(cin >> temp))
		{
			// if Ctrl+D is pressed it's no error but casual program workflow
			if (cin.eof())
				break ;
			cout << "Bad input. Terminating function execution..." << endl;
			// we reset fail || bad to zero ('0') to read everything that is left in stdin
			cin.clear();
			// we read char by char till new-line character using cin.get()
			// we could have used cin.getline() but we need to define storage
			// and num of chars to read
			while (cin.get() != '\n')
				continue ;
			break ;
		}
		else if (temp < 0)
			break ;
		arr[i] = temp;
	}
	return (i);
}

int		main(void)
{
	using	namespace	std;
	
	const	int	arr_size = 5;
	const	int	arr[arr_size] = {1, 2, 3, 4, 5};
	int		array[arr_size];
	int		size;

	// arr_size * 4 will be displayed, as we are asking about size of an array
	cout << "Sizeof an array: " << sizeof arr << endl;
	// displaying all elements
	ft_display_arr(arr, arr_size);
	// displaying only 3 elems at the beginning
	ft_display_arr(arr, arr_size - 2);
	// displaying only 2 elems at the end
	ft_display_arr(arr + 3, arr_size - 3);
	
	size = ft_fillin_arr(array, arr_size);
	cout << "Real size of newly created array: " << size << endl;
	// 1st argument: array pointer, 2nd: array size
	ft_display_arr(array, size);
	ft_modify_arr(array, size, 3);
	ft_display_arr(array, size);

	ft_display_arr(array, array + size);
	return (0);
}
