/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:55:36 by rtakano           #+#    #+#             */
/*   Updated: 2022/05/31 22:25:43 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr(long long n, int *len)
{
	*len += 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
	}
	if (n > 9)
		putnbr(n / 10, len);
	ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_putnbr(long long n)
{
	int	*res;

	res = malloc(sizeof(int));
	*res = 0;
	putnbr(n, res);
	return (*res);
}
