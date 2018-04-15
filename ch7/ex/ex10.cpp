#include <iostream>

using	namespace	std;

double		ft_add(double x, double y)
{
	return (x + y);
}

double		ft_substract(double x, double y)
{
	return (x - y);
}

double		ft_multiply(double x, double y)
{
	return (x * y);
}

double		ft_divide(double x, double y)
{
	return (x / y);
}

double		ft_calculate(double x, double y, double(*ft)(double, double))
{
	return ((*ft)(x, y));
}

int		main(void)
{
	typedef	double (*ft_math_instr)(double, double);

	ft_math_instr temp[4] = {ft_add, ft_substract, ft_multiply, ft_divide};
	double		x;
	double		y;
	auto temp_ptr = &temp;
	ft_math_instr lol[4] = {ft_divide, ft_multiply, ft_substract, ft_add};
	
	//ft_math_instr (*bidarr[2])[4] = {&temp, &temp};
	// The line above won't work as when i = 0 everything is ok,
	// there is no point to hurry as bidarr points to address of array 'temp' but then
	// when i = 1 it is expected to move somewhere but the second argument has same address as the first one
	// like we are expected to leave curr address, but we can't as second arg is located on this mem space
	// !!!!!NONSENCE!!!!!!!
	// But the line below will work perfectly fine as first arg is located on address x and second on address y
	// We have a right to move somewhere else, like from 0x00 to 0x01
	ft_math_instr (*bidarr[2])[4] = {&temp, &lol};
	ft_math_instr (*(*bidarr_ptr)[2])[4] = &bidarr;
	cout << "Enter x and y values: ";
	while (cin >> x >> y)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 4; j++)
			{
				// while writing a question on stackoverflow
				// use as additioanal example char bidarr
				cout << sizeof bidarr << endl;
				cout << sizeof *bidarr << endl;
				cout << sizeof (*bidarr[i]) << endl;	
				cout << &(bidarr) << endl << endl;	
				cout << &(*bidarr) << endl << endl;	
				cout << &(*bidarr[i]) << endl << endl;	
				//cout << &(*bidarr[i][j]) << endl << endl;	
				cout << (*(*bidarr[i][j]))(x, y) << endl;	
			}
		cout << "Enter x and y values: ";
	}	
	return (0);
}
