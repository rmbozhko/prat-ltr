#include <iostream>

int		main(void)
{
	using	namespace	std;

	// || operation
	// if (l_expr || r_expr), if l_expr equals 'true' compiler
	// won't evaluate rightmost expr, as || need only one 'true'
	// to return 'true'
	int		x;

	x = 5;
	if (x++ < 10 || x++ == 2)
	{
		// x = 6 will be displayed,
		// this for not evaluating r_expr by compiler
		cout << "Here is x: " << x << endl;
	}
	
	// This works similiar for &&(and)
	int		y;

	y = 1;
	if (++y == 3 && ++y < 4)
		;
	else
	{
		// As far as you may see we didn't enter the r_expr.
		// And didn't evaluate it so far
		// now y is 2 but could be 3(thanks to r_expr)
		cout << "Here is y: " << y << endl;
	}

	// there is one great option if the one doesn't have &, |, ! chars
	// on one's keyboard, in C++ there are alternatives to that
	// and(&&), or(||) and not(!) just like in Python
	// By the way this can be also added into C, just #include <iso646.h>
	// i believe this is header file with defines like following:
	// #define and &&, #define or || #define not !
	// or more complex, you should check someday
	if ((not true or true) and not false)
		cout << "This is alternative syntax :)" << endl;

	
	// Ternary operator
	// Very complicated, therefore useless example
	const	char	arr[2][50] = {"Jason ", "at your service\n"};
	const	char	*str = "Quillstone ";
	for (int i = 0; i < 3; i++)
		cout << ((i < 2) ? !i ? arr[i] : str : arr[!!i]);
	
	// swtich practicing
	// switch's cases values can be integers and char or enum constants
	// if cases are integers and constant char is passed as a choice
	// we would get the endless loop, better check why
	
	// Very important!!!!!!Very-very!!!!
	// 'cin' is !!!very bad!!! way to read input from stdin
	// if you are reading char 'q' to variable, which data type is 'float' or 'int'
	// such behaviour makes 'cin' set its failbit to '1'
	// as knwon, if failbit or eofbit equals to '1' further reading ins't prohibited
	// this will happen in our second loop, where we use enum constants,
	// if we type any character('a' || 'A' || '.') instead of 'int'
	float	f_num;
	cin >> f_num;
	

	// If switch cases data types are chars there won't be endless loops as each
	// key is actually char('a', 'A', '.', '1')
	char		choice;

	cin >> choice;
	while (choice != 'Q' && choice != 'q' && !cin.eof())
	{
		cout << "Type a, a, r, R, l, L, c, C for switch" << endl;
		switch (choice)
		{
			// Multiple choices like (choice == 'a') && (choice == 'A')
			case 'a':
			case 'A':
				cout << "little a";
				cout << "\a\n";
				break ;
			case 'r':
				// as here is no break wi move further to 'R' case
				// and meet break there
				cout << "little r";
			case 'R':
				cout << "reporting ...\n";
				break ;
			case 'l':
			case 'L':
				cout << "The boss was in all day.\n";
				break ;
			case 'c':
				cout << "little c";
			case 'C':
				cout << "Such a comfort....\n";
				break ;
			default:
				cout << "This is not a choice\n";
		}
		cin >> choice;
	}


	// Switch practicing using enum constants
	// Meanwhile, 'enum' is created in way its constants can be only accessed
	// We have no opportunity to create variable with such data type
	enum	{red = 1, orange, yellow, green, blue, violet, indigo};
	int	code;

	// But when we are expecting to get numuric value and instead got character('a', '.')
	// cin returns '0'(zero) and sets its failbit to '1' to prevent any further reading
	
	do
	{
		cout << "Enter color code (1-7): ";
		// Here we put input into 'int' varibale, as 'cin' object knows nothing about
		// out new enumeration data type
		cout << cin.fail() << endl << cin.eof() << endl;
		// But using cin.clear and cin.fail checking
		// we can unset failbit and continue reading from stdin
		if (!cin.eof() && cin.fail())
		{
			cin.clear();
			cout << cin.fail() << endl << cin.eof() << endl;
			cin.get();
		}
		cin >> code;
		cout << "Code is: " << code << endl;
		switch (code)
		{
			// Down below, while comparing code and enum constants,
			// the last ones(constants) are automatically casted to 'int'
			case 0:
				cout << "Something went wrong, check your input!\a\a\a\a\n";
				break ;
			case red:
				cout << "You have selected red color\a\n";
				break;
			case orange:
				cout << "You have selected orange color\a\n";
				break;
			case yellow:
				cout << "You have selected yellow color\a\n";
				break;
			case green:
				cout << "You have selected green color\a\n";
				break;
			case blue:
				cout << "You have selected blue color\a\n";
				break;
			case violet:
				cout << "You have selected violet color\a\n";
				break;
			case indigo:
				cout << "You have selected indigo color\a\n";
				break;
			default:
				cout << "You havn\'t choosen color. Try again\n";
		}
	}
	while ((code == 0 || (code >= red && code <= indigo)) && !cin.eof());

	return (0);
}
