#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>

int		main(void)
{
	using	namespace std;

	int		*iptr;
	int		val;

	val = 6;
	iptr = &val;
	cout << "Val address using variable \'val\': " << &val << endl;
	cout << "Val address using pointer \'iptr\': " << iptr << endl;

	char		*str;
	double		*dptr;

	// Even if all pointers points to different data types:
	// str -> char
	// dptr -> double
	// iptr -> int
	// All of pointers varibales have same size
	cout << "Size of char pointer: " << sizeof str << endl;
	cout << "Size of double pointer: " << sizeof dptr << endl;
	cout << "Size of int pointer: " << sizeof iptr << endl;
	
	cout << "Address of char pointer: " << &str << endl;
	cout << "Address of double pointer: " << &dptr << endl;
	cout << "Address of int pointer: " << &iptr << endl;

	// We may recieve garbadge, as two of three pointers are not initialized
	// The following two cout-s cause Seg. faults 
	//cout << "Value of char pointer: " << str << endl; // garbidge
	//cout << "Value of double pointer: " << dptr << endl; // garbidge
	cout << "Value of int pointer: " << iptr << endl;

	// Pointers should be used very careful
	long	*fellow;
	// Very-very bad!!!! Where did you assign '223323' ?
	// It could be another varibale address from your program
	// or some OS running inforamtion
	// You have allocated place for pointer, not for its value
	//*fellow = 223323; // Very bad approach!!
	// You should also allocate memory for pointer value
	// Allocating memory in heap for value
	
	// C-like memory allocating
	fellow = (long*)malloc(sizeof(long));
	// Setting value (fellow contains address of memory as value) in RAM
	*fellow = 223323; // Correct approach
	cout << "C-like approach: " << *fellow << endl;	
	
	// C++-like memory allocating
	// If 'new' cannot allocate memory it generates exception
	// Some time ago it returned NULL-pointer, just like in C
	dptr = new double; // (223323);
	*dptr = 223.0;
	cout << "C++-like approach: " << *dptr << endl;
	
	// Pointers are not int-like data types,
	// although they contains int-like values (addresses)

	// dptr = 0xB8000000; // was allowed in C, before C99
	// allowed, if casted to pointer data type
	//dptr = (double*)0x7ffd8845f; // allowed
	//cout << *dptr << endl; // Seg fault
	// invalid, static_cast is more safer(restrictiver) type of casting
	// dptr = static_cast<double*> (0xB8000000); // not allowed

	// To free allocated memory use 'delete'
	// if new returned NULL-pointer and 'delete' that memory it's safe
	long	*lptr;

	lptr = fellow;
	delete lptr;
	delete dptr;
	cout << "Deleted heap memory pointers output:" << endl;
	cout << *lptr << endl << *dptr << endl;

	// Allocating memory for an array
	int	*iparr;
	
	iparr = new int[10]; // allocating 10 cells, each - 4 bytes long
	delete []iparr; // delete whole array, with its cells
	//delete iparr; // undefined behavior, do not use this
	//delete []fellow; // undefined behavior, do not use this

	double	*dp_array;

	dp_array = new double[3];
	dp_array[0] = 0.2;
	dp_array[1] = 0.5;
	dp_array[2] = 0.8;
	
	cout << "Array first elem: " << dp_array[0] << endl;
	cout << "Moving pointer ..." << endl;
	dp_array += 1;
	cout << "Array first elem: " << dp_array[0] << endl;
	// returning to previous place as smth might go wrong while delete[]
	dp_array -= 1; // try to comment and observe 'Aborted'
	delete []dp_array;

	// Pointer arithmetic
	char		name[20] = "Roman";
	char		*surname;

	//name = "Roman"; //not allowed, reassigning of const array is forbidden
	surname = (char*)malloc(sizeof(char) * 20 + 1);
	strcpy(surname, "Bozhko");
	cout << name << " " << surname << endl;
	delete surname;	
	
	// How first elem addr and array addr differs?
	short			tell[10];

	tell[0] = 55;
	// this is addr of 2-bytes memory segment
	cout << tell << endl;
	// this is addr of 20-bytes memory segment
	cout << &tell << endl;
	// here we go to the next elem of an array
	// each elem of an array takes 2 bytes,
	// to get to next one we move pointer two bytes further
	cout << tell + 1 << endl;
	// here we go to the next block of 20-bytes memory segment
	cout << &tell + 1 << endl;
	// So, addr of first elem maybe same as addr of an array
	// but moving ptr (ptr + 1) will result in different locations

	// it's a pointer to short array, which has 10 elems
	// it's a pointer to 20-bytes memory segment
	short		(*lol)[10] = &tell;
	cout << *lol[0] << endl;

	// Getting addr of value char* is pointing
	char		city[20] = "Big City Life";
	char		*c_ptr;
	
	c_ptr = city;
	cout << "COUT handle char* pointer like a value: " << c_ptr << endl;
	cout << "To get addr where char* pointer is pointing use typecast: " << (int*)c_ptr << endl;

	// Working with structure dynamic allocating
	struct	inflatable
	{
		char	name[20];
		float	volume;
		double	price;
	};
	// pointer to structure initializing
	// allocating memory segment sufficient for holding
	// all fields of inflatable structure
	inflatable	*ps = new inflatable;
	
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);
	cout << "Enter volume in cubic feet: ";
	// We use .(dot), as we dereference a pointer to a structure
	// so currently we work with structure instance itself,
	// which has allocated memory segment somewhere in heap
	cin >> (*ps).volume;
	cout << "Enter price: ";
	cin >> (*ps).price;
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << endl;
	cout << "Price: " << ps->price << endl;
	delete ps;


	// Working with char* dynamic memory allocating
	// Allocate memory for char* in heap
	char		temp[] = "LOLITA";
	char		*lolita = new char[strlen(temp) + 1];
	
	// Assign memory segment, which lol is pointing to value: "LOL"
	strcpy(lolita, temp);
	cout << "Value: " << temp << ", address in stack: " << &temp << endl;
	cout << "Value: " << lolita << ", address in heap: " << (int*)lolita << endl;
	cout << "First Value: " << *(lolita + 1) << ", address in heap: " << (int*)(lolita + 1) << endl;

	delete []lolita;

	// Vector quick overview
	// Allocates memory in heap(using new) by itself
	using 	std::vector;
	
	// creating vector-array with len = 0
	vector<int> vi;
	int	n;
	cin >> n;
	// creating vector-array with len = n
	// n can be varibale or constant
	vector<double> vd(n);
	vector<char*> vcptr(n);
	cout << sizeof vd << endl << sizeof vcptr << endl;
	cout << &vd[0] << endl << &vcptr[0] << endl;
	// Both array and vectors have object.at() method
	// It takes index where to assign value and check it, so it won't let -2
	//vd.at(-2) = 24.55F; // Aborted
	vd.at(0) = 24.55F;
	cout << vd[0] << endl;

	// Array quick overview
	// Allocates memory in stack
	// This data type is very similar to plain static arrays
	// but with cool attributes and methods
	using	std::array;

	// creates var ai, which is int array and has 5 elems
	// size of array cannot be speciefied by varible
	// only constant or integer literal
	array<int, 5>ai;
	// creates var ad, which is double array and has 4 elems
	// besides, it initializes them in place
	array<double, 4> ad = {1.2, 2.1, 3.43, 4.3}; 
	array<float, 3> af {1.76F, 22.4F, 341.2F}; 
	//af[-2] = 24.55F; // it's allowed, but is VERY-VERY DANGEROUS CODE
	// Both array and vectors have object.at() method
	// It takes index where to assign value and check it, so it won't let -2
	//af.at(-2) = 24.55F; // Aborted
	af.at(2) = 24.55F;
	
	cout << sizeof ai << endl << sizeof ad << endl << sizeof af << endl;
	cout << &ai << endl << &ad << endl << &af << endl;
	cout << af[2] << endl;

	return (0);
}
