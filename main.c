#include <stdio.h>
int ft_printf(const char *str, ...);

int main(int argc, char const *argv[])
{
	int d = 3;
	char *str = "str";
	char c = 'a';
	ft_printf("///////////////////////////\nft_printf test\n");
	ft_printf("nbr_test = %d /// string_test = %s /// char_test = %c\n", d, str, c);
	ft_printf("///////////////////////////\n\n");
	printf("///////////////////////////\nprintf test\n");
	printf("nbr_test = %d /// string_test = %s /// char_test = %c\n", d, str, c);
	printf("///////////////////////////\n");
	return 0;
}
