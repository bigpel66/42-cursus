/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:50:51 by jseo              #+#    #+#             */
/*   Updated: 2021/04/22 17:09:51 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		to_string_sq(t_square *sq, int idx)
{
	ostream_title("Square", idx);
	ostream_vector(&(sq->p), "Square Position\t\t");
	ostream_vector(&(sq->o), "Square Orientation\t");
	ostream_floating_point(sq->l, "Square Side Length\t");
	ostream_color(&(sq->c), "Square Color\t\t");
	printf("\n");
}

static t_bool	valid_sq(t_square *sq, int idx)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(sq->o))
		ret = FALSE;
	if (sq->l <= 0.0)
		ret = FALSE;
	if (!valid_color(sq->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid square value\n", 29);
	to_string_sq(sq, idx + 1);
	return (ret);
}

static t_bool	parse_sq(t_square *sq, char *line)
{
	t_bool	ret;
	int		r;
	int		g;
	int		b;

	ret = TRUE;
	if (!sdouble(&line, &(sq->p.x), &(sq->p.y), &(sq->p.z)))
		ret = FALSE;
	if (!sdouble(&line, &(sq->o.x), &(sq->o.y), &(sq->o.z)))
		ret = FALSE;
	if (!udouble(&line, &(sq->l)))
		ret = FALSE;
	if (!sint(&line, &r, &g, &b))
		ret = FALSE;
	c_init(&(sq->c), r, g, b);
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Wrong parsing square\n", 29);
	return (ret);
}

t_bool			get_square(t_scene *rt, char *line)
{
	static int	i;

	if (!parse_sq(&((rt->sq)[i]), line) || !valid_sq(&((rt->sq)[i]), i))
		return (FALSE);
	++i;
	return (TRUE);
}

t_bool			chk_square(t_scene *rt)
{
	++(rt->cnt.sq);
	return (TRUE);
}
