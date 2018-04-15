#include <iostream>
#include <string>

// UNION data structure can store only one data type
// but can be accessed using multiple(int, long, double, float, bool ...)
// Mainly they are used when we have little memory space availiable
// We can specify counters for whole program using UNION
// And set their max values(like for bit fields in structures)
union	one4all {
	int	int_val;
	long	long_val;
	double	double_val;
};

struct	widget {
	char	brand[20];
	int	type;
	// Union can be part of structure
	// In this case all elems of "id" can be accessed using 'id_val' label
	union	id {
		long	id_num;
		char	id_char[20];
	}	id_val;
};

// Anonymus structure
struct {
	char	name[20];
	// anonymus union field
	// it has no label, its values are values of structure,
	// but share same memory space
	union	{
		int	id;
		long	score;
		double	avg_result;
	};
} anonymus = {
	"Mr. X", anonymus.id = 7
};

// Defining new user-specified data type 'spectrum'
// It holds values from '0' to '7'
enum	spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};

int		main(void)
{
	using	namespace std;
	
	one4all		temp;
	widget		prize;
	
	temp.long_val = 2147483548;
	cout << temp.long_val << endl;
	temp.int_val = 12; // BUT we have lost long_val
	cout << temp.int_val << endl;
	temp.double_val = 4.35; // BUT we have lost int_val
	cout << temp.double_val << endl;
	// Union size will be equal to size of largest element
	// In our case it is double -> 8 bytes
	cout << "Size of one4all union data structure: " << sizeof temp << endl;

	// Pushing union to structure and accessing it throw label 'id_val'
	prize.id_val.id_num = 1;
	prize.type = 15;
	cout << prize.type << endl << prize.id_val.id_num << endl;
	
	// Accessing anonymus structure with anonymus union field
	// As union has no label(it is anonymus)
	// we access its fields as fields of structure
	cout << anonymus.name << " has id: " << anonymus.id << endl;

	spectrum	band;

	band = blue; // allowed, blue is element of enum 'spectrum'
	cout << band << endl;
	//band = 2000; // not allowed, 2000 is not elem of enum 'spectrum'
	//band = 4; // not allowed, 4 is not elem of enum 'spectrum'
	band = spectrum(4); // allowed, through typecasting int to 'spectrum'
	cout << band << endl;

	// enum knows nothing about mathematical operations
	//cout << band++ << endl; // not allowed
	// But it can be used as a part of mathematical expression
	int	color;

	color = 5 + band;
	cout << color << endl;
	
	// elems of enum can be assigned to its data type, but
	// '+' operator knows nothing about 'spectrum' data type,
	// so it casts lvalue and rvalue to the default ENUM type -> int
	//band = orange + yellow; // not allowed
	// but if we typecast result of this expr to 'spectrum' type it's OK
	band = spectrum(orange + yellow);
	cout << band << endl;

	// If we'd like only to use defined elems of ENUM
	// we can omit declaring the name of ENUM
	enum {Pascal, C, Scala, Python, CPP, SQL, JS};
	cout << CPP << endl;

	// We can assign values to elems of enum
	// to make it starts from any number we want
	// we can assign values to all, some or none values
	enum bigstep {first, second = 100, third};
	
	cout << second << endl;
	// as it goes right after second(100), it gets previus_elem + 1
	cout << third << endl;
	
	// ENUM allows different elems have same values
	// C++ allows assining long, long long values to elems of ENUM
	enum {zero, null = 0, ein, numero_uno = 1};
	cout << zero << endl << null << endl << ein << endl << numero_uno << endl;
	
	// Allowed values assigning
	// The max allowed value of following enum to assing will be 15
	// 1 step: look for biggest num = 8 (2^3)
	// 2 step: take next two-squared number (2^(n + 1))
	// 3 step: substract 1 from gotten value
	// recieved value is the highest possible for your enum
	// same algo for smallest if less than zero
	// if equals or greater than zero, the smallest will be = '0'
	enum bits {one = 1, two = 2, four = 4, eight = 8};
	bits mybit = bits(6); // allowed, as '6' is among allowed values
	mybit = bits(15); // allowed, among values
	
	// possible, not allowed, greater than highest possible
	mybit = bits(16);
	cout << mybit << endl;

	return (0);
}
