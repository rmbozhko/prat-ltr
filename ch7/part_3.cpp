#include <iostream>
#include <cstring>

const	unsigned	num_of_months = 12;

unsigned	sum_days(const int days_arr[], int arr_len)
{
	unsigned	len;

	len = 0;
	for (int i = 0; i < arr_len; i++)
		len += days_arr[i];
	return (len);
}

void		ft_print_name(const char *str)
{
	std::cout << str << std::endl;
}

int		main(void)
{
	using	namespace	std;
	
	// making pointer const about value
	int		age;

	age = 39;
	// we cannot modify age variable using i_ptr(implicitly)
	const int	*i_ptr = &age;
	//*i_ptr = 50; // not allowed
	// but we can modify this value using age variable
	age = 50;
	// constant value pointer doesn't have to point to const variable
	// it can be but itsn't necessary
	//const	int	some_const = 12;
	//const int 	*some_var = &some_var;
	
	// but if you want to assign some const to pointer pointer should also be defined as constant
	const	float	pi = 3.14;
	const	float	*f_ptr = &pi;
	//float		*pi_ptr = &pi; // is not allowed, if var is const ptr should be also const
	
	const	int	**pp2;
	const	int	*p1; // but if p1 was just int*(not constant) we could compile program
	const	int	n = 13;
	
	pp2 = &p1;
	*pp2 = &n;
	cout << **pp2 << endl;

	const	int	months[num_of_months] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	
	
	// if we want to pass const ptr to function it also should be declared as const
	cout << "Sum of days in year: " << sum_days(months, num_of_months) << endl;

	// we have review a pointer to constant value
	// but we can make this pointer variable point to another block of memory(variable)
	const	int	*ptr_const_val;
	int		some_val = 2;
	const	int	some_const_val = 5;
	
	ptr_const_val = &some_const_val;
	cout << "Changable pointer: " << *ptr_const_val << endl;
	ptr_const_val = &some_val;
	cout << "Changable pointer: " << *ptr_const_val << endl;

	// but we can define pointer to point only to one address and nowhere else
	// besides it can even change that block of memory
	int		sloth = 3;
	int	*const	const_memory_ptr = &sloth;
	
	cout << *const_memory_ptr << endl;
	//const_memory_ptr = &some_val; // not allowed

	// we can even mix these types of pointers like coctails
	// a not memory address and value changable pointer
	double		trouble = 2.0E30;
	// we cannot change value of variable we're pointing to
	// and we cannot change the variable we are pointing to
	const	double	*const	stick = &trouble;
	cout << fixed;
	cout.precision(4);
	cout.setf(ios_base::showbase);
	cout << *stick << endl;
	

	char		*str;

	str = new char[15];
	strcpy(str, "Roman Bozhko");
	ft_print_name(str);
	return (0);
}
