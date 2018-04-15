#include <iostream>

using	namespace	std;

// inline functions
// great news for C++ developers, if your function is small(1-3 lines), not recursive
// and is called 'once upon a time' you can use 'inline' keywork to specify function as built-in
// if function execution time is less than function calling proccess time, then this function should be built-in

inline	double		ft_square(int n);
inline	void		ft_change_toys_value(int &n);

int		main()
{
	double		x;

	cout << "Enter value: ";
	cin >> x;
	// look out we are passing double variable to function that recieves int
	// Don't worry it is internal job of C++ to casr passing variable value if it hasn't found function
	// with needed name and parameters
	cout << "And result is: " << ft_square(x) << endl;

	// References
	int		rats;
	// In line below rodents bacome the alternative name for memory block accessed by name 'rats'
	// this means that you can access same memory address where some value is stored using two different names
	int		&rodents = rats;

	rats = 12;
	cout << "Rats: " << rats <<" and Rodents: " << rodents <<endl;
	rodents = -5; 
	cout << "Rats: " << rats <<" and Rodents: " << rodents <<endl;
	// The following output shows that these varibales have same memory address
	cout << "Rat's address: " << &rats <<" and Rodents' address: " << &rodents <<endl;

	// reference and pointer have lots in common
	int		bad_num = 666;
	int		pos_num = 777;
	int		&devils_num = bad_num;
	int		*bad_num_ptr = &bad_num;

	cout << "Value via ref.: " << devils_num << ", address via ref.: "
		<< &devils_num << ", address of ref.: " << &devils_num << endl;
	cout << "Value via ptr.: " << *bad_num_ptr << ", address via ptr.: "
		<< bad_num_ptr << ", address of ptr.: " << &bad_num_ptr << endl;

	// but there is one problem
	// you cannot reassign devils_num(reference) to any other variabke
	// in this case you will assign pos_num value to devils_num address	
	//devils_num = pos_num; // not allowed
	// but you can do that with pointer
	bad_num_ptr = &pos_num;
	// unless it is declared as int *const bad_num_ptr, because such declaration prohibits reassigning
	// So to say, reference is very similar to pointers, especially to const pointers(void *const variable)

	// look at line, where 'devils_num = pos_num', actually it is allowed
	//  but is this case you won't reassign devils_num, you will just change the value it has
	cout << "Bad_num: " << bad_num << " and devils_num: " << devils_num << ", and of course pos_num: " << pos_num << endl;
	devils_num = pos_num;
	cout << "Bad_num: " << bad_num << " and devils_num: " << devils_num << ", and of course pos_num: " << pos_num << endl;


	// Trying to reassign using pointers
	int		apples = 101;
	// here ptr is pointing to apples variable
	int		*apples_ptr = &apples;
	// here we assign to ref variable a variable whose address is stored in apples_ptr variable
	// from this example we can conclude that the only way to assign an address of any variable to ref. var
	// is to define it when declaring the reference variable like above or below
	int		&apples_ref = *apples_ptr;
	int		oranges = 50;
	cout << "Apples: " << &apples << ", Apples ref.: " << &apples_ref << ", Apples ptr.: " << apples_ptr << endl;
	apples_ptr = &oranges;
	// apples_ptr has changes, but apples_ref doesn't
	cout << "Apples: " << &apples << ", Apples ref.: " << &apples_ref << ", Apples ptr.: " << apples_ptr << endl;
	
	cout << "Apples: " << apples << ", Apples ref.: " << apples_ref << ", Oranges: " << oranges << endl;
	apples_ref = oranges;
	cout << "Apples: " << apples << ", Apples ref.: " << apples_ref << ", Oranges: " << oranges << endl;


	// Using references in their natural environment, in functions(like arguments)
	int		toys;

	cout << "Please enter, how many toys do you have: ";
	cin >> toys;
	cout << "Toys variable value before function with ref. variable is called: " << toys << endl;
	// when we call function the list of its argumnets is declrared and defined with passed params
	// in our case it's toys variable, whose original value, not copied one, can be easily accessed
	// using function reference parameter
	ft_change_toys_value(toys);		
	cout << "Toys variable value after function with ref. variable is called: " << toys << endl;
	return (0);
}

inline	void		ft_change_toys_value(int &n)
{
	n = 999;
}

inline	double		ft_square(int n)
{
	return (n * double(n));
}
