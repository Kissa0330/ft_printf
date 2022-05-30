#include <stdio.h>
int ft_printf(const char *str, ...);

int main(int argc, char const *argv[])
{
	int d = 3;
	unsigned int u = 2111111;
	char *str = "str";
	char c = 'a';
	void *arr = &c;
	int hex = -25;

	//TODO ft_puthexの引数がマイナスの場合の動作が未定義
	ft_printf("///////////////////////////\nft_printf test\n");
	ft_printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	ft_printf("///////////////////////////\n\n");
	printf("///////////////////////////\nprintf test\n");
	printf("nbr_test1 = %d /// nbr_test2 = %u /// string_test = %s /// char_test = %c /// percent_test = %% /// pointer_test = %p /// hex_test = %x, %X\n", d, u, str, c, arr, hex, hex);
	printf("///////////////////////////\n");
	return 0;
}
