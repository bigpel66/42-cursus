#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ptr;
	int ft_len;
	int ori_len;

	// ft_len = ft_printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ft_len = ft_printf("% 0.20.16-+ #p", "hi");
	printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("\n");
	// ori_len = printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ori_len = printf("% 0.20.16-+ #p", "hi");
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	return (0);
}

// 1111 0000 0000 0000 0000 0000 0000 0000
// 0000 1111 0000 0000 0000 0000 0000 0000
