/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:20:46 by rtakano           #+#    #+#             */
/*   Updated: 2022/05/31 22:26:41 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbrs(char tgt, int nbr)
{
	int	res;

	res = 0;
	if (tgt == 'd' || tgt == 'i')
		res = ft_putnbr(nbr) - 2;
	else if (tgt == 'u')
		res = ft_putnbr((unsigned int)nbr) - 2;
	return (res);
}

int	put_str(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s) - 2);
}

int	put_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1 - 2);
}

int	judge_str(char *str, va_list args)
{
	size_t	res;
	char	tgt;

	res = ft_strlen(str);
	while (ft_strchr(str, '%') != NULL)
	{
		while (*str != '%')
			ft_putchar_fd(*str++, 1);
		tgt = *(str + 1);
		if (tgt == 'd' || tgt == 'i' || tgt == 'u')
			res += put_nbrs(tgt, va_arg(args, int));
		else if (tgt == 's')
			res += put_str(va_arg(args, char *));
		else if (tgt == 'c')
			res += put_char((unsigned char)va_arg(args, int));
		else if (tgt == 'p')
			res += ft_putpt(va_arg(args, uintptr_t)) - 2;
		else if (tgt == 'X' || tgt == 'x')
			res += ft_puthex(va_arg(args, int), tgt) - 2;
		else if (tgt == '%')
			res += put_char('%');
		str += 2;
	}
	ft_putstr_fd(str, 1);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	res;

	va_start(args, str);
	res = judge_str((char *)str, args);
	va_end(args);
	return (res);
}
