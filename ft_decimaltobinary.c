/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltobinary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:57:57 by rtakano           #+#    #+#             */
/*   Updated: 2022/05/31 16:43:28 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*changebinarynum(int *binarynum, int num, int negativeflag)
{
	int	i;

	i = 31;
	if (negativeflag == 1)
	{
		num = num * -1 - 1;
		while (num)
		{
			binarynum[i] -= num % 2;
			num /= 2;
			i --;
		}
	}
	else if (negativeflag == 0)
	{
		while (num)
		{
			binarynum[i] += num % 2;
			num /= 2;
			i --;
		}
	}
	return (binarynum);
}

int	*ft_decimaltobinary(int num)
{
	int	*res;
	int	initial;
	int	i;

	res = malloc(sizeof(int) * 33);
	res[32] = '\0';
	if (num < 0)
		initial = 1;
	else if (0 <= num)
		initial = 0;
	i = 0;
	while (i < 32)
		res[i++] = initial;
	return (changebinarynum(res, num, initial));
}
