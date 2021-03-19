#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int *ptr;

	int ft_len;
	int ori_len;

	wchar_t *s = (wchar_t *)"하이";
	wchar_t c = L'🤡';
	// unsigned long long lu = (unsigned long long);

	*ptr = 10;
	// printf("ptr value: %p\n", ptr);
	// printf("ptr adr val : %p\n", &ptr);

	ft_len = ft_printf("%lc", c);
	// ft_len = ft_printf("%10ls", "\U0001f921\U0001f921\U0001f921\U0001f921");
	// ft_len = ft_printf("%10lc", 127);
	// ft_len = ft_printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("ft bytes : %d\n", ft_len);
	// printf("ft ptr: %d\n", *ptr);
	printf("\n");
	ori_len = printf("%lc", c);
	// ori_len = printf("%10ls", (wchar_t *)"\U0001f921");
	// ori_len = printf("%10lc", 127);
	// ori_len = printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	// printf("original ptr: %d\n", *ptr);
	return (0);
}

// 1111 0000 0000 0000 0000 0000 0000 0000
// 0000 1111 0000 0000 0000 0000 0000 0000
