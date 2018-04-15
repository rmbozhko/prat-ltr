#include <iostream>
#include <cstring>

struct	CandyBar
{
	char		kind[80];
	float		weight;
	unsigned	calories_num;	
};

int		main(void)
{
	using	namespace std;
	
	CandyBar	*trio;

	trio = new CandyBar[3];
	strcpy(trio[0].kind, "Milkieway");
	trio[0].weight = 2.2;
	trio[0].calories_num = 330;
	strcpy(trio[1].kind, "Roshen");
	trio[1].weight = 1.8;
	trio[1].calories_num = 270;
	strcpy(trio[2].kind, "Rottshen");
	trio[2].weight = 2.4;
	trio[2].calories_num = 410;
	
	cout << "Name of CandyBar instance: " << trio[0].kind << endl;
	cout << "Its weight: " << trio[0].weight << endl;
	cout << "Number of calories: " << trio[0].calories_num << endl;
	
	cout << "Name of CandyBar instance: " << trio[1].kind << endl;
	cout << "Its weight: " << trio[1].weight << endl;
	cout << "Number of calories: " << trio[1].calories_num << endl;
	
	cout << "Name of CandyBar instance: " << trio[2].kind << endl;
	cout << "Its weight: " << trio[2].weight << endl;
	cout << "Number of calories: " << trio[2].calories_num << endl;
	
	delete []trio;
	return (0);
}
