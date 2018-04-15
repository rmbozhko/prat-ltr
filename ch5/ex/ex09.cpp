#include <iostream>
#include <cstring>
#include <string>

int		main(void)
{
	using	namespace	std;

	string		word;
	unsigned	counter;

	cout << "Enter words (for quit type \"done\")" << endl;
	cin >> word;
	counter = 0;
	while (!cin.fail() && word != "done")
	{
		counter++;
		cin >> word;
	}
	cout << "You entered " << counter << " words." << endl;
	return (0);
}
