#include <iostream>
#include <cstring>

bool		ft_is_vowels(int c)
{
	if ((c == 'A' || c == 'a')
	|| (c == 'E' || c == 'e')
	|| (c == 'I' || c == 'i')
	|| (c == 'O' || c == 'o')
	|| (c == 'U' || c == 'u'))
		return (true);
	return (false);
}

int		main(void)
{
	using	namespace	std;
	char		word[50];
	int		consonants;
	int		vowels;
	int		others;

	others = 0;
	consonants = 0;
	vowels = 0;
	cout << "Enter words to start(q for quit the program):\n";
	while (cin >> word && strcmp("q", word))
	{
		if (isalpha(word[0]))
		{
			if (ft_is_vowels(word[0]))
				vowels++;
			else
				consonants++;	
		}
		else
			others++;
	}
	cout << consonants << " words start with consonants." << endl;
	cout << vowels << " words start with vowels." << endl;
	cout << others << " words start with other chars." << endl;
	return (0);
}
