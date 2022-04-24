#include "ft_printf.h"
#include <stdio.h>

char	*ft_changehex(long long nbr)
{
	char		*hex;
	long long	len;
	long long	i;

	i = nbr;
	len = 1;
	while(nbr / 16 > 0)
	{
		len++;
		nbr /= 16;
	}
	hex = malloc(sizeof(char) * len);
	nbr = i;
	while (len--)
	{
		if(nbr % 16 < 10)
			hex[len] = nbr % 16 + '0';
		else
			hex[len] = nbr % 16 % 10 + 'a';
		nbr /= 16;
	}
	return (hex);
}

void	ft_puthex(long long nbr, char format)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_changehex(nbr);
	if(format == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i ++;
		}
	}
	ft_putstr_fd(str, 1);
}
