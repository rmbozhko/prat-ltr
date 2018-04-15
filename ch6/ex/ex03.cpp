#include <iostream>

using	std::cout;
using	std::endl;
using	std::cin;

bool		showmenu(void)
{
	cout << "c) carnivore\tp) pianist\nt) tree\tg) game" << endl;
	return (true);
}

int		main(void)
{
	char		c;

	showmenu();
	while (cin >> c)
	{
		switch (c)
		{
			case 'c':
				cout << "A maple is a carnivore." << endl;
				break ;
			case 'p':	
				cout << "A maple is a pianist." << endl;
				break ;
			case 't':
				cout << "A maple is a tree." << endl;
				break ;
			case 'g':
				cout << "A maple is a game." << endl;
				break ;
			default:
				cout << "Please enter a c, p, t or g: ";
		}
		if (c == 'c' || c == 'p' || c == 't' || c == 'g')
			showmenu();
	}
	return (0);
}
