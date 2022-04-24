#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

void	ft_putnbr(long long n);
void	ft_putaddress(void *arr);
void	ft_puthex(long long nbr, char format);

#endif