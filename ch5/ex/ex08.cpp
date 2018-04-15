#include <iostream>
#include <cstring>


int		main(void)
{
	using	namespace	std;

	char		word[999];
	unsigned	counter;

	cout << "Enter words (for quit type \"done\")" << endl;
	cin >> word;
	counter = 0;
	while (!cin.fail() && strcmp(word, "done"))
	{
		counter++;
		cin >> word;
	}
	cout << "You entered " << counter << " words." << endl;
	return (0);
}
