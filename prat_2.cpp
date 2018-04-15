#include "prat.hpp"

// We will be able to use all std lib functions without std:: prefix
//using namespace std;

// We will be able to use following functions without std, but all others(from std lib) with std:: prefix
using std::cout;
using std::endl;

//std:: -> квалификатор
//using -> директива
//endl -> манипулятор

void		ft_print(std::string str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_print(int num)
{
	using std::string;
	using std::cout;
	using std::endl;

	char		str[11];
	char		temp[11];
	int		i;
	size_t		j;

	j = 0;
	while (num > 0)
	{
		str[j] = num % 10 + 48;
		j++;
		num /= 10;
	}
	str[j] = '\0';
	i = j - 1;
	j = 0;
	while (i >= 0)
		temp[j++] = str[i--];
	temp[j] = '\0';
	ft_print(temp);
}

void		ft_have_nice_day(void)
{
	using namespace std;
	//function scope std namespace
	//everything from std library without std:: qualificator
	string		name;
	int		age;
	char		answer;	

	cout << "Tell me please, your name: ";
	cin >> name;
	cout << name  << " have a nice day." << endl;
	ft_print(name);
	cout << "Tell me please, your age: " << endl;
	cin >> age;
	ft_print(age);
	cout << "So, " << name << " your age is " << age << endl;
	cout << "Did you know that sqrt of your age is "
		<< ft_get_sqrt((double)age) << "? y/n " << endl;
	cin.get();
	answer = cin.get();
	if (answer == 'y')
		cout << "Good for you!";
	else if (answer == 'n')
		cout << "You are welcome.";
	else
		cout << "Wrong answer..";
	cout << endl;
}

int		main(void)
{
	std::string		str;
	
	cout << "Hello, how are you?";
	cout << endl;
	std::cin >> str;
	cout << "I feel " << str << endl;
	ft_have_nice_day();
	return (0);
}
