#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int main(void)
{
	setlocale(1, "");

	int ft_len;
	int ori_len;

	// ft_len = ft_printf("%lc %lc %lc\n", L'ä', L'ö', L'ü');
	// ft_len = ft_printf("%10lc %-6.10-20lc\n", L'ä', L'ö', L'ü');
	ft_len = ft_printf("%ls\n", L"🤗 💯 🌍 🚀 🔴 ");
	// ft_len = ft_printf("%10ls", "\U0001f921\U0001f921\U0001f921\U0001f921");
	// ft_len = ft_printf("%10lc", 127);
	// ft_len = ft_printf("this is for the test%n\n", ptr);
	printf("\n");
	printf("ft bytes : %d\n", ft_len);

	printf("\n");
	// ori_len = printf("%lc %lc %lc\n", L'ä', L'ö', L'ü');
	// ori_len = printf("%10lc %-6.10-20lc\n", L'ä', L'ö', L'ü');
	ori_len = printf("%ls\n", L"🤗 💯 🌍 🚀 🔴 ");
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
