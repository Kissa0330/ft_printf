/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:48:50 by rtakano           #+#    #+#             */
/*   Updated: 2022/06/03 20:36:50 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"
# define FORMAT_SIZE 2

int		ft_printf(const char *str, ...);
void	ft_putnbr(long long n, int *len);
int		ft_putpt(uintptr_t pt);
int		ft_puthex(int nbr, char format);
int		*ft_decimaltobinary(int num);
char	*ft_changehex(unsigned int nbr);

#endif