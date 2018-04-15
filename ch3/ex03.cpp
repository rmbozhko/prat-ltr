#include <iostream>

int		main(void)
{
	using		namespace std;
	const	double	secs_in_min = 60;
	const	double	mins_in_degr = 60;
		
	// to use auto specify -std=c++11
	auto		degr = 0;
	auto		mins = 0;
	auto		secs = 0;
	
	cout << "Enter a latitude in degrees, minutes and seconds: " << endl << "First, enter the degrees: ";
	cin >> degr;
	cout << "Next, enter the minutes of arc: ";
	cin >> mins;
	cout << "Finally, enter the seconds of arc: ";
	cin >> secs;
	double res = degr + mins / mins_in_degr + ((secs / secs_in_min) / mins_in_degr);
	cout << degr << " degrees, " << mins << " minutes, " << secs << " seconds = " <<
	res << " degrees" << endl;
	return (0);
}
