#include <iostream>

int		main(void)
{
	using	namespace	std;

	char		c;

	while (cin >> c)
	{
		cout << "Here we go: " << c << endl;
		switch (c)
		{
			// we can read numeric input from keyboard
			// and handle it with cases
			case '0':
				cerr << "Smth bad has happened!";
				break ;
			case '1':
				cout << "Yo, yo here you are!#1";
				break ;
			case '2':
				cout << "Jessy Pinckman in da house!#2";
				break ;
			case '3':
				cout << "It is exact how sounds!#3";
				break ;
			default:
				cout << "Nothing choosen biatch!#def";
		}
		cout << endl;
	}
	cout << "Bad: " << cin.bad() << endl
		<< "Good: " << cin.good() << endl
		<< "Fail: " << cin.fail() << endl
		<< "EOF: " << cin.eof() << endl;
	cout << "Output: " << c << endl;
	if (!cin.good())
		cin.clear();
	int		lines;

	lines = 0;
	while (cin.get(c) && c != 'Q')
		lines += (c == '\n') ? 1 : 0;
	cout << "Lines quantity: " << lines << endl;
	return (0);
}
