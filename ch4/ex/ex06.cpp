#include <iostream>

struct	CandyBar
{
	char		kind[80];
	float		weight;
	unsigned	calories_num;	
};

int		main(void)
{
	using	namespace std;
	
	CandyBar	trio[3] = {
		{"Milkieway", 2.2, 330},
		{"Roshen", 1.8, 270},
		{"Rottshen", 2.4, 410}
	};
	
	cout << "Name of CandyBar instance: " << trio[0].kind << endl;
	cout << "Its weight: " << trio[0].weight << endl;
	cout << "Number of calories: " << trio[0].calories_num << endl;
	
	cout << "Name of CandyBar instance: " << trio[1].kind << endl;
	cout << "Its weight: " << trio[1].weight << endl;
	cout << "Number of calories: " << trio[1].calories_num << endl;
	
	cout << "Name of CandyBar instance: " << trio[2].kind << endl;
	cout << "Its weight: " << trio[2].weight << endl;
	cout << "Number of calories: " << trio[2].calories_num << endl;
	
	return (0);
}
