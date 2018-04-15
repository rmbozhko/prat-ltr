#include <iostream>
#include <array>

using	std::endl;
using	std::cin;
using	std::cout;
using	std::array;

int		main(void)
{
	array<unsigned, 3> records;
	
	cout << "First lap record: ";
	cin >> records[0];
	cout << "Second lap record: ";
	cin >> records[1];
	cout << "Third(final) lap record: ";
	cin >> records[2];
	cout << "Avg. of 3 laps: " << (records[0] + records[1] + records[2]) / 3;
	cout << endl;
	return (0);
}

