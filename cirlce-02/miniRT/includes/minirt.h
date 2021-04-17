#ifndef MINIRT_H
#define MINIRT_H

#include "mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct s_img
{
	void *id;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_img;

typedef struct s_mlx
{
	void *sid;
	void *wid;
	t_img *img;
} t_mlx;

int main(void);
void pre_setting(t_mlx *m);

#endif
