#include <iostream>

int		main(void)
{
	using	namespace	std;

	// if compiler finds: bool, char, signed char, unsigned char, short
	// in expressions like one below, it automatically convert result of expression to 'int'
	// and than cast it to the type of fowl: 'short'
	short	chickens = 20;
	short	ducks = 35;
	short 	fowl = chickens + ducks;
	
	// if we have some division, multiplication, addition or else
	// the result will be casted by compiler to the biggest of presented data type
	
	// here the data type of resulting number of expression in the middle will be - double,
	// because as we know if floating point number wasn't casted
	// using suffix F, f to 'float' data type, it will be converted to double by default.
	// Double(8) > int(4) -> so result will be in double
	cout << (9.0 / 5) << endl;
	
	char		c = 'A';
	
	cout << "ASCII code of letter \'A\': " << (int)c << endl; // C-alike style
	// OR we also can write smth like this
	cout << "ASCII code of letter \'A\': " << int(c) << endl; // C++-alike style

	// Besides C++ has 4 typecasting operations
	// static_cast<dataType> (varName) -> casts varName to dataType and return casted value
	// Straustrup thinks that static_cast used below is more safe than C-way mentioned above
	cout << static_cast<signed char> (c) << endl;
	cout << static_cast<bool> (c) << endl;
	cout << static_cast<float> (c) << endl;	
	char		zero = '\0'; // ASCII code: 0
	cout << static_cast<bool> (zero) << endl;
	cout << static_cast<float> (zero) << endl;
	
	// auto-hell
	// auto look for initializing value and
	// assigning certain type to variable automatically	
	auto	inum = 0;	// here auto assing int data type to varibale inum
	auto	fnum = 1.2e2f;	// here auto assing float data type to variable fnum due to suffix
	
	// But there can be problems
	// using explicit declaration i can make variable be double
	auto	dnum1 = 0;	// here we got int, if we even would like to hae double
	double	dnum2 = 0;	 // here we got double
	
	//auto 	a;		// error as there is no initializer
	
	c = 'A';
	cout << c << " " <<sizeof c << endl;
	return (0);
}
