#include <iostream>
#include <string>
#include <cstring>

int		main(void)
{	
	using	namespace std;
	
	string	name;
	string	surname;
	string	result;	

	cout << "Enter your first name: ";
	getline(cin, name);
	cout << "Enter your last name: ";
	getline(cin, surname);
	
	result = surname + ", " + name;	
	cout << "Here's the information in a single string: " << result << endl;
	return (0);
}
