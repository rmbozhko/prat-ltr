#include <iostream>
#include <fstream>
#include <cstdlib>

using		namespace	std;

// OOP, Inheritance
// ostream - базовый клас, ofstream - производным классом
// ofstream has an access to all methods of ostream class

// Reference variable can be a reference both to a basic and to a derivative class
void		ft_file_it(ostream &out, double foc_length, const double foc_eye, int limit)
{
	ios_base::fmtflags		initial;
	
	initial = out.setf(ios_base::fixed);
	out.precision(0);
	out << "Focal length of an objective: " << foc_length << "mm\n";
	out.setf(ios_base::showpoint);
	out.precision(1);
	out.width(12);
	out << "f.l. eyepiece";
	out.width(15);
	out << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		out.width(12);
		out << foc_eye[i];
		out.width(15);
		out << int(foc_length / foc_eye[i] + 0.5) << endl;
	}
	out.setf(initial);
}

int		main(void)
{
	const int	LIMIT = 5;

	
	
	return (0);
}
