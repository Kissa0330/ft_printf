#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	size_t	len;
	char	*str_pt;
	va_list	args;

	len = 0;
	va_start(args, str);
	str_pt = (char *)str;
	while(ft_strchr(str_pt, '%') != NULL)
	{
		len = ft_strlen(str_pt) - ft_strlen(ft_strchr(str_pt, '%'));
		while (len--)
			ft_putchar_fd(*str_pt++, 1);
		if(*(str_pt + 1) == 'd')
			ft_putnbr_fd(va_arg(args, int), 1);
		else if(*(str_pt + 1) == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		// else if(*(str_pt + 1) == 'c')
		// 	ft_putchar_fd(va_arg(args, char), 1);
		str_pt = str_pt + 2;
	}
	va_end(args);
	ft_putstr_fd(str_pt, 1);
	return (ft_strlen(str));
}
