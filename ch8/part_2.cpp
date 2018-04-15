#include <iostream>
#include <cmath>
#include <string>

using	namespace	std;

// Reference usage with structures
struct	free_throws
{
	string		name;
	int		made;
	int		attempts;
	float		percent;
};

void		ft_display(const free_throws &);
void		ft_set_pc(free_throws &);
free_throws	&ft_accumulate(free_throws &, const free_throws &);
free_throws	ft_val_accumulate(free_throws &dest, const free_throws &src);

// END

// C++ can generate temporary variable, if thing passed to a function argument,
// which is reference, is not lvalue (expression(7.0, var_name + 1), literal constant("Roma", ""))
// or variable which data type differs from expected but can be casted to a proper one
// BTW, C++ can only create temporary variable and make a reference to it, if a ref. variable has 'const' modifier
// lvalue - is data object that can be used to access any memory address(var_name, pointer, array or array's elem)

// for proper working, like passing the lvalue and same datatype argument
double		ft_refcube(double &rd)
{
	rd = rd;
	cout << "rd address: " << &rd << endl;
	return (rd * rd * rd);
}

// for temporary variables, so here на відміну від ф-ції вище 'const' can be found
// which prevents temporary variables changing
// such type of function is very similar to plain function type, where it works with copies of passed arguments
double		ft_refcube(const double &rd)
{
	// we cannot modify rd, which is 'const'
	// but we can modify temp and return it if needed, like working on initial value
	double		temp = rd;
	cout << "TEMP var: " << temp << endl;
	//rd = rd; // unlike the same line in function above, such isn't possible as rd is 'const' 
	cout << "Temporary variable function sample: " << &rd << endl;
	return (rd * rd * rd);
}

void		ft_refswap(int &a, int &b)
{
	int		temp;

	temp = b;
	b = a;
	a = temp;
}

int		main(void)
{
	double		side = 3.0;
	double		*pd = &side;
	double		&rd = side;
	long		edge = 5L;
	double		lens[4] = {2.0, 5.0, 10.0, 12.0};
	
	double		res;
	res = ft_refcube(side); // temporary var is not created, side is double and can be lvalue
	cout << res << endl;
	res = ft_refcube(lens[2]); // temporary var is not created, array's element is double and can be lvalue
	cout << res << endl;
	res = ft_refcube(rd); // temporary var is not created, rd is double and can be lvalue
	cout << res << endl;
	cout << "Variable side address: " << &side << endl; // address here and in function will be same
	res = ft_refcube(*pd); // temporary var is not created, *pd is double and can be lvalue	
	cout << res << endl;
	cout << "Variable edge address: " << &edge << endl; // this output will differ from function's
	res = ft_refcube(edge); // temporary var!!is!! created, edge is not double, it is long but it can be lvalue
	cout << res << endl;
	res = ft_refcube(10.0 + side); // temporary var !!is!! created, expr. will result in double but can't be lvalue
	cout << res << endl;
	res = ft_refcube(7.0); // temporary var !!is!! created, 7.0 has double value but can't be lvalue
	cout << res << endl;

	int		x;
	int		y;
	
	x = 12;
	y = -5;
	cout << "Value of side variable before swap: " << side << endl;
	cout << "Value of edge variable before swap: " << edge << endl;
	// If the line below is passed two temporary variables are created(due to the datatype mismatch) 
	// and their values are swapped, while side and edge local vars remain the same
	//ft_refswap(side, edge); // isn't allowed since C++98
	// Though, ft_refswap has two ref. parameters it takes temporary variables adresses when
	// they are created due to the fact that passed arguments have different datatype
	cout << "Value of side variable after swap: " << side << endl;
	cout << "Value of edge variable after swap: " << edge << endl;


	// In C++11 rvalue reference appeared, which can be reference to rvalues,
	// like expressions, functions' returns constant literals
	double&& right_val_ref_sqrt = sqrt(81);
	cout << right_val_ref_sqrt << endl;
	double&& right_val_ref_expr = 2.0 * rval_ref_sqrt + 25.12;
	cout << right_val_ref_expr << endl;
	
	// Using reference variables with structures
	// if certain member of structure isn't defined, it is automatically set to zero(0)
	free_throws	ifelsa = {"Ifelsa Branch", 13, 14};
	free_throws	andor = {"Andor Knott", 10, 16};
	free_throws	minnie = {"Minnie Max", 7, 9};
	free_throws	whilly = {"Whilly Looper", 5, 9};
	free_throws	long_long = {"Long Long", 6, 14};
	free_throws	team = {"Throwgoods", 0, 0};
	free_throws	dup;

	ft_set_pc(ifelsa);
	ft_display(ifelsa);
	ft_accumulate(team, ifelsa);
	ft_display(team);

	// Using the returning reference of ft_accumulate
	// As far as ft_accumulate returns a reference and ft_display is expecting reference to a block of memory
	// allocated for a free_throws element the line below is possible
	ft_display(ft_accumulate(team, andor));
	ft_accumulate(ft_accumulate(team, minnie), whilly);
	ft_display(team); 
	
	// Using the returning reference to assign to a variable
	cout << "Before long_long accumlating" << endl;
	ft_display(team);
	// The line below works with team data object and returns itself
	// this mean that both dup and team will reference the same memory address
	// dup is not a reference, it's a plain structure variable
	// but can still access the memory zone allocated for team variable
	dup = ft_accumulate(team, long_long);
	cout << &dup << endl << &team << endl;
	cout << "After long_long accumlating" << endl;
	ft_display(team);
	cout << "Displaying dup after assignment via returned reference" << endl;
	ft_display(dup);

	// ill-advised assignment
	free_throws lol;
	
	(lol = ft_val_accumulate(dup, whilly)) = whilly;	
	ft_display(lol);
	ft_set_pc(whilly);

	// the line below works because the returned value is reference variable, which can be lvalue
	ft_accumulate(dup, whilly) = whilly;	
	
	// here in the lvalue we get an address of a copy of a dup variable
	// but we don't save it anywhere, so we just make that address to store whilly and then disappear
	ft_val_accumulate(dup, whilly) = whilly;	
	
	// Over here we do same as in a line above, but store the returned copy in lol variable
	// and then modify it(assign whilly), so we can access that zone(structure elements and so)
	//free_throws lol;
	// this is not good approach, as far as we got !!copy!! of a structure, this may cost hundreds of bytes
	(lol = ft_val_accumulate(dup, whilly)) = whilly;	
	ft_display(lol);
	cout << "Displaying dup after ill-advised assignment" << endl;
	ft_display(dup);
	
	return (0);
}

free_throws	ft_val_accumulate(free_throws &dest, const free_throws &src)
{
	dest.attempts += src.attempts;
	dest.made += src.made;
	ft_set_pc(dest);
	return (dest);
}

void		ft_display(const free_throws &temp)
{
	cout << "Name: " << temp.name << '\n';
	cout << " Made: " << temp.made << '\t';
	cout << "Attempts: " << temp.attempts << '\t';
	cout << "Percent: " << temp.percent << '\n';
}

void		ft_set_pc(free_throws &temp)
{
	if (temp.attempts != 0)
		temp.percent = 100.0f * float(temp.made) / float(temp.attempts);
	else
		temp.percent = 0;
}

free_throws	&ft_accumulate(free_throws &dest, const free_throws &src)
{
	dest.attempts += src.attempts;
	dest.made += src.made;
	ft_set_pc(dest);
	return (dest);
}
