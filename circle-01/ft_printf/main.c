#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int *ptr;
	int ft_len;
	int ori_len;

	*ptr = 10;
	printf("ptr value: %p\n", ptr);
	printf("ptr adr val : %p\n", &ptr);
	// ft_len = ft_printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ft_len = ft_printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("ft ptr: %d\n", *ptr);
	printf("\n");
	// ori_len = printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ori_len = printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	printf("original ptr: %d\n", *ptr);
	return (0);
}

// 1111 0000 0000 0000 0000 0000 0000 0000
// 0000 1111 0000 0000 0000 0000 0000 0000
