#include "ft_printf.h"

void	putpt(uintptr_t pt, int *len)
{
	if (pt >= 16)
	{
		putpt(pt / 16, len);
		putpt(pt % 16, len);
	}
	else
	{
		if (pt <= 9)
			ft_putchar_fd((pt + '0'), 1);
		else
			ft_putchar_fd((pt - 10 + 'a'), 1);
		*len += 1;
	}
}

int	ft_putpt(uintptr_t pt)
{
	int	*res;

	res = malloc(sizeof(int));
	ft_putstr_fd("0x", 1);
	*res = 2;
	putpt(pt, res);
	return (*res);
}
