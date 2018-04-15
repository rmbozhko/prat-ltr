#include <iostream>

int		main(void)
{
	using	namespace std;
	char	grade;
	string	name;
	string	surname;
	int	age;
	
	cout << "What is your first name? ";
	getline(cin, name);
	cout << "What is your last name? ";
	getline(cin, surname);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << surname << ", " << name << endl;
	cout << "Grade: " << char(grade + 1) << endl;
	cout << "Age: " << age << endl;
	return (0);
}
