#include <iostream>
#include <string>
#include <ctime> // C library to get everything interconnected with time

typedef	float* ft_ptr;
#define FC_PTR float*

int		main(void)
{
	using	std::cout;
	using	std::endl;
	using	std::string;
	using	std::cin;
	using	std::clock;

	string		temp;
	unsigned	i;

	temp = "Lov'in you, baby";
	i = 0;
	while (temp[i])
		cout << temp[i++] << endl;
	cout << int(temp[i]) << endl;

	// Endless for-loop:
	/*for (;;) // upsense of check condition is always interpreted as 'true'
	{}*/

	// as std::clock() may return long, unsigned long, or anything else
	// clock_t data type is declared, and its type depends on system
	clock_t		delay;
	float		secs;
	clock_t		start;

	cout << "Enter the delay time, in seconds: ";
	cin >> secs;
	// CLOCKS_PER_SEC is constant defined in <ctime>(time.h) file
	// it stores num of seconds in 1 unit of sys time
	// here we got how long to postpone program execution
	// secs_num * CLOCKS_PER_SEC == number of sys units to wait
	delay = secs * CLOCKS_PER_SEC;
	start = clock(); // returns num of time units spent after program started
	while (clock() - start < delay)
	{
		cout << "Yo, here we are!" << endl;
	}
	cout << "Going further\a" << endl;	
	

	// here only 1 variable is declared as pointer to float with size = 8 bytes
	// anther one is plain float varible with size = 4 bytes
	FC_PTR lol, mol;
	cout << "Size of declared varibales using #define:" << sizeof lol
	 << endl << sizeof mol << endl;

	// here both variables are declared as pointers to float
	// we can see that from size of pointers(8 bytes)
	ft_ptr pol, wol;
	cout << "Size of declared varibales using typdef: " << sizeof pol 
	<< endl << sizeof wol << endl;
	
	// do-while cycle
	const	int	beloved_num = 7;
	int		usr_asnwer;

	do
	{
		cout << "Enter number in range(1-10)" << endl;
		cin >> usr_asnwer;
	}
	while (usr_asnwer != beloved_num);
//	cin.clear();
	cout << "Yes, you did it." << endl;

	double		prices[] = {12.99, 8.50, 11.00, 2.99, 4.89};
	
	// for-range loop
	for (double x : prices)
	{
		cout <<	x << endl;
	}
	// for-range loop over initialization list	
	for (int x : {1, 2, 3, 4, 5, 6, 7})
		cout << x << " ";
	cout << endl;
	// for-range loop with value modifying
	for (double &x : prices)
	{
		x *= 0.8; // 20% sale :)
		cout << x << endl;
	}
	
	// const is modifier and auto decides what type to use
	const auto num = 12;
	cout << "NUM: " << num << " and SIZE: " << sizeof num << endl;


	// Reading from stdin
	// object of class 'istream' cin has 3 different user interfaces to handle user input
	// cin >> var_name
	// cin.get() // returns ASCII code of read character or -1 if EOF is met
	// cin.get(char) // uses reference to modify value of single passed arg
	// it automatically casts to 'true' if read character differs from EOF
	// and 'false' if EOF is the last read character
	
	// cin >> var_name
	// cin object returns read value only if <Enter> is pressed,
	// till it isn't pressed the input is buffering and waiting cmd to be returned to program
	// this kind of reading omits spaces(' '), tabulation(\t) and new-line characters(\n)
	int	count1 = 0;
	char	ch1;

	cout << "Enter characters; enter # to quit:\n";
	do
	{
		cout << ch1;
		cin >> ch1;
		count1 += (ch1 != '#') ? 1 : 0;
	} while (ch1 != '#');
	cout << endl << count1 << endl;

	// cin.get(char)
	// the input is still buffering, we got it after hit <Enter>

	int	count2 = 0;
	char	ch2;

	cout << "Enter characters; enter # to quit:\n";
	cout << "HEre you go: " << ch2;
	do
	{
		cout << ch2;
		cin.get(ch2);
		count2 += (ch2 != '#') ? 1 : 0;
	} while (ch2 != '#');
	cout << endl << count2 << endl;

	return (0);
}
