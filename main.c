#include <stdio.h>
int ft_printf(const char *str, ...);

int main(int argc, char const *argv[])
{
	ft_printf("///////////////////////////\nft_printf test\n");
	ft_printf("1 = %d /// 2 = %s\n", 2, "str");
	return 0;
}
