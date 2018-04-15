#include <iostream>
#include <climits>

using		std::cout;
using		std::endl;
using		std::dec;
using		std::oct;
using		std::hex;
using		std::cin;

int		main(void)
{
	char		c;
	size_t		i(10); // C++ alike syntax
	size_t		j = 55; // C alike syntax
	int		rheads = {12}; //C++11 assigning
	int		emus{7}; //C++11 assigning
	int		rocks = {}; //C++11 assigning, in particular case rocks assigned to zero
	
	int		deca;
	int		octa;
	int		hexa;

	deca = 10;
	octa = 010;
	hexa = 0x10;
	cout << "deca: " << deca << ", octa: " << octa << ", hexa: " << hexa << endl;
	
	//It reveals that cout object of class ostream
	//has other manipulators that endl: dec, oct, hex
	//they are used to modify output made by cout
	cout << oct;
	cout << "Octal: " << deca << endl;
	cout << hex;
	cout << "Hexademical: " << deca << endl;
	//beware to change manipulator to default(dec)
	//or all passed nums will be converted to hex
	cout << dec;
	cout << "Decimal: " << deca << endl;

	cout << "I: " << i << endl << "J: " << j << endl;
	cout << "Size of short: " << sizeof(short) << endl;
	cout << "Size of long int: " << sizeof(long int) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long: " << sizeof(long) << endl;
	cout << "Size of long long: " << sizeof(long long) << endl;
	
	//Following constants defined in <climits> || <limits.h> -> no namespace usage
	cout << "Number of bites in byte: " << CHAR_BIT << endl;
	cout << "INT MAX: " << INT_MAX << endl;
	cout << "Short MAX: " << SHRT_MAX << endl;
	cout << "Long long MAX: " << LLONG_MAX << endl;
	cout << "Long MAX: " << LONG_MAX << endl;
	

	// What data type will have pushed into cout constant
	cout << "Current year: " << 2017 << endl;
	// By default, all passed constants will be fitted into int
	// But if number is bigger than int, it would be passed to bigger data type: long or long long
	// But we can make cout store int num in unsinged long:
	cout << "Current year: " << 2017UL << endl;
	// besides if we pass hex or cotal number after int
	// it would be fitted into unsigned int, not into long
	// single U - stands for unsigned int
	cout << "Current year: " << 0x42U << endl;
	cout << "Hell, yeah ... ";
	

	// cout.put() method displays passed as argument character
	cout.put('!');
	// use of cout.put() is defined by historical reasons
	// before C++ 2.0 all char variables displayed their values properly
	// char c = '$'; cout << c; -> '$' sing was displayed
	// whereas 
	// cout << '$'; an ASCII code for dollar sing was displayed
	// this is because in that version char constants was stored in int data type vars
	// but cout.put() did printing contants properly: cout.put('$') -> '$' got printed
	// But nowadays, in C++ 2.0 char constants are stored in char variables, so everything is Good
	cout << endl;

	while (cin.get(c))
	{
		if (c == 'q')
		{
			cout << "Exiting..." << endl;
			break ;
		}
		cout.put(c);
	}

	char		alarm;
	
	alarm = '\a';
	cout << alarm << "Don\'t do that again\a\n";	
	return (0);
}
