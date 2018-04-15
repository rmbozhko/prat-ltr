#include <iostream>
#include <cctype>

int		main()
{
	using	namespace	std;

	char		c;

	while (cin.get(c) && c != '@')
	{
		if (isupper(c))
			c = tolower(c);
		else if (islower(c))
			c = toupper(c);
		cout << c << endl;
	}
	cout << c << endl;
	return (0);
}

