#include <iostream>

#define SIZE 3

int		main(void)
{
	using	namespace std;
	unsigned char i;
	int		arr[SIZE];
	char		temp[SIZE] = {'A', 'B', 'C'};
	// in this case only the first element of the array will get value: '1'
	// 499 others will get 0, so it's easy way to ft_bzero array
	long		array[500] = {1};
	// in this case compiler will count len of arr1 and allocate proper num of bytes for it
	short		arr1[] = {1, 2, 3, 4};	
	arr[0] = 12;
	arr[1] = -99;
	arr[2] = 2147483647;
	i = 0;
	while (i < SIZE)
	{	
		cout << temp[i++] << endl;
	}
	i = 0;
	while (i < SIZE)
	{
		cout << arr[i++] << endl;
	}
	
	// In C++11 we are allowed to initialize array with curly braces
	double		darr[] {1.2e2, 1.7e3, 21.62e4, -2.786e8};
	
	// As mentioned before this assigning is better, as it warns programer
	// narrowing conversion of ‘3.0e+0’ from ‘double’ to ‘long int’ inside { } [-Wnarrowing]
	long		larr[] = {31, 22, 3.0};
	char		carr[] = {'L', 'O', 214748, 'L'};
	
	// As C-alike way to bzero array C++11 approuch is nearly same.
	// But we should specify num of array elems to know how long to bzero
	// If nothing is passed len by default is set to '0'.
	int		iarr[] = {};
	unsigned 	uiarr[] {};
	
	cout << sizeof iarr << " " << sizeof uiarr << endl;

	char		cdog[] = {'S', 'p', 'o', 't'}; // error, where is '\0'?
	char		ccat[5] = {'M', 'u', 'f', 'y', '\0'}; // OK

	cout << cdog << endl << ccat << endl;
	char		cdino[] = "T-rex"; // '\0' added by default
	char		cfish[6] = "Nemo"; // it bzero rest by default
	// [0] = N, [1] = e, [2] = m, [3] = o, [4] = '\0', [5] = '\0'
	
	cout <<	*(cfish + 1) << endl;

	// We can concatinate string literals in C++, !!not!! (char*(string)) vars
	cout << "Hello," " World!" << endl;
	cout << "I need more,"
	" more POWER!!!!" << endl;
	cout.put('\0');

	// The main problem of 'cin' is that it is word-oriented
	// So, if we type in New York, we need 2 variable to store those values
	// as 'cin' default delimiter are space, tab, newline character
	// But 'cin' object of class istream has 2 methods, which are line-oriented
	const	unsigned arr_size = 18;
	char		name[arr_size];
	char		dessert[arr_size];
	char		hometown[arr_size];
	char		homeland[arr_size];	

	// Things about getline():
	// 1. its read till end of line(when 'return' hit) and take it in 1-st arg
	// but then replace it with terminating zero char.
	cout << "Enter your " "name: ";
	cin.getline(name, arr_size);
	cout << "Enter your favorite dessert: ";
	cin.getline(dessert, arr_size);
	cout << "Ok, " << name << " here is your order: " << dessert << endl; 
	cout << "Enter hometown and homeland: " << endl;
	// This is possible as getline() return 'cin' object
	// which is use in second call of function getline()
	cin.getline(hometown, arr_size).getline(homeland, arr_size);
	cout << "I live in " << hometown << ". It is in " << homeland << endl;

	// Things about get():
	// 1. Is mainly exactly the same as getline, but if getline reads to newline character and stops !!after!! it, get() reads till newline char and stops !!before! it. So second call of get() won't bring anything interesting unless this newline character will be somehow read. And it is where cin.get() -> get() which reads 1 char come to play some role.
	
	cout << "Enter your " "name: ";
	cin.get(name, arr_size).get();
	cout << "Enter your favorite dessert: ";
	cin.get(dessert, arr_size).get();
	cout << "Ok, " << name << " here is your order: " << dessert << endl; 
	cout << "Enter hometown and homeland: " << endl;
	// get with params returns 'cin' object
	// while get without params returns ASCII code of read character.
	cin.get(hometown, arr_size).get();
	cin.get(homeland, arr_size).get();
	cout << "I live in " << hometown << ". It is in " << homeland << endl;
	cin.get(homeland, 3).get();		
	// In conclusion, I would summarize that both: getline() and get()
	// if line length is more than passed num_of_bytes_to_read(2-nd param)
	// set flag: failbit, which blocks any further output.
	// if line is empty -> get() set failbit and stops executing and calling	// while getline do nothing about that
	// But for debugging get() is better as we can reveal easily if it got to end or not. get(void) -> returns ASCII code of read char.
	// If this code == '\n', than get(varArr, varSize) read correctly to end of string.
	// If code differs than it is about array size overflow. There are more chars to read, but we have no more space for them.
	// BUT IS FLAG: failbit can be omitted using method: cin.clear()
	//cin.clear();
	cin.get(homeland, 3).get();	

	// Problem of cross-type reading
	int		number;
	char		wish[500] {};
	cout << "Enter any ASCII Table code: ";
	// Problem is in 'cin' reading
	// here it reads some value but leaves newline-char unread(like get())
	(cin >> number).get();
	cout << "Enter your wish: ";
	// If we call getline it puts nothing in wish varible
	// because as we know getline reads newline character
	// and replace it with terminating zero: '\0'
	// as mentioned before the one char left in stdin is newline char
	// So thing we need to do is to read this newline char
	// OR with getline: (cin >> i).get()
	cin.get(wish, sizeof wish).get();
	cout << "And your wish is: " << wish << endl;
	
		
	return (0);
}
