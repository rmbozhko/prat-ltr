#include <iostream>
#include <string>

using		namespace	std;

// Practicing using of references

struct		free_throws
{
	string		name;
};

// This function will likely crush if got called, as here we are asking of memory address of local variable,
// which will be destroyed as soon as function finishes its execution
// but everything depends on compiler, which can malloc memory if you return local variable
const free_throws	&ft_clone2(free_throws &temp)
{
	free_throws	newguy;

	newguy = temp;
	newguy.name = "Andrey";
	return (newguy);
}

// This function will execute perfectly if got called, as here we are dereferncing the pointer's value
// which is an address of temp variable, so to say we are returning temp address back from function
// we have nothing to do with pointer variable itself
const free_throws	&ft_clone(free_throws &temp)
{
	free_throws	*newguy;

	newguy = &temp;
	// or (both are same)
	*newguy = temp;
	newguy->name = "Roman";
	return (*newguy);
}

string		ft_version1(const string &s1, const string &s2)
{
	// Safe function
	string		res;

	// we are allocating the string object in this function, modify it
	// and then returns its !!!copy!!! 
	res = s2 + s1 + s2;
	return (res);
}

const string	&ft_version2(string &s1, const string &s2)
{
	// Safe function, but modify the source data
	// we are modifying the s1 variable and also returning it from function
	s1 = s2 + s1 + s2;
	return (s1);
}

const string	&ft_version3(const string &s1, const string &s2)
{
	// Not safe function
	string		res;

	// we are allocating the string object in this function, modify it
	// and then returns object itself, which is impossible as it will be destroyed as soon as 'return' is met
	res = s2 + s1 + s2;
	return (res);
}

const string	ft_version4(string s1, string s2)
{
	// we got here two copies of sent arguments
	// we don't work on input variable and const char* defined in main function
	// we work on their casted(second parameter) copies
	string		res;

	// here we modify the local variable value and then returns local variable
	// from function, but as already mentioned, we doesn't return variable itself
	// we returns its copy, which is allocated in temporary memory space with 'const' kvalificator
	res = s2 + s1 + s2;
	return (res);
}

const string	&ft_version5(string s1, string s2)
{
	// Unsafe, very dangerous function, same as ft_version1
	// we got here two copies of sent arguments
	// we don't work on input variable and const char* defined in main function
	// we work on their casted(second parameter) copies
	string		res;
	
	// here we modify the local variable value and then return on of passed copies
	// from function, we return variable itself, but it is undefined behaviour
	// it is like to return (res), from this function
	// all variables from this function res, s1 and s2 are in the same storage
	// and it gets empty as soon as ft finishes
	res = s2 + s1 + s2;
	return (s2);
}

int		main(void)
{
	free_throws		player;
	player.name = "Oleg";
	cout << "Original name: ";
	cout << player.name << endl;	
	cout << "Proper function: ";
	const free_throws	&jolly = ft_clone(player);
	cout << player.name << endl;
	cout << "Jolly's name: " << jolly.name << endl;
	cout << "Wrong function: ";
	ft_clone2(player);
	// name hasn't changed
	cout << player.name << endl;

	string		input;
	string		result;
	string		copy;

	cout << "Enter a string: ";
	getline(cin, input);
	copy = input;
	cout << "Your string as entered: " << input << endl;
	// first arg is string, but second is const char* 
	// nevertheless std::string implicilty casts char* or const char* to std::string
	// of course with temporary variable creating if it is passed as function argument
	result = ft_version1(input, "***");
	cout << "Original string: " << input << endl;	
	cout << "Modified string: " << result << endl;	
	result = ft_version2(input, "###");
	cout << "Original string: " << input << endl;	
	cout << "Modified string: " << result << endl;
	cout << "Middle of the test. Resetting values." << endl;
	input = copy;
	// You are ask for an access to memory address, which is no longer valid
	// it is valid only until ft_version3 is working, cause you are asking to get local variable out	
	result = ft_version3(input, "@@@");
	cout << "Original string: " << input << endl;	
	cout << "Modified string: " << result << endl;
	cout << "The inputted string: " << copy << endl;
	result = ft_version4(input, "$$$");
	cout << "Original string: " << input << endl;	
	cout << "Modified string: " << result << endl;
	// You are ask for an access to memory address, which is no longer valid
	// it is valid only until ft_version5 is working, cause you are asking to get local variable out
	// parameters of function which are copies, just like in ft_version4 and ft_version5 are also local vars
	result = ft_version5(input, "^^^");
	cout << "Original string: " << input << endl;	
	cout << "Modified string: " << result << endl;
	return (0);
}
