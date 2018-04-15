#include <iostream>
#include <cstring>
#include <string>

using	namespace	std;

/* The main thing here to learn is that EOF isn't a symbol or whatever visible
* it's a flag, a signal that it is impossible to read futher
*/

int		main()
{
	// When cin reveals EOF, it settles two bits: eofbit and failbit = 1
	// to check whether eofbit == 1 use cin.eof(), which returns true in case of EOF or false
	// to check both eofbit and failbit use cin.fail()
	// it returns true if eofbit == 1 || failbit == 1
	// So, it works with more cases
	// But both this methods inform about last reading session,
	// so they show be used after cin >> var_name || var_name = cin.get() || cin.get(var_name)
	int		count;
	char		ch;

	count = 0;
	// we read one char here to determine whether it's EOF or we can continue reading
	cin.get(ch);
	// cin.fail() and cin.eof() can be invoked only after at least 1 reading process
	while (!cin.fail())
	{
		cout << ch;
		count++;
		cin.get(ch);
	}
	cout << "Characters read: " << count << endl;
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	// We have read enough text and want to move on to cin.getline()
	// but once we are there we are not able to read as eofbit and failbit are set
	// but we can make them both again = 0 and read further using method of object cin.clear()
	cin.clear();
	// but be aware that some OS hesitate cin.clear() invoking,
	// so Ctrl+Z will stop reading completely
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	const	int	arr_size = 20;
	char	arr[arr_size];
	cin.getline(arr, arr_size);
	cout << arr << endl;

	// As far as we know cin.get(char) returns cin object
	// this object is casted automatically in certain circumstances(if, else if, while, for) 
	// to 'true' if it hasn't reached EOF or to 'false' if EOF is reached
	// or smth happened on lower levels(disk reading error, file permission)
	// that is why this type of checking is better than binary cin.fail() check!
	while (cin.get(ch))
	{
		cout << "OOP reading approach." << endl;
		cout << ch;
	}
	cout << endl;
	cout << "EOF ASCII code: " << EOF << endl;
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	cin.clear();
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	
	// ch = cin.get()
	// in this case get() method return ASCII code of read char and assign to lvalue
	// if EOF is met EOF constant is returned and loop broke down
	while ((ch = cin.get()) != EOF)
		cout << "[char]Procedure reading approach.\n" << ch << endl;
	
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	cin.clear();
	cout << "FAILBIT: " << cin.fail() << "\nEOFBIT: " << cin.eof() << endl;
	// in some OS 'char' == 'unsigned char', so -1 will never be assigned to such variable
	// so use 'int' to assign the returned value and cast in to 'char' while cout << char(var)
	int		num;
	while ((num = cin.get()) != EOF)
		cout << "[int]Procedure reading approach.\n" << char(num) << endl;
	

	// Resume workout	
	int	x = (1, 024);
	cout << x << endl;	
	int	y = (x = 1, x + 1);
	cout << x << endl << y << endl;	
	
	return (0);
}

