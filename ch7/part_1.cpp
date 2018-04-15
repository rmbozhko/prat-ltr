#include <iostream>
#include <cstdarg> // va_list, va_arg are defined here, do you remember 'ft_printf'????

void		ft_get_name(const char *str);
void		cheers(); // same as cheers(void)
int		greetings(int); // we are allowed to define 'int' varibale or leave it like here
// if we don't want to specialize the arguments of function, we do so
// variable num of params, use of ft_printf custom implemetation 
int		ft_find_biggest(int quantity, ...);
// Not allowed to have many functions of variable arg list len
//int		ft_find_biggest(char quantity, ...);

// Good example
void		ft_example(float, float);
void		ft_instance(float a, float b);

// Bad example
//void		ft_beispiel(float a, b); // Error
long double	ft_probability(unsigned total_amount, unsigned chances);

int		ft_arr_elem_sum(int arr[], int elem_num);
int		ft_arr_ptr_elem_sum(int *arr, int elem_num);

int		main(void)
{
	using		namespace	std;

	const	int	arr_size = 3;
	unsigned	total_num;
	unsigned	choices;	
	int		array[arr_size] = {2, 3, 29};
	int		*arr;
	
	arr = new int[arr_size];
	arr[0] = 5;
	arr[1] = 15;
	arr[2] = 25;
	cout << &arr << endl << &array << endl;	
	cout << &arr[0] << endl << &array[0] << endl;	
	cout << "The result: " << ft_find_biggest(arr_size, array) << endl;
	cout << "LONG LONG: " << sizeof (long long) << endl;
	cout << "LONG DOUBLE: " << sizeof (long double) << endl;
	cout << "Enter the integers set and number of choices to do.\n";
	while (cin >> total_num >> choices && choices <= total_num)
	{
		ft_probability(total_num, choices);
		cout << "Enter the integers set and number of choices to do.\n";
	}
	cout << "Bye" << endl;
	cout << "The sum of elems, using arr syntax: " << ft_arr_elem_sum(array, arr_size) << endl;
	cout << "The sum of elems, using pointer syntax: " << ft_arr_ptr_elem_sum(arr, arr_size) << endl;
	cout << "Pointer to array modified value: " << arr[2] << endl;
	cout << "Array notation modified value: " << array[2] << endl;
	const char		*name = "Andrew";

	ft_get_name(name);
	delete []arr;
	return (0);
}

void		ft_get_name(const char *str)
{
	using		std::cout;
	using		std::endl;

	cout << str << endl;
}

long double	ft_probability(unsigned total_amount, unsigned chances)
{
	using		namespace	std;
	
	// as mentioned in main() long double has more place than any other data type
	long double		result;

	result = 1.0;
	for (unsigned i = total_amount, j = chances; j; i--, j--)
	// we need to cast here as we are assigning float point result
	// we have two unsigned(4 bytes) and we to manual typecast tot long double(16)
	// in such case we will get the result stored in the largest data type, so long double
	// luckily our 'result' variable is also long double so we won't lose any data
		result *= ((long double)i / j);
	cout << fixed;
	cout.precision(5);
	cout.setf(ios_base::showbase);
	cout << "Probability: " << result << endl;
	return (result);
}

int		ft_find_biggest(int num, ...)
{
	using		namespace	std;
	
	int		res;
	va_list		v_list;
	int		value;

	res = 0;
	va_start(v_list, num);
	for (int i = 0; i < num; i++)
	{
		value = va_arg(v_list, int);
		if (value > res)
			res = value;
	}
	va_end(v_list);
	cout << "The biggest value of passed array: " << res << endl;
	return (res);
}

// As far as we know in C and in C++, when we pass variable as a parameter to function we copy its value
// But when we are passing an array or a pointer to an array, we actually pass the address of it
// So in function, we work with its actual values
// Check by yourself: *** modified value: [new_last_elem value]
int		ft_arr_ptr_elem_sum(int *arr, int elem_num)
{
	using	namespace	std;

	int		sum;

	sum = 0;
	for (int i = 0; i < elem_num; i++)
		sum += arr[i];
	cout << "The sum of arr elements, using pointer syntax: " << sum << endl;
	arr[2] = 500;
	return (sum);
}

int		ft_arr_elem_sum(int arr[], int elem_num)
{
	using	namespace	std;

	int		sum;

	sum = 0;
	for (int i = 0; i < elem_num; i++)
		sum += arr[i];
	cout << "The sum of arr elements, using array syntax: " << sum << endl;
	arr[2] = 999;
	return (sum);
}
