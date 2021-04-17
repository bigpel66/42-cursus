#include "minirt.h"

void pre_setting(t_mlx *m)
{
	m->sid = mlx_init();
	m->wid = mlx_new_window(m->sid, 1920, 1080, "miniRT");
}

int main(void)
{
	t_mlx m;

	pre_setting(&m);
	mlx_loop(m.sid);
	return (0);
}
