#include "ft_printf.h"

void	put_str(char *str, va_list args)
{
	size_t	len;
	char	tgt;

	while (ft_strchr(str, '%') != NULL)
	{
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, '%'));
		while (len--)
			ft_putchar_fd(*str++, 1);
		tgt = *(str + 1);
		if (tgt == 'd' || tgt == 'i')
			ft_putnbr(va_arg(args, int));
		else if (tgt == 'u')
			ft_putnbr(va_arg(args, unsigned int));
		else if (tgt == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (tgt == 'c')
			ft_putchar_fd((unsigned char)va_arg(args, int), 1);
		else if (tgt == 'p')
			ft_putaddress(va_arg(args, void *));
		else if (tgt == 'X' || tgt == 'x')
			ft_puthex(va_arg(args, int), tgt);
		else if (tgt == '%')
			ft_putchar_fd('%', 1);
		str = str + 2;
	}
	ft_putstr_fd(str, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	put_str((char *)str, args);
	va_end(args);
	return (ft_strlen(str));
}
