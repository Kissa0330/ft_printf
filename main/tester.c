/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:53:19 by rtakano           #+#    #+#             */
/*   Updated: 2022/05/31 22:33:04 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_printf(const char *str, ...);

int main(int argc, char const *argv[])
{
	int d = 3;
	unsigned int u = 2111111;
	char *str = "testtest";
	char c = 'a';
	int hex = 1234355674;
	void *arr = &hex;
	int res;

	//TODO ft_puthexの引数がマイナスの場合の動作が未定義
	ft_printf("///////////////////////////\nft_printf test\n");
	res = ft_printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	ft_printf("res == %d\n", res);
	ft_printf("///////////////////////////\n\n");
	printf("///////////////////////////\nprintf test\n");
	res = printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	printf("res == %d\n", res);
	printf("///////////////////////////\n");
	return 0;
}
	// ft_printf("///////////////////////////\nft_printf test\n");
	// res = ft_printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	// ft_printf("res == %d\n", res);
	// ft_printf("///////////////////////////\n\n");
	// printf("///////////////////////////\nprintf test\n");
	// res = printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	// printf("res == %d\n", res);
	// printf("///////////////////////////\n");
