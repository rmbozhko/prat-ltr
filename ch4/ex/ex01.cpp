#include <iostream>

int		main(void)
{
	using	namespace std;
	
	char	grade;
	char	name[80];
	char	surname[80];
	int	age;
	
	cout << "What is your first name? ";
	cin.getline(name, sizeof name);
	cout << "What is your last name? ";
	cin.get(surname, sizeof surname).get();
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << surname << ", " << name << endl;
	cout << "Grade: " << char(grade + 1) << endl;
	cout << "Age: " << age << endl;
	return (0);
}
