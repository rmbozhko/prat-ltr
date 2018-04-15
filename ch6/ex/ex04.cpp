#include <iostream>
#include <fstream>

using	namespace	std;

const	unsigned	strsize = 50;
const	unsigned	members_num = 3;

struct	bop
{
	char	fullname[strsize];
	char	title[strsize];
	char	bopname[strsize];
	int	preference;
};

bop		*ft_get_bops_memebrs_info(char *filename)
{	
	bop		*bop_arr;
	ifstream	input_file;	

	input_file.open(filename);
	bop_arr = new bop[members_num];
	for (int i = 0; i < members_num; i++)
	{
		input_file.get(bop_arr[i].fullname, sizeof bop_arr[i].fullname).get();
		input_file.get(bop_arr[i].title, sizeof bop_arr[i].title).get();
		input_file.get(bop_arr[i].bopname, sizeof bop_arr[i].bopname).get();
		input_file >> bop_arr[i].preference;
		cout << input_file.good() << endl;
		input_file.get();
		input_file.get();
		if (!input_file.good())
			input_file.clear();
		cout << input_file.good() << endl;
	}
	input_file.close();
	return (bop_arr);
}

void		ft_show_menu(void)
{
	cout << "Benevolent Order of Programmers Report\n";
	cout << "a. display by name\tb. display by title\n"
		"c. display by bopname\td. display by preference\n"
		"q. quit\n";
	cout << "Enter your choice: ";
	
}

void		ft_display_name(bop *data)
{
	for (int i = 0; i < members_num; i++)
		cout << data[i].fullname << endl;
}

void		ft_display_title(bop *data)
{
	for (int i = 0; i < members_num; i++)
		cout << data[i].title << endl;
}

void		ft_display_bopname(bop *data)
{
	for (int i = 0; i < members_num; i++)
		cout << data[i].bopname << endl;
}

void		ft_display_preference(bop *data)
{
	for (int i = 0; i < members_num; i++)
	{
		if (data[i].preference == 0)
			cout << data[i].fullname << endl;
		else if (data[i].preference == 1)
			cout << data[i].title << endl;
		else if (data[i].preference == 2)
			cout << data[i].bopname << endl;
		else
			cout << "Wrong preference num.(0-2)" << endl;
	}
}

int		main(void)
{	
	char		c;
	char		filename[50];
	bop		*data;	

	(cin >> filename).get();
	data = ft_get_bops_memebrs_info(filename);
	ft_show_menu();
	while (cin.get(c) && c != 'q')
	{
		switch (c)
		{
			case 'a':
				ft_display_name(data);
				break ;
			case 'b':
				ft_display_title(data);
				break ;
			case 'c':
				ft_display_bopname(data);
				break ;
			case 'd':
				ft_display_preference(data);
				break ;
			default:
				cout << "Wrong input, try again." << endl;
		}
		cin.get();
	}
	delete []data;
	return (0);
}
