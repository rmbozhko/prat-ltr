#include <iostream>

int		main(void)
{
	using		namespace std;

	wchar_t		w_c;
	char16_t	c_16; // char with 2 bytes
	char32_t	c_32; // char with 4 bytes
	const	int	Months = 12; // definition and initialization const var
	//Months = 12;	// assigning to variable with const qualificator
			// after its setting isn't allowed
	float		fnum1{1.0}; // C++11 assinging //списковая иницализация	
	float		fnum;	

	c_16 = u'/u00F6';
	c_32 = U'/U0000222B';
	w_c = L'P';
	cout << c_16 << " " << c_32 << endl; 
	wcout << L"Hello, friend!\n" << sizeof w_c << endl;
	fnum = -3.45E-2F;//-2 назвываеться порядком, -3.45 это мантисса.
	cout << fnum << endl;
	fnum = 8e-2F;
	cout << fnum << endl;

	//WTF?!?! This is floating-point numbers.
	fnum1 = 2.0E22;
	fnum = fnum1 + 1.0F;
	cout << "Result of substraction: " << fnum - fnum1 << endl;
	//Float handles only first 7 digits before dot.
	// That it is why it doesn't give a damn about 1.0 and result is -> 0
		
	//turn off exp displaying, instead show all number in dec notation
	//ios_base::fixed, ios_base::floatfield are consts defined in iostream
	cout.setf(ios_base::fixed, ios_base::floatfield);	
	cout << "Result of addition: " << -9.2e-5 << endl;
	cout << "Automatically casted to double(by default all constants with floating-point are casted to double): " << 1e7 / 9.0 << endl;
	cout << "Automatically casted to float, due to suffix: "
		<< 1e7f/9.0f << endl;
	
	double dnum1 = 2.147483655E9;
	cout << dnum1 << endl;
	unsigned long long		inum1;

	inum1 = dnum1;
	cout << inum1 << endl;	
	inum1 = 7.2E12;
	cout << inum1 << endl;	
	
	int		lol = {3.14};//warning, in c++11 assigning floating-point num to int not allowed
	int		ceck = {2147483648};//waning in c++11, -Wnarrowing
	cout << lol << endl;
	cout << ceck << endl;

	const	int	code = 66;
	int		x = 66;

	char		c1 {31325}; //awful, why trying to fit if there is only 1 byte
	char		c2 = {66}; // allowed 66 fits in 1 byte
	char		c3 {code}; // ok, as previous, because both are constants
	char		c4 = {x}; // bad, as x is not a const, so its value can be changed
			x = 31325; // here we go, that is why previous line is dengerous

	char		c5 = x; //in C99 || C++98/03, such is allowed even if x value doesn't fit in 1 byte

	return (0);
}
