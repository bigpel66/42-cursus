#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft_len;
	int	ori_len;

	ft_len = ft_printf("asdf");
	ft_printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("\n");
	ori_len = printf("%s", "asdf");
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	return (0);
}
