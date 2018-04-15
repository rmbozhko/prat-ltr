#include <iostream>
#include <string>

using	std::string;

struct	inflatable
{
	char	name[30];
	float	volume;
	double	price;
	// if compiler isn't very old and std namespace is being used
	// then we can declare string(and other things:vector)
	// as fields of structure
	string	surname;
};

/* // As the result we can look into position variable as it has no struct label
void		ft_display_str_fields(position)
{	
	cout << position.x << endl;
	cout << position.y << endl;
}*/

int		main(void)
{
	using	namespace std;
	// In C++11 you do not need to write struct keyword when declaring var.
	struct inflatable	temp_c; // C-like approach
	inflatable		temp_cpp;

	inflatable		guest = {
			"Glorious Gloria",
			1.88,
			29.99
		};
	inflatable		pal = {
			"Audacious Arthur",
			3.12,
			32.99
		};
	
	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $" << guest.price + pal.price << "!\n";
	
	// C++11-like defining, without '='
	inflatable		duck {"Daphne", 0.12, 9.98};
	//C++11-like defining, bzeroing all fields of structure
	inflatable		mayor {};
	//C++11-like defining doesn't allow values bigget than declared
	// !!Error!!!
	//inflatable		temp {"ABCDEFGHIJKLMNOPQRSTUVWXYZLOLKECKCHEBURECK"};

	// We can assign structure variable to another structure variable
	// This is called field copying, as each field(even arrays) copy each elm to other variable
	cout << "Duck\'s name: " << duck.name << endl;
	cout << "Mayor\'s name: " << mayor.name << endl;
	cout << "Assigning duck to mayor ..." << endl;
	mayor = duck;
	cout << "After assigning" << endl;
	cout << "Duck\'s name: " << duck.name << endl;
	cout << "Mayor\'s name: " << mayor.name << endl;

	// We can also declare local structure
	// Also we can declare instance of structure just after its definition
	// Besides we can even initialize some instances
	struct		perks
	{
		// As in C, in C++ we can specify number of bites used by field
		// Mainly bit fields are used to match register in some microcontrollers or devices with small amount of internal memory
		// To use bit field the field must be int, short, unsigned, char
		int	key : 5; // field(key) takes five bits(max value: 31)
		char	car[15];
	} mr_smith, ms_smith = {
		7,
		"Packard"
	};
	// As we can see both variables are created
	// One: bzeroed, another one: initialized
	cout << "Mr. Smith car: " << mr_smith.car << endl;
	cout << "Ms. Smith car: " << ms_smith.car << endl;

	// If we are confident that we will have only one instance of structure
	// We can do following:
	struct
	{
		int	x;
		int	y;
	} position;
	// This will create only one instance of such form and will be unavaible for the rest of program execution
	// Best way to use this feature is to create one global instance of some structure, like valid(Filler, Corewar) or farmer(Lem-in)
	//ft_display_str_fields(position);
	
	// We can initialize arrays of structures
	perks		s_arr[2] = {
		{8, "Pegeout"},
		{10, "Ferarri"}
	};
	cout << "Zero s_arr index = " << s_arr[0].key << ":" << s_arr[0].car << endl;
	cout << "First s_arr index = " << s_arr[1].key << ":" << s_arr[1].car << endl;
	return (0);
}
