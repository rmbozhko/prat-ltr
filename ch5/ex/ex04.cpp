#include <iostream>

int		main(void)
{
	using	namespace	std;

	unsigned		kleo_amount;
	unsigned		dafna_amount;
	unsigned		years_num;
	unsigned		dafna_initial;

	cout << "Enter amount of money invested to complicated percent: ";
	cin >> kleo_amount;
	cout << "Enter amount of money invested to plain percent: ";
	cin >> dafna_amount;
	cout << "Now we will see how many years, it takes for 1st acc.";
	cout << "to overcome in balance the 2nd one." << endl;
	years_num = 0;
	dafna_initial = dafna_amount;
	do
	{
		kleo_amount += (kleo_amount * 0.05);
		dafna_amount += (dafna_initial * 0.1);
		years_num++;
		cout << "And one more year passed...\n";
	}
	while (kleo_amount < dafna_amount);
	cout << "Due to research it will take 1st acc. " << years_num;
	cout << " years to overcome in balance 2nd one." << endl;
	return (0);
}
