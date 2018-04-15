#include <iostream>

int		main(void)
{
	using	namespace std;

	const auto	secs_in_minute = 60;
	const auto	secs_in_hour = 60 * secs_in_minute;
	const auto	secs_in_day = secs_in_hour * 24;
	unsigned long	total_secs;
	int		result;

	cout << "Enter the number of seconds: ";
	cin >> total_secs;
	result = total_secs / secs_in_day;
	cout << total_secs << " seconds = " << result;
	total_secs -= (secs_in_day * result);
	result = total_secs / secs_in_hour;
	cout << " days, " << result << " hours, ";
	total_secs -= (secs_in_hour * result);
	result = total_secs / secs_in_minute;
	cout << result << " minutes, ";
	total_secs -= (result * secs_in_minute);
	cout << total_secs << " seconds" << endl;
	return (0);
}
