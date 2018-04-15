#include <iostream>

int		main(void)
{
	using		std::cout;
	using		std::cin;
	using		std::endl;

	int		lines_num;

	cout << "Enter number of lines: ";
	cin >> lines_num;
	for (int i = 0; i < lines_num; i++)
	{
		for (int k = lines_num - (i + 1); k > 0; k--)
			cout << '.';
		for (int j = i + 1; j > 0; j--)
			cout << '*';
		for (int j = i + 1; j > 0; j--)
			cout << '*';
		for (int k = lines_num - (i + 1); k > 0; k--)
			cout << '.';
		cout << endl;
	}
	return (0);
}
