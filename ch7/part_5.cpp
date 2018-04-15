#include <iostream>
#include <array>

//using	namespace	std;
using		std::cout;
using		std::cin;
using		std::endl;
using		std::array;

void		ft_array_print(array<double, 5> temp)
{
	for (int i = 0; i < 5; i++)
		cout << "Element #" << i << ": "<< temp[i] << endl;
}

void		ft_mod_arr(char *arr)
{
	arr[0] = 'L';
}

void		ft_print_arr(char *arr)
{
	cout << arr << endl;
}

void		ft_countdown(int *num)
{
	// for each new recursion level new copy of num variable is created
	// we can see that if look up on same lvls if Counting down and Kaboom
	cout << "Counting down ... " << *num << " and address " << &num << endl;
	if (*num > 0)
	{
		(*num)--;
		ft_countdown(num);
	}
	cout << "Kaboom ... " << *num << " and address " << &num << endl;
}

void		ft_modify_array(array<double, 5> *temp)
{
	bool		eof;

	eof = false;
	for (int i = 0; i < 5 && !eof; i++)
	{
		cout << "Enter value to an array: ";
		// The brackets are needed to get the correct sequence of operations
		// first of all goes square and simple brackets, asterisk after them
		while (!(cin >> (*temp)[i]))
		{
			eof = cin.eof();
			cout << eof << endl;
			cin.clear();
			while (cin.get() != '\n')
				continue ;
			if (eof)
				exit(EXIT_FAILURE);
		}
	}
	ft_array_print(temp[0]);
}

const	int	divs = 6;
const	int	len = 66;

void		ft_subdivide(char *ar, int low, int high, int level)
{
	int	mid;
	
	if (level == 0)
		return ;
	mid = (high + low) / 2;	
	ar[mid] = '|';
	ft_subdivide(ar, low, mid, level - 1);
	ft_subdivide(ar, mid, high, level - 1);
}

void		ft_draw_ruler(void)
{
	char		ruler[len];

	// setting nearly all elems of an arr to space(' ')
	// zero one elem should be '|' and len - 2 should be 
	for (int i = 1; i < len - 2; i++)
		ruler[i] = ' ';

	ruler[len - 1] = '\0';
	ruler[0] = ruler[len - 2] = '|';

	for (int i = 1; i <= divs; i++)
	{
		ft_subdivide(ruler, 0, len - 2, i);
		cout << ruler << endl;
		// resetting elems to spaces
		for (int j = 1; j < len - 2; j++)
			ruler[j] = ' ';
	}
}

double		ft_mkaliber(int lines_num)
{
	return (lines_num * 28.0 * 8);
}

double		ft_rbozhko(int lines_num)
{
	return (lines_num * 28.0 * 4);
}

void		ft_estimate(int lines_num, double(*ft)(int))
{
	cout << "To write " << lines_num << " lines I should be paid: "
					<< (*ft)(lines_num) << " hrvn." << endl;
}

// Complicated function pointers declarations
const double	*f1(const double ar[], int n);
const double	*f2(const double *ar, int);
const double	*f3(const double [], int);

