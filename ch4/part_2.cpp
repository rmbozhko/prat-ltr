#include <iostream>
#include <string>
#include <cstring>

int		main(void)
{
	using	namespace std;
	string	name = "Roman"; // C99 declaring
	string	surname = {"Bozhko"}; // C++11 declaring
	string	age; // declared, not initialized. Length of age is zero
	char	city[25] = {"Boryspil"}; // C++11 assigning
	// objects of class string can be assigned to each other
	age = name;
	cout << age << endl;
	// C-alike char arrays can be assigned string class object
	age = city;
	cout << age << endl;
	
	//string objects (and string literals) can be concatinated
	name += " " + surname;
	cout << name << endl;
	cout << "Lenght of name varibale(using method): " << age.size() << endl;
	cout << "Lenght of name variable(using function): " << strlen(city) << endl;
	
	char	carr[20];
	string	temp;
	
	cout << "Lenght of C-like array: " << strlen(carr) << "\nSize of initialized but not defined string object: " << temp.size() << endl;
	cin.getline(carr, 20);
	cout << "Entered value using method: " << carr << endl;
	// this is wrong, getline as method doesn't know what to do with string data type
	// cin.getline(temp, 20);
	// this is a function, where 1-st arg tells from where to read
	// and 2-nd where to save read info
	// it is great, as you do not need to specify amount of read chars 
	// working with string class objects we use this way to save value from stdin
	// because cin object knows nothings about 'string' data type.
	getline(cin, temp);
	// WHY THEN cin >> <string class> WORKS???!?!?!?!?
	// There is smth about friend-function
	cout << "Enter smth to show that cin works with strings: " << endl;
	cin >> temp;
	cout << "Entered value using function: " << temp << endl;
	
	wchar_t		wcarr[] = L"Wide char data type string";
	char16_t	two_bytearr[] = {u"Two byte long string"};
	char32_t	four_bytearr[] = {U"Four byte long string"};

	// In C++11 we can print raw string
	// It is string, where \n is interpreted as \n not as newline char
	cout << R"(Lol\n\a\bl\\\'\")" << endl;
	// But what if we would like to output "( or )"
	// raw string allows us specify ending chars
	// to output mentioned char sequence we can specify another delimiters
	cout << R"*("(Lol\n\a)")*" << endl;
	cout << R"+(\nlol\n)+" << endl;
	// we can specify u and U with R to get string of 16 bits or 32 bits
	cout << uR"(God cop, bad cop)" << endl;

	return (0);
}
