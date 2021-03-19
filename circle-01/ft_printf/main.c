#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>


int main(void)
{
	int ft_len;
	int ori_len;

	wchar_t *s = (wchar_t *)L"🤡";
	wchar_t c = L'🤡';

	ft_len = ft_printf("%ls", 0);
	// ft_len = ft_printf("%10ls", "\U0001f921\U0001f921\U0001f921\U0001f921");
	// ft_len = ft_printf("%10lc", 127);
	// ft_len = ft_printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("ft bytes : %d\n", ft_len);

	printf("\n");
	ori_len = printf("%lc", 0);
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
