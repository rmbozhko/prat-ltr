#include <iostream>

using		std::cout;
using		std::endl;

struct	box
{
	char	maker[40];
	float	height;
	float	width;
	float	length;
	float	volume;
} parcell = {"Nova Poschta", 12, 5, 10};

void		ft_show_box(box temp)
{
	cout << "Maker: " << temp.maker << endl;
	cout << "Height: " << temp.height << endl;
	cout << "Width: " << temp.width << endl;
	cout << "Length: " << temp.length << endl;
	cout << "Volume: " << temp.volume << endl;
}

void		ft_calc_box_vol(box *temp)
{
	temp->volume = temp->height * temp->width * temp->length;
}

int		main(void)
{
	ft_show_box(parcell);
	ft_calc_box_vol(&parcell);
	ft_show_box(parcell);
	return (0);
}
