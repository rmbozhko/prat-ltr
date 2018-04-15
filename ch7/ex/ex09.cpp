#include <iostream>
#include <cstring>
#include <string>
# define SLEN 30

using		namespace	std;

struct	student
{
	string	fullname;
	char	hobby[SLEN];
	int	ooplvl;
};

void		ft_renew_reading(const char *str, student *curr, short flag)
{
	cin.clear();
	while (cin.get() != '\n')
		continue ;
	cout << str;
	if (!flag)
		getline(cin, curr->fullname);	
	else if (flag == 1)
		cin >> curr->hobby;	
	else if (flag == 2)
		cin >> curr->ooplvl;	
}

int		ft_getinfo(student pa[], int n)
{
	int		i;

	for (i = 0; i < n; i++)
	{
		cout << "Enter your fullname: ";
		while (!(getline(cin, pa[i].fullname)))
		{
			ft_renew_reading("Enter your fullname: ", &pa[i], 0);
		}
		if (!pa[i].fullname.size())
		{
			cout << "\nExiting\n" << endl;
			break ;
		}
		cout << "Enter your hobby: ";
		while (!(cin >> pa[i].hobby))
			ft_renew_reading("Enter your hobby: ", &pa[i], 1);
		cout << "Enter your OOP level: ";
		if (!(cin >> pa[i].ooplvl))
		{
			cout << pa[i].ooplvl << endl;
			ft_renew_reading("Enter your OOP level: ", &pa[i], 2);
		}
		cin.get();
	}
	return (i);
}

void		display1(student st)
{
	cout << "Fullname: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOP Level: " << st.ooplvl << endl;
}

void		display2(const student *st)
{
	cout << "Fullname: " << st->fullname << endl;
	cout << "Hobby: " << st->hobby << endl;
	cout << "OOP Level: " << st->ooplvl << endl;
}


void		display3(const student st[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Fullname: " << st[i].fullname << endl;
		cout << "Hobby: " << st[i].hobby << endl;
		cout << "OOP Level: " << st[i].ooplvl << endl;
	}
}

int		main(void)
{
	cout << "Введите размер класса : ";
	int class_size;
	cin >> class_size;
	while (cin.get () != '\n')
		continue ;
	student * ptr_stu = new student [class_size] ;
	if (!ptr_stu)
		return (EXIT_FAILURE);
	int entered = ft_getinfo(ptr_stu, class_size) ;
	for ( int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete []ptr_stu;
	cout << "Done \n" ;
	return (0);
}
