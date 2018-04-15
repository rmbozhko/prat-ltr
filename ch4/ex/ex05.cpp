#include <iostream>

struct	CandyBar
{
	char		kind[80];
	float		weight;
	unsigned	calories_num;	
};

int		main(void)
{
	using		namespace std;

	CandyBar	snack = {"Mocha Munch", 2.3, 350};
	cout << "Name of CandyBar instance: " << snack.kind << endl;
	cout << "Its weight: " << snack.weight << endl;
	cout << "Number of calories: " << snack.calories_num << endl;
	return (0);
}
