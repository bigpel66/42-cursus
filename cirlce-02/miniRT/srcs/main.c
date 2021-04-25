/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:24:34 by jseo              #+#    #+#             */
/*   Updated: 2021/04/25 17:21:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		print_error_list(void)
{
	size_t	i;

	i = -1;
	while (++i < 107)
		printf("%zu: %s\n", i, strerror(i));
}

static char	*extract_basename(char *f, int *len)
{
	char	*tmp;

	while (1)
	{
		if (ft_strchr(f, '/'))
		{
			f = ft_strchr(f, '/');
			++f;
		}
		else
			break ;
	}
	tmp = ft_strchr(f, '.');
	*len = tmp - f;
	return (f);
}

int			main(int argc, char **argv)
{
	t_mlx	m;
	char	*f;
	int		len;

	if (argc < 2 || argc > 3)
		e_file_param();
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
		e_file_option();
	scene_open(&m, argv[1], CHECK);
	if (!scene_init(&(m.rt)) || !obj_init(&m))
		e_memory_alloc(&m);
	scene_open(&m, argv[1], PARSE);
	f = extract_basename(argv[1], &len);
	mlx_setup(&m, f);
	mlx_calc(&m);
	if (argc == 2)
		mlx_run(&m);
	else
		mlx_save(&m, f, len);
	mlx_free(&m);
	return (VALID);
}
