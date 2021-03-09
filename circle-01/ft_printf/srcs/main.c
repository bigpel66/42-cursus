#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft_len;
	int	ori_len;

	ft_len = ft_printf("asdf%d");
	ft_printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("\n");
	ori_len = printf("%s", "asdf%d");
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	return (0);
}
