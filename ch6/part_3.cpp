#include <iostream> //ostream, istream classes defined
#include <fstream> //ofstream, ifstream classes defined
#include <string>
#include <cstdlib> // library, with EXIT_FAILURE and exit function prototype

int		main(void)
{
	using	namespace	std;

	// Working-out with ofstream
	ofstream		file; // creating instance of ofstream
	char			arr_filename[50];
	string			str_filename;

	getline(cin, str_filename);
	// BTW when you open file, you delete its content, but you can overwrite this behaviour
	file.open(str_filename); // associating object with file
	if (!file.is_open())
		cout << "Smth wrong happened: " << bool(file) << endl;
	// the input is redirected to file, using '<<'
	file << "It\'s a lol file:), YOYOYOYO" << endl;
	file.close(); // closing file, as have worked enough with it
	

	char		automobile[50];
	int		year;
	double		d_price;
	double		a_price;
	ofstream	output_file;

	output_file.open("info.txt");
	cout << "Enter model of car: ";
	cin.get(automobile, sizeof automobile).get();
	cout << "Enter year of production: ";	
	cin >> year;
	cout << "Enter the original price: ";	
	cin >> a_price;	
	d_price = a_price * 0.913;
	
	// Showing off that we can do same things with file output as with standart output
	cout.put('\n');
	cout << "Model: " << automobile << endl;
	cout << "Year: " << year << endl;
	// setting precision
	// following methods only affect privat members of 'ostream' class
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	// end of setting precision	
	cout << "Starting price: " << a_price << endl;
	cout << "Now asking: " << d_price << endl;
	
	output_file.put('\n');
	output_file << "Model: " << automobile << endl;
	output_file << "Year: " << year << endl;
	// setting precision
	// following methods only affect privat members of 'ostream' class
	output_file << fixed;
	output_file.precision(2);	
	output_file.setf(ios_base::showpoint);
	// end of setting precision	
	output_file << "Starting price: " << a_price << endl;
	output_file << "Now asking: " << d_price << endl;
	output_file.close();


	// Working-out with ifstream
	ifstream	input_file;
	char		line[80];

	cout << "Enter file to read from: ";
	cin >> str_filename;	
	input_file.open(str_filename);
	// if we don't check whether file is open or not it will cause problems in future
	// while trying to reading from it or so
	// if compiler doesn't support ifstream.is_open() use ifstream.good() instead
	// but you should be aware that good doesn't work so thoroughly as is_open does
	if (!input_file.is_open())
		// EXIT_FAILURE equals to '1' and is used to show system that smth went wrong
		exit(EXIT_FAILURE);
	while (input_file.good())//(input_file.getline(line, sizeof line))
	{
		if (!input_file.getline(line, sizeof line))
			break ;
		cout << line << endl;
	}
	cout << "Good function return: " << bool(input_file.good()) << endl;
	input_file.close();
	return (0);
}
