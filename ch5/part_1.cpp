#include <iostream>
#include <array>

int		main(void)
{
	using	namespace	std;

	cout << (3 < 2) << endl;
	cout << (3 > 2) << endl;
	cout.setf(ios_base::boolalpha);
	cout << (3 < 2) << endl;
	cout << (3 > 2) << endl;

	// In 'for' cycle the variable we declare as counter
	// will vanish after we exit the cycle
	for (int i = 0; i < 3; i++)
		cout << "Hello, World!" << i <<"\n";
	//cout << i << endl; // not allowed, compiler can't found varibale 'i'

	const int	arr_size = 16;
	array<long long, arr_size> fib_arr;
	
	// 1 will be automatically casted to 'int'
	// so we use suffix 'LL' to cast it by ourselves
	fib_arr[0] = fib_arr[1] = 1LL;
	
	for (int i = 2; i < arr_size; i++)
		fib_arr[i] = fib_arr[i - 1] * i;

	for (int i = 0; i < arr_size; i++)
		cout << i << "! = " << fib_arr[i] << endl;

	// Using 'for' loops with strings and arrays
	string		name;
	char		surname[] = "Bozhko";

	name = "Roman";
	for (int i = 0; i < name.size(); i++)
		cout << name[i] << endl; 
	
	cout << "Here goes surname" << endl;
	
	for (int i = 0; i < sizeof surname; i++)
		cout << surname[i] << endl; 


	// Incrementing, decrementing
	int	a, y, z;

	a = 10;
	z = 5;
	y = z + a++, z = a;
	cout << a << endl << y << endl << z << endl;

	// Working with pointers
	double		arr[5] = {21.1, 32.8, 23.4, 45.2, 37.4};
	double		*d_ptr = arr; // *d_ptr == arr[0] == 21.1

	++d_ptr; // *d_ptr == arr[1] == 32.8
	// ++d_ptr == arr[2] == 23.4 and * returns this value to 'x' variable
	double		x = *++d_ptr; 
	// * returns value of addr d_ptr is curr. pointing to
	// ++ increments returned value
	++*d_ptr;
	
	// * returns value of addr d_ptr is curr. pointing to
	// ++ increments returned value
	(*d_ptr)++;

	// we increment d_ptr addr., so now it points to arr[3]
	// but as we are working with postfix increment
	// we got its previous value arr[2] with '*'
	x = *d_ptr++;

	// Allowed, as we get next 1-st line
	// and it's 'if-statement' with opening and closing parentheses
	while (1)
		if (1)
		{
			cout << "YEAH!!" << endl;
			break ;
		}	

	// Sub-local scope in functions
	int	m = 10;
	{
		cout << "In local scope: " << m << endl; // 10
		int	m = 100;
		cout << "In local scope: " << m << endl; // 100	
	}	
	cout <<"In outer scope: " << m << endl; // 10

	// Using comma as delimeter
	char	c;
	string	word;
	
	cout << "Enter any word to reverse: ";
	cin >> word;
	for (int j = 0, i = word.size() - 1; j < i; i--, j++)
	{
		// we can define and initialize char c in cycle
		// program execution will slow down as 
		// we will create 'c' variable each time cycle executes
		// but we'll save memory as 'c' will vanish after leaving cycle
		c = word[j];
		word[j] = word[i];
		word[i] = c;
	}
	cout << "Reversed string: " << word << endl;
	
	int i, j, o;
	
	// allowed, the result of expressin below is result of last operation
	// in our case it is 2 * j = 2 * 40 = 80
	// we can return this value from main() and check it using $?
	i = 20, j = 2 * i, o = 2 * j;

	int	cats;

	// ',' has less priority than '=',
	// so here we assign 17 t 'cats' and 240 does nothing
	cats = 17, 240;
	cout << "Cats: " << cats << endl; // 17
	// But here we assign 240 to 'cats', as the last operation is returned
	// revise line #116
	cats = (17, 240);
	cout << "Cats: " << cats << endl; // 240

	// Comparing string literals
	char	nick[] = "rbzhko";
	
	// nick represents the address of first char
	// and address where 'nick' is allocated
	// as 'rbozhko' is located in other place than 'nick' it'll result -> 0
	cout << bool (nick == "rbzhko") << endl; //false(0)
	// But if we compare nick == nick it'll result -> 1,
	// as both values have same address in memory
	cout << bool (nick == nick) << endl; //true(1)

	// Comparing string objects
	string	company = "SAP";
	char	carr[] = "LOL";
	char	*cptr = carr;
	
	// As C++ provides prgrammers with operators overload
	// So in 'string' class we have cmp string objects using '==' and '!=
	// Using following operators we can cmp not only string objects,
	// but also plain C-like arrays, string literals and char ptrs(char*)
	cout << "Comparing string objects using '=='" << endl;
	cout << bool(company == "SAP") << endl;
	cout << bool(company == company) << endl;
	cout << bool(company == carr) << endl;
	cout << bool(company == cptr) << endl;

	cout << "Comparing string objects using '!='" << endl;	
	cout << bool(company != "SAP") << endl;
	cout << bool(company != company) << endl;
	cout << bool(company != carr) << endl;
	cout << bool(company != cptr) << endl;
	

	return (0);
}