int		main(void)
{
	array<double, 5> temp {1.0, 2.0, 3.0, 4.0, 5.0};
	// same rules that goes to structures are also aplicable to class objects
	// 
	// when we pass a variable we got its copy
	ft_array_print(temp);
	// when we pass address of the variable we got the reference to it
	ft_modify_array(&temp);
	
	char		test[] = "Roman";
	ft_mod_arr(test);
	cout << test << endl;
	//main(); // actually main function can be called in C++ but without -pedantic and error handling compiler flags
	int		i = 4;
	ft_countdown(&i);
	ft_draw_ruler();
	int		lines_num;

	cout << "Enter number of lines to write: ";
	cin >> lines_num;
	cout << "Here is mkaliber estimate: ";
	ft_estimate(lines_num, ft_mkaliber);
	cout << endl;
	cout << "Here is rbozhko estimate: ";
	ft_estimate(lines_num, ft_rbozhko);
	cout << endl;

	// Complicated function declarations pointers
	auto p1 = f1;
	(*p1)(NULL, 1);
	// we have declared a constant pointer to a function that returns const double pointer address
	// and get const double pointer as 1-st arg and int value as a second one
	/// we cannot change the address the following function pointer is pointing to as it's const
	const double *(* const p2)(const double [], int) = f2;
	p1 = f3;
	const double *(*p3)(const double*, int) = f3;
	auto ft_ptr = p1;
	// the following two ways to invoke function is applicable as they are allowed
	// the (*p1) shows us implicitly that it is a function pointer
	// the p1 explain that even a function name is a pointer
	// (notice how we assign a function to its pointer(no address operator))
	// so we should handle a function pointer as its name, which is a pointer
	cout << "Address: " << (*p1)(NULL, 1) << " and value: " << *(*p1)(NULL, 1) << endl;
	cout << "Address: " << p2(NULL, 1) << " and value: " << *p2(NULL, 1) << endl;
	//p2 = f3; // Error assignment to read-only mem space
	(*p2)(NULL, 1);
	(*ft_ptr)(NULL, 1);
	(*p3)(NULL, 1);

	// a pointer to an array of pointers to functions with identical set of arguments an returned value
	cout << "An array of function pointers workflow: " << endl;
	// [], () have higher priorety than '*' so, it is read like this:
	// a three elements length array, each elem of which is a pointer to function which returns bla-bla-bla-bla
	// besides, we cannot use here 'auto' keyword as it can be used only with single initializer
	// like int, double, char variable
	const double *(*p_arr[3])(const double *, int) = {f1, f2, f3};
	// but now we can make one more pointer to an array of three pointers to functions
	auto p_arr_2 = p_arr;
	for (int i = 0; i < 3; i++)
	{
		// we have [i] inside brackets because we should firstly reach the place in memory where certain
		// function pointer is stored and only then 'dereference' and invoke it
		const double *cdp = (*p_arr_2[i])(NULL, 1);
		cout << "Address of passed value: " << cdp << " value: " << *cdp << endl;
	}
	
	// pretend we have three same p_arr that do different things
	// we can gather them in one whole array of arrays or 2-d array
	// we can make a pointer + 0 to a p_arr array, pointer + 1 to smth else
	// it is so to say pointer to pointer to an array of three pointers to functions
	//auto p_p_arr = &p_arr_2; // 'auto' is allowed using -std=c++11
	const double *(*(*p_p_arr)[3])(const double*, int) = &p_arr; 
	// declaring an array of pointer to an array of pointers to pointers 
	const double *(*three_ft_ptr[3])(const double*, int) = {f2, f3, f1};
	const double *(*(*p_lol[2])[3])(const double*, int);// = {&p_arr, &three_ft_ptr}; 
	p_lol[0] = &p_arr;
	p_lol[1] = &three_ft_ptr;
	const double *(*(*(*ft_lol_ptr)[2])[3])(const double *, int) = &p_lol;
	// we also can use 'auto' here
	auto p_p_arr_auto = &p_arr;	
	// *p_p_arr is an address of first array, **p_p_arr is a first element of first array
	
	/* Segmenattion fault part 
	cout << "A pointer to an array of pointers to function pointers workflow: " << endl;
	for (size_t j = 0; j < 2; j++)
	{
	for (size_t i = 0; i < 3; i++)
	{
		cout << i << endl << j << "Lol" << endl;
		const double *cdp = (*(**ft_lol_ptr)[j][i])(NULL, 1);
		cout << "Address of passed value: " << cdp << " value: " << *cdp << endl;
	}
	}
	*/
	cout << "A pointer to an array of function pointers workflow: " << endl;
	for (int i = 0; i < 3; i++)
	{
		// we have [i] inside brackets because we should firstly reach the place in memory where certain
		// function pointer is stored and only then 'dereference' and invoke it
		const double *cdp = (*(*p_p_arr)[i])(NULL, 1);
		cout << "Address of passed value: " << cdp << " value: " << *cdp << endl;
	}

	// !!!!!!!!!!!!NOTICE!!!!!!!!!!!
	// &p_arr[0] is an address of first element, p_arr + 1 will result in moving appx. 4 bytes further
	// &p_arr is an address of of a whole array, &p_arr + 1 will result in moving appx. 12 bytes further
	
	
	// defining pointers to function, using auto keyword and using implicit assignment
	// working with typedef
	typedef char* str; 
	str lol[2] = {"Kek!", "Cheburek!"};	
	for (int i = 0; i < 2; i++)
		ft_print_arr(*(lol + i));
	
	// besides 'typdef' works fine with function complicated declarations
	typedef void(*void_ft)(char*);
	// but still 'auto' is used sometimes
	auto vp1 = ft_mod_arr;
	void_ft vp2 = ft_mod_arr;
	// vp3 is an array of three function pointers made useing 'typedef'
	void_ft vp3[3] = {ft_print_arr, ft_mod_arr, ft_print_arr};
	// vp4 is a pointer to an array of three function pointers made useing 'typedef'
	void_ft	(*vp4)[3] = &vp3;	
	// reassigning variable to another value
	vp1 = ft_print_arr;
	(*vp2)(test);
	(*vp1)(test);
	return (0);
}


const double	*f1(const double ar[], int n)
{
	double di = 123.0;
	const double *num = &di;

	cout << "Hello, World!@From f1" << endl;
	return (num);
}

const double	*f2(const double *ar, int)
{
	double di = 3424.0;
	const double *num = &di;

	cout << "Hello, World!@From f2" << endl;
	return (num);
}

const double	*f3(const double [], int)
{
	const double di = 392846912.0;
	const double *num = new double(di);//&di;

	cout << "Hello, World!@From f3" << endl;
	return (num);
}
