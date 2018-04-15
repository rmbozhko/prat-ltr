#include <iostream>

int		main(void)
{
	using	namespace	std;
	
	// Don't ever used goto. Its very bad style!!
	if (1)
		goto paris;	
	// Lots of code lien
	// .....
	// .....
	// .....
	if (0)
		paris: cout << "I am going to Paris\n";

	// Cycles for integer reading
	// value of varibale used as container for input will be changed to zero('0')
	// input will be left in queue
	// failbit will be set to '1' in 'cin' object
	// automatic 'cin' object to 'bool' casting will result 'false'
	int		n;
	char		c;

	n = 1;
	cout << "\'cin\' object to bool data type casting: " << bool(cin) << endl;
	cout << "n\'s value before reading: " << n << endl;
	cin >> n;
	cout << "n\'s value after reading: " << n << endl;
	cout << "EOF: " << cin.eof() << endl << "Fail: " << cin.fail() << endl;
	// we use clear() method here to allow cin.get() below to read the wrong type input
	// otherwise, it will return -1
	cin.clear();
	c = cin.get();
	cout << c << endl;
	c = cin.get();
	cout << c << endl;
	cout << "\'cin\' object to bool data type casting: " << bool(cin) << endl;
	
	const	int	max = 5;
	int		golf[max];
	double		total;

	cout << "Please, enter your golf scores.\n";
	cout << "You should enter " << max << " rounds.\n";
	for (int i = 0; i < max; i++)
	{
		cout << "Round #" << i + 1 << ": ";
		// if 'cin' object returns 'true' an inputted value is put into an array or variable
		// if 'cin' object returns 'false'(for example: reading char to int)
		// array or variable remain unchanged
		while (!(cin >> golf[i]))
		{
			cout << "Curr value: " << golf[i] << endl;
			// we use cin.clear() here to read the rest of input which is left in stdin
			// using cin.get() method
			cin.clear();
			while (c = cin.get())
			{
				cout << "Character:" << c << "|"<< endl;
				// sample string: 12lda 2
				// in case of new-line character we can push new numbers only in next line
				// example:
				// i = 12, i + 1 = (is waiting for input)
				// but in case of space, we can do this:
				// i = 12, i + 1 = 2
				// those chars(lda) are omitted by cycle we are currently in
				if (c == '\n')//' ')
					break ;
				else
					continue ;
			}
			cout << "Please, enter the numeric value: ";
		}
		cout << "Element #" << i << " -> "<< golf[i] << endl;
	}
	total = 0.0;
	for (int i = 0; i < max; i++)
		total += golf[i];
	cout << total / max << " = average score of " << max << " rounds.\n";


	// It is whole about reading
	// When we are reading any value, it is important to understand that we are reading chars
	// their data type is char, and then 'cin' automatically casts read values to
	// data types of recieving variables
	// To see proper, handling comment cins one-by-one
	// we have an input 38.5 19.2

	// in this case we only read one character and bufferize it
	char	ch;
	cin >> ch;
	cout << "Char: " << ch << endl;
	
	// in this case we only read 38, as '.'(dot) can't be part of int number,
	// and bufferize them as 51 56(ASCII)
	int	num;
	cin >> num;
	cout << "Int: "<< n << endl;


	// in this case we read 38.5, as ' '(space) cannot be a part of floating-point number
	// and bufferize them as 51 56, 46, 53(ASCII)
	double	x;
	cin >> x;
	cout << "Double: " << x << endl;

	// in this case we read to the space, newline or tabulation(we don't read them)
	char	word[50];
	(cin >> word).get();
	cout << word << endl;

	// in this case we read to newline character or till chars to read ends
	cin.getline(word, 50);
	cout << word << endl;
	// When assigning values to variables, we cast the read values to data types of receiving vars
	// if the read value ft_is_alpha character we got 'cin' object casted to 'false' otherwise 'true'
	return (0);
}
