#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int		main(void)
{
	using		std::fixed;
	using		std::ios_base;
	using		std::cerr;
	using		std::cin;
	using		std::cout;
	using		std::endl;
	using		std::string;
	using		std::ifstream;
	using		std::ofstream;
	using		std::exit;

	string		filename;
	ifstream	input_file;
	int		counter;
	double		value;
	double		sum;
	
	cout << "Enter filename to read data from: ";
	getline(cin, filename);
	input_file.open(filename);
	
	if (!input_file.is_open())
	{
		cerr << "Couldn\'t open the file with following filename: " << filename << endl;
		return (EXIT_FAILURE);
	}
	counter = 0;
	value = 0.0;
	sum = value;
	while (input_file >> value)
	{
		counter++;
		sum += value;
	}
	// the iostream and fstream method good() checks
	if (!input_file.good())
	{
		if (input_file.eof())
			cout << "File reading cycle reached EOF.";
		else if (input_file.fail())
			cout << "File reading crashed due to input data type.";
		else
			cout << "Unknown error.";
	}
	else
		cout << "\n\n\nWHAT?!?!?!?!? WTF??!?!?!?!";
	cout << endl;
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Total number of elems in file: " << counter << endl;
	cout << "The sum of those elems: " << sum << endl;
	cout.precision(4);
	cout << "The average of those elems: " << sum / counter << endl;
	return (0);
}
