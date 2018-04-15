#include <iostream>
#include <string>

struct	car
{
	std::string		vendor;
	unsigned		production_year;
};

int		main(void)
{
	using	namespace	std;

	int		auto_num;
	//car		**car_arr;
	
	cout << "Enter number of automobiles to be included into catalog: ";
	cin >> auto_num;
	
	//car_arr = (car**)malloc(sizeof(car*) * auto_num);
	
	car	*car_arr[auto_num]; //= new car[auto_num];
	for (int i = 0; i < auto_num; i++)
	{
		car		*car_temp;
	
		car_temp = new car;
		cout << "Automobile #" << i + 1 << ":" << endl;
		cout << "Enter vendor\'s name: ";
		cin.get();
		getline(cin, car_temp->vendor);
		cout << "Enter year of production: ";
		cin >> car_temp->production_year;
		car_arr[i] = car_temp;
	}
	cout << "Your catalog Inhalt:\n";
	for (int i = 0; i < auto_num; i++)
	{
		cout << car_arr[i]->production_year << " ";
		cout << car_arr[i]->vendor << endl;
	}

	//delete []car_arr;
	return (0);
}
