#include <iostream>


using	std::cout;
using	std::endl;

struct	boss;
struct	map;
struct	applicant
{
	char	name[30];
	int	credit_ratings[3];
};

void	igor(void);
float	tofu(int);
double	mpg(double, double);
long	summation(long [], size_t len);
double	doctor(const char *);
void	ofcourse(boss); // (boss)
char	*plot(map *); // (map*)
int	judge(int (*ft)(const char));
void	f1(applicant*);
const char *f2(const applicant*, const applicant*);

void	ft_mod_arr(int *arr, size_t len, int num)
{
	for (size_t i = 0; i < len; i++)
		arr[i] = num;
}

void	ft_mod_arr_ptr(int *begin, int *end, int num)
{
	for (int *i = begin; i != end; i++)
		*i = num;
}

double	ft_mod_arr_ptr(const double *arr, size_t len)
{
	double		max_value;

	max_value = arr[0];
	for (int i = 0; i < len; i++)
		max_value = (arr[i] > max_value) ? arr[i] : max_value;	
	return (max_value);
}

int	replace(char *str, char c1, char c2)
{
	int		times;
	
	for (int i = times = 0; str[i]; i++)
		if (str[i] == c1)
		{
			str[i] = c2;
			times++;	
		}
	return (times);
}

void	ft_show_inhalt(applicant temp)
{
	cout << "Showing copy of variable" << endl;
	cout << temp.name << endl;
	for (int i = 0; i < 3; i++)
		cout << temp.credit_ratings[i] << ".";
	cout << endl;
}

void	ft_show_inhalt(applicant *temp)
{
	cout << "Showing using pointer" << endl;
	cout << temp->name << endl;
	for (int i = 0; i < 3; i++)
		cout << temp->credit_ratings[i] << ".";
	cout << endl;
}
int		main(void)
{
	cout << *"pizza" << endl; // 'p'
	cout << "taco"[2] << endl; // 'c'
	applicant	rbozhko = {"Roman Bozhko", {12, 5, 1998}};
	ft_show_inhalt(rbozhko);
	ft_show_inhalt(&rbozhko);

	typedef void (*ft_show)(applicant*);
	typedef const char *(*ft_cmp)(const applicant*, const applicant*);
	ft_show p1 = f1;
	ft_cmp p2 = f2;

	// ap is an array of 5 pointers to functions
	ft_show ap[5];
	// ap is a pointer to an array of 10 pointers to functions
	ft_cmp (*pa)[10];
	return (0);
}
