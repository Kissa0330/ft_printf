#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdint.h>
#include "./libft/libft.h"

int		ft_putnbr(long long n);
int		ft_putpt(uintptr_t pt);
int		ft_puthex(int nbr, char format);
int		*ft_decimaltobinary(int num);
char	*ft_changehex(unsigned int nbr);

#endif