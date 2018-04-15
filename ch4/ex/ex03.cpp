#include <iostream>
#include <cstring>

int		main(void)
{
	using	namespace std;
	
	char	name[80];
	char	surname[80];
	char	*result;	

	cout << "Enter your first name: ";
	cin.get(name, sizeof name).get();
	cout << "Enter your last name: ";
	cin.get(surname, sizeof surname).get();
	
	result = new char[strlen(name) + strlen(surname) + 3];
	strcpy(result, surname);
	strcat(result, ", ");
	strcat(result, name);
	
	cout << "Here's the information in a single string: " << result << endl;
	delete []result;
	return (0);
}
