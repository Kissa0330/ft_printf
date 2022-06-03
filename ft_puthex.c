/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:17:21 by rtakano           #+#    #+#             */
/*   Updated: 2022/05/31 21:04:42 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_binarytodecimal(int *binary)
{
	int				i;
	unsigned int	decimal;
	unsigned int	multiplynum;

	i = 31;
	decimal = 0;
	multiplynum = 1;
	while (i >= 0)
	{
		decimal += binary[i] * multiplynum;
		multiplynum *= 2;
		i--;
	}
	return (decimal);
}

char	*ft_changehex(unsigned int nbr)
{
	char	*hex;
	int		len;
	int		i;

	i = nbr;
	len = 1;
	while (nbr / 16 > 0)
	{
		len++;
		nbr /= 16;
	}
	hex = malloc(sizeof(char) * len);
	nbr = i;
	while (len--)
	{
		if (nbr % 16 < 10)
			hex[len] = nbr % 16 + '0';
		else
			hex[len] = nbr % 16 % 10 + 'a';
		nbr /= 16;
	}
	return (hex);
}

int	ft_puthex(int nbr, char format)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_changehex(ft_binarytodecimal(ft_decimaltobinary(nbr)));
	if (format == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i ++;
		}
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
