#include <iostream>

int		main(void)
{
	using	namespace	std;
	
	int		start;
	int		end;
	int		sum;

	sum = 0;
	cout << "Enter the start int: ";
	cin >> start;
	cout << "Enter the end int: ";
	cin >> end;

	for (int i = start; i <= end; i++)
		sum += i;
	cout << "The sum of numbres, which are between two specified: ";
	cout << sum << endl;
	return (0);
}
