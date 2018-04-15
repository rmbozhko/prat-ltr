#include <iostream>
#include <string>
#include <fstream>

typedef struct	s_patrons
{
	std::string		fullname;
	double		donation;
}		t_patrons;

int		main(void)
{
	using	namespace	std;
	
	int		patrons_num;
	t_patrons	*patrons_arr;
	size_t		i;
	ifstream	input_file;

	input_file.open("info.txt");
	if (!input_file.is_open())
		return (EXIT_FAILURE);
	(input_file >> patrons_num).get();
	if (input_file.good())
	{
		i = 0;
		patrons_arr = new t_patrons[patrons_num];
		while (input_file.good() && i < patrons_num)
		{
			getline(input_file, patrons_arr[i].fullname);
			(input_file >> patrons_arr[i].donation).get();
			i++;
		}
		cout << "Patrons" << endl;
		for (int j = 0; j < i; j++)
		{
			if (patrons_arr[j].donation > 10000)
				cout << patrons_arr[j].fullname << " (Grand Patron)" << endl;
			else
				cout << patrons_arr[j].fullname << " (Patron)" << endl;
		}
		return (0);
	}
	return (EXIT_FAILURE);
}
