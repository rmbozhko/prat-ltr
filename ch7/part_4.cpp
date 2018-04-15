#include <iostream>
#include <cmath>
#include <string>

// 1st arg of function is pointer to an array with 3 elements(ptr to bidarr)
// and we have num of columns by default: 3 and we got num of rows with second element
void		ft_display_bidarr_with_3_cols(int (*arr)[3], int arr_len)
{
	using		std::cout;
	using		std::endl;

	for (int i = 0; i < arr_len; i++)
	{
		cout << "Element #" << i + 1 << endl;
		for (int j = 0; j < 3; j++)
			cout << "Sub-element #" << i + 1 << ": " << arr[i][j] << endl;
	}
}

char		*ft_build_str(char c, unsigned len)
{
	char		*temp;

	temp = new char[len * sizeof (char) + 1];
	temp[len] = '\0';
	while (len-- > 0)
		temp[len] = c;
	return (temp);
}

unsigned	ft_strlen(const char *const str)
{
	unsigned	i;

	while (str[i])
		i++;
	return (i);
}

struct	travel_time
{
	int	hours;
	int	mins;
};

travel_time	sum(travel_time t1, travel_time t2)
{
	using	std::cout;
	using	std::endl;
	
	travel_time	total;
	
	total.mins = (t1.mins + t2.mins) % 60;
	total.hours = (t1.hours + t2.hours) + (t1.mins + t2.mins) / 60;
	return (total);
}

void		show_time(travel_time t)
{
	using	std::cout;
	using	std::endl;
	
	cout << t.hours << " hours, " << t.mins << " ,mimutes." << endl;
}

struct		polar
{
	double		distance;
	double		angle;
	polar() { std::cout << "\n\n\n\tWE ARE YOUNG!!\n\n\n"; }
	polar(const polar&) {std::cout << "\n\n\n\tOLOLOLOLOLOLO!\n\n\n\n"; }
};

struct		rect
{
	double		x;
	double		y;
};

void		show_polar(polar *dapos)
{
	using		std::cout;
	using		std::endl;

	const	double		rad_to_deg = 57.29577951;
	cout << "Distance = " << dapos->distance;
	cout << ", angle = " << dapos->angle * rad_to_deg << " degrees." << endl;
}

polar		rect_to_polar(rect *xypos)
{
	polar		answer;

	answer.distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
	// determine angle between 2 points
	answer.angle = atan2(xypos->y, xypos->x);
	// he we are returning copy of structure, such behaviour depends on compiler realisation
	// one can return copy. while other not, read about it RVO wikipedia
	return (answer);
}

void		display_bid_string_arr(const std::string sarr[], unsigned len)
{
	using	std::cout;
	using	std::endl;

	for (int i = 0; i < len; i++)
		cout << sarr[i] << " : " << sarr[i].size() << endl;
}

int		main(void)
{
	using		namespace	std;

	// array of pointers with len = 2
	int		*arr[2];
	// two dimensional array with 2 columns
	int		bidarr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int		num = 5;

	arr[1] = &num;
	*arr[1] = 10;
	cout << num << endl;
	cout << (*arr[1]) << endl;
	ft_display_bidarr_with_3_cols(bidarr1, 2);
	int		bidarr2[5][3] {{12, 142, 323}, {546, 857, 776}, {121, 1, 0}, {20, 90, 102}, {86, 12, 456}};
	ft_display_bidarr_with_3_cols(bidarr2, 5);

	char		*c_ptr;
	
	c_ptr = ft_build_str('V', 46);
	cout << c_ptr << endl;
	delete []c_ptr;
	c_ptr = ft_build_str('-', 20);
	cout << c_ptr << "+NULL+" << c_ptr << endl;
	delete []c_ptr;
	
	
	travel_time	day1 {5, 45};
	travel_time	day2 {4, 55};
	travel_time	trip = sum(day1, day2);
	trip.mins = 10;
	trip = day2;
	show_time(trip);

	rect	rplace;
	polar	pplace;

	cout << "Enter values of coordinates x and y: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(&rplace);
		show_polar(&pplace);
		cout << "Enter new values again:(q for quiting)";
	}
	cout << "Done\n" << endl;
	if (!cin.good())
	{
		char		c;

		cin.clear();
		while ((c = cin.get()) && c != '\n' && c >= 0)
			continue ;
	}
	// exactly as char arrays we may also have arrays of string-s
	// as string data type is array itself, creating array of string is two-dimensional array
	const	int	sarr_len = 5;
	string		str_arr[sarr_len];

	for (int i = 0; i < sarr_len; i++)
		getline(cin, str_arr[i]);
	display_bid_string_arr(str_arr, sarr_len);
	return (0);
}
