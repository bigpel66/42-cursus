#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ft_len;
	int ori_len;

	ft_len = ft_printf("%10.2*0+.3s", 3, "asasdfasdf");
	ft_printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("\n");
	ori_len = printf("%10.2*0+.3s", 3, "asasdfasdf");
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	return (0);
}
