/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:15:44 by jseo              #+#    #+#             */
/*   Updated: 2021/05/03 17:59:01 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		sign_double(char **s)
{
	if (**s == '-')
	{
		++(*s);
		return (-1);
	}
	return (1);
}

static t_bool	integer_double(char **s, int *i)
{
	if (is_digit(**s))
	{
		while (is_digit(**s))
			*i = *i * 10 + (*((*s)++) - '0');
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	fraction_double(char **s, double *f)
{
	int	i;

	i = 0;
	++(*s);
	if (is_digit(**s))
	{
		while (is_digit(**s))
			*f += pow(10, --i) * (*((*s)++) - '0');
		return (TRUE);
	}
	return (FALSE);
}

t_bool			udouble(char **s, double *v)
{
	int		sign;
	int		i;
	double	f;

	i = 0;
	f = 0.0;
	if (!s || !(*s))
		return (FALSE);
	while (is_blank(**s))
		++(*s);
	sign = sign_double(s);
	if (!integer_double(s, &i))
		return (FALSE);
	if (**s == '.')
		if (!fraction_double(s, &f))
			return (FALSE);
	*v = ((double)i + f) * sign;
	return (TRUE);
}

t_bool			sdouble(char **s, double *v1, double *v2, double *v3)
{
	*v1 = 0.0;
	*v2 = 0.0;
	*v3 = 0.0;
	while (is_blank(**s))
		++(*s);
	if (!is_digit(**s) && **s != '-')
		return (FALSE);
	if (!udouble(s, v1) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!udouble(s, v2) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!udouble(s, v3))
		return (FALSE);
	return (TRUE);
}
