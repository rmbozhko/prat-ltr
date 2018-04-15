#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char *Snames[] = {"Spring", "Summer", "Fall", "Winter"};

struct	expenses
{
	double	*expenses;
};

void fill(expenses *pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> (pa->expenses)[i];
	}
}

void show(const expenses *pa)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << (pa->expenses)[i] << endl;
		total += (pa->expenses)[i];
	}
}

int main()
{
	expenses *year = new expenses;
	year->expenses = new double[Seasons];

	fill(year);
	show(year);
	delete []year->expenses;
	delete year;
	return 0;
}

