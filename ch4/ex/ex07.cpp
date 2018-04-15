#include <iostream>

struct	Pizza
{
	char		name[240];
	float		diameter;
	unsigned	weight;
};

int		main(void)
{
	using	namespace	std;
	Pizza		temp;

	cout << "Enter name of pizza, please: ";
	cin.get(temp.name, sizeof temp.name).get();
	cout << "Enter diameter of pizza, please: ";
	cin >> temp.diameter;
	cout << "Enter weight of pizza, please: ";
	cin >> temp.weight;
	cout << "Name: " << temp.name << endl;
	cout << "Diameter: " << temp.diameter << endl;
	cout << "Weight: " << temp.weight << endl;
	
	return (0);
}
