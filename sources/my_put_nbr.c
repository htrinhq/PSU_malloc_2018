/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** putnbr
*/

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_put_nbr(int nb)
{
	int nbr;

	if (nb < 0) {
		my_putchar(45);
		nb = (-1) * nb;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			nbr = nb % 10;
			nb = (nb - nbr);
			nb = nb / 10;
			my_put_nbr(nb);
			my_putchar(48 + nbr);
		} else
			my_putchar(48 + nb % 10);
	}
	return (0);
}
