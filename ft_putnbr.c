#include "ft_printf.h"

void	ft_putnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
