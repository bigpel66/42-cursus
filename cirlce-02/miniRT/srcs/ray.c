#include "minirt.h"

void ray_update(t_ray *r)
{
	r->cur = v_add(v_scale(r->a, r->t), r->b);
}

void camera_update(t_camera *c)
{

}
