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
	Pizza		*temp;

	temp = new Pizza;
	cout << "Enter diameter of pizza, please: ";
	(cin >> temp->diameter).get();
	cout << "Enter name of pizza, please: ";
	cin.get(temp->name, sizeof temp->name).get();
	cout << "Enter weight of pizza, please: ";
	cin >> temp->weight;
	cout << "Name: " << temp->name << endl;
	cout << "Diameter: " << temp->diameter << endl;
	cout << "Weight: " << temp->weight << endl;
	cout << "Address of allc. memory for struct ptr: " << &temp << endl;
	cout << "Address of allc. memory for struct: " << temp << endl;

	delete	temp;
	return (0);
}
