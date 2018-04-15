#include <iostream>
#include <fstream>

int		main(void)
{
	using	namespace	std;

	unsigned	chars_num;
	char		c;
	ifstream	input_file;
	ofstream	output_file;
	char		file[50];

	chars_num = 0;
	cout << "Enter file to read from: ";
	cin >> file;
	input_file.open(file);
	cout << "Enter file where to write: ";
	cin >> file;
	output_file.open(file);
	while (input_file >> c)
	{
		chars_num++;
	}
	cout << "Number of read chars: " << chars_num << endl;
	output_file << "Number of read chars: " << chars_num << endl;
}
