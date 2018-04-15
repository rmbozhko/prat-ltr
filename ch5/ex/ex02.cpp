#include <iostream>
#include <array>

int		main(void)
{
	using	namespace	std;
	
	const	int			fac_size = 101;
	array<long double, fac_size>	ld_arr;

	ld_arr[0] = ld_arr[1] = 1.0L;
	for (int i = 2; i < fac_size; i++)
	{
		ld_arr[i] = i * ld_arr[i - 1];
		cout << i << "! = " << ld_arr[i] << endl;
	}
	return (0);
}
