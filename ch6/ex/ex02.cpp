#include <iostream>
#include <array>

int		main(void)
{
	using	namespace	std;

	array<double, 10>	donations;
	double			value;
	unsigned		i;
	double			avg;
	unsigned		j;

	i = 0;
	avg = 0;
	while (cin >> value)
	{
		donations[i++] = value;
		avg += value;
	}
	if (i > 1)
	{
		avg /= i;
		cout << "Average of gotten numbers: " << avg << endl;
		for (int k = j = 0; k < i; k++)
		{
			if (donations[k] > avg)
				j++;
		}
		cout << "Number of inputted values, which exceed the avg of set: " << j << endl;
		return (0);
	}
	return (1);
}
