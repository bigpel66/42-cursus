#include "minirt.h"

static void to_string_co(t_cone *co, int idx)
{

}

static t_bool	valid_co(t_cone *co, int idx)
{
	t_bool ret;

	ret = TRUE;
	if (!valid_color(co->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Detail: Invalid cone value\n", 27);
	to_string_co(co, idx + 1);
	return (ret);
}

static t_bool	parse_co(t_cone *co, char *line)
{
	t_bool ret;
	int r;
	int g;
	int b;

	ret = TRUE;

	return (ret);
}

t_bool 	get_cone(t_scene *rt, char *line)
{
	static i;

	if (!parse_co(&((rt->co)[i]), line) || !valid_co(&((rt->co)[i]), i))
		return (FALSE);
	++i;
	return (TRUE);
}

t_bool chk_cone(t_scene *rt)
{
	++(rt->cnt.co);
	++(rt->cnt.obj);
	return (TRUE);
}

