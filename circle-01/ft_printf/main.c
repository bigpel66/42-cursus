#include "ft_printf.h"
#include <stdio.h>

/*int main(void)
{
	// int ptr;
	int ft_len;
	int ori_len;

	// ft_len = ft_printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ft_len = ft_printf("452bb[%0*u]", 222, 7);
	printf("\n");
	printf("ft bytes : %d\n", ft_len);
	printf("\n");
	// ori_len = printf("%10.2*0+.3-203.50#s", 3, "asasdfasdf");
	ori_len = printf("452bb[%0*u]", 222, 7);
	printf("\n");
	printf("original bytes : %d\n", ori_len);
	return (0);
}*/

#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main()
{
	printf("/********************     %%u     *******************/\n\n");

	int array_size = 5;
	int i = 0;
	unsigned int nb[] = { 0, 6, 451, 2000000, UINT_MAX };

	while (i < array_size)
	{
		printf("-------------------- start while loop with nb[%u] "
			   "--------------------\n\n",
			   nb[i]);

		printf("%d\n\n", printf("1 [%u]", nb[i]));
		printf("%d\n\n", ft_printf("1 [%u]", nb[i]));

		printf("%d\n\n", printf("1.1 [%5u]", nb[i]));
		printf("%d\n\n", ft_printf("1.1 [%5u]", nb[i]));

		printf("%d\n\n", printf("2 [%05u]", nb[i]));
		printf("%d\n\n", ft_printf("2 [%05u]", nb[i]));

		printf("%d\n\n", printf("2.2 [%0u]", nb[i]));
		printf("%d\n\n", ft_printf("2.2 [%0u]", nb[i]));

		printf("%d\n\n", printf("3 ! [%.u]", nb[i]));
		printf("%d\n\n", ft_printf("3 ! [%.u]", nb[i]));

		printf("%d\n\n", printf("3.1 ! [%.0u]", nb[i]));
		printf("%d\n\n", ft_printf("3.1 ! [%.0u]", nb[i]));

		printf("%d\n\n", printf("3.2 ! [%.5u]", nb[i]));
		printf("%d\n\n", ft_printf("3.2 ! [%.5u]", nb[i]));

		printf("%d\n\n", printf("3.3 ! [%0.5u]", nb[i]));
		printf("%d\n\n", ft_printf("3.3 ! [%0.5u]", nb[i]));

		printf("%d\n\n", printf("3.4 ![%10.u]", nb[i]));
		printf("%d\n\n", ft_printf("3.4 ![%10.u]", nb[i]));

		printf("%d\n\n", printf("3.5 ! [%5.0u]", nb[i]));
		printf("%d\n\n", ft_printf("3.5 ! [%5.0u]", nb[i]));

		printf("%d\n\n", printf("3.6 ! [%.10u]", nb[i]));
		printf("%d\n\n", ft_printf("3.6 ! [%.10u]", nb[i]));

		printf("%d\n\n", printf("3.7 ! [%10.6u]", nb[i]));
		printf("%d\n\n", ft_printf("3.7 ! [%10.6u]", nb[i]));

		printf("%d\n\n", printf("4 [%010.5u]", nb[i]));
		printf("%d\n\n", ft_printf("4 [%010.5u]", nb[i]));

		printf("%d\n\n", printf("5 [%-5d]", nb[i]));
		printf("%d\n\n", ft_printf("5 [%-5d]", nb[i]));

		printf("%d\n\n", printf("5.1 ![%-.5d]", nb[i]));
		printf("%d\n\n", ft_printf("5.1 ![%-.5d]", nb[i]));

		int nb_2[] = { -444, -5, 0, -0, 7, 222, 555 };
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)
		{
			printf("\n**********  [  * loop with %d ]  *********\n\n", nb_2[i_2]);

			printf("%d\n\n", printf("10 [%*u]", nb_2[i_2], nb[i]));
			printf("%d\n\n", ft_printf("10 [%*u]", nb_2[i_2], nb[i]));

			printf("%d\n\n", printf("11 [%*.u]", nb_2[i_2], nb[i]));
			printf("%d\n\n", ft_printf("11 [%*.u]", nb_2[i_2], nb[i]));

			printf("%d\n\n", printf("12 [%*.0u]", nb_2[i_2], nb[i]));
			printf("%d\n\n", ft_printf("12 [%*.0u]", nb_2[i_2], nb[i]));

			printf("%d\n\n", printf("13 [%*.*u]", nb_2[i_2], nb_2[i], nb[i]));
			printf("%d\n\n", ft_printf("13 [%*.*u]", nb_2[i_2], nb_2[i], nb[i]));

			printf("%d\n\n", printf("453[%0*.*u]", nb_2[i], nb_2[i], nb[i]));
			printf("%d\n\n", ft_printf("453[%0*.*u]", nb_2[i], nb_2[i], nb[i]));

			printf("%d\n\n", printf("453a [%010.*u]", nb_2[i_2], nb[i]));
			printf("%d\n\n", ft_printf("453a [%010.*u]", nb_2[i_2], nb[i]));

			printf("%d\n\n", printf("441[%5.*u]", nb_2[i_2], nb[i]));
			printf("%d\n\n", ft_printf("441[%5.*u]", nb_2[i_2], nb[i]));

			printf("%d\n\n", printf("452bb[%0*u]", nb_2[i_2], 7));
			printf("%d\n\n", ft_printf("452bb[%0*u]", nb_2[i_2], 7));

			printf("%d\n\n", printf("453b !! [%0*.*u]", nb_2[i_2], nb_2[i_2], 7));
			printf("%d\n\n", ft_printf("453b !! [%0*.*u]", nb_2[i_2], nb_2[i_2], 7));
			i_2++;
		}
		i++;
	}

	printf("%d\n\n", printf("453c[%0*.*u]", -5, -10, -7));
	printf("%d\n\n", ft_printf("453c[%0*.*u]", -5, -10, -7));
	printf("%d\n\n", printf("453b !![%0*.*u]", 5, 10, 7));
	printf("%d\n\n", ft_printf("453b !![%0*.*u]", 5, 10, 7));
	printf("%d\n\n", printf("453d[%0*.*u]", -5, 10, -7));
	printf("%d\n\n", ft_printf("453d[%0*.*u]", -5, 10, -7));
	printf("%d\n\n", printf("453e[%0*.*u]", 5, -10, -7));
	printf("%d\n\n", ft_printf("453e[%0*.*u]", 5, -10, -7));
	printf("%d\n\n", printf("453f[%*.*u]", -5, -10, -7));
	printf("%d\n\n", ft_printf("453f[%*.*u]", -5, -10, -7));
	printf("%d\n\n", printf("453g[%*.*u]", 5, 10, 7));
	printf("%d\n\n", ft_printf("453g[%*.*u]", 5, 10, 7));
	printf("%d\n\n", printf("453h[%-*.*u]", 5, 10, 7));
	printf("%d\n\n", ft_printf("453h[%-*.*u]", 5, 10, 7));
}

// 1111 0000 0000 0000 0000 0000 0000 0000
// 0000 1111 0000 0000 0000 0000 0000 0000
