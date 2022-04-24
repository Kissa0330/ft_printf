#include "ft_printf.h"

void	put_str(char *str, va_list args)
{
	size_t	len;

	len = 0;
	while(ft_strchr(str, '%') != NULL)
	{
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, '%'));
		while (len--)
			ft_putchar_fd(*str++, 1);
		if(*(str + 1) == 'd' || *(str + 1) == 'i')
			ft_putnbr_fd(va_arg(args, int), 1);
		else if(*(str + 1) == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if(*(str + 1) == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
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
