#include "ft_printf.h"

size_t	put_str(char *str, va_list args)
{
	size_t	len;
	size_t	res;
	char	tgt;
	char	*s;

	res = ft_strlen(str);
	while (ft_strchr(str, '%') != NULL)
	{
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, '%'));
		while (len--)
			ft_putchar_fd(*str++, 1);
		tgt = *(str + 1);
		if (tgt == 'd' || tgt == 'i')
			res += ft_putnbr(va_arg(args, int)) - 2;
		else if (tgt == 'u')
			res += ft_putnbr(va_arg(args, unsigned int)) - 2;
		else if (tgt == 's')
		{
			s = va_arg(args, char *);
			ft_putstr_fd(s, 1);
			res += ft_strlen(s) - 2;
		}
		else if (tgt == 'c')
		{
			ft_putchar_fd((unsigned char)va_arg(args, int), 1);
			res += 1 - 2;
		}
		else if (tgt == 'p')
			res += ft_putpt(va_arg(args, uintptr_t)) - 2;
		else if (tgt == 'X' || tgt == 'x')
			res += ft_puthex(va_arg(args, int), tgt) - 2;
		else if (tgt == '%')
		{
			ft_putchar_fd('%', 1);
			res += 1 - 2;
		}
		str += 2;
	}
	ft_putstr_fd(str, 1);
	return	(res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	res;

	va_start(args, str);
	res = put_str((char *)str, args);
	va_end(args);
	return (res);
}
