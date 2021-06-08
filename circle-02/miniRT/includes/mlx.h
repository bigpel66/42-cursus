/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:53:02 by jseo              #+#    #+#             */
/*   Updated: 2021/04/30 14:57:58 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD 		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

void			*mlx_init(void);
void			*mlx_new_window(void *m_ptr, int x, int y, char *title);
int				mlx_clear_window(void *m_ptr, void *w_ptr);
int				mlx_pixel_put(void *m_ptr, void *w_ptr, int x, int y, int c);
void			*mlx_new_image(void *m_ptr, int x, int y);
char			*mlx_get_data_addr(void *i_ptr, int *bpp, int *sl, int *en);
int				mlx_put_image_to_window(void *m_ptr, void *w_ptr, void *i_ptr,
						int x, int y);
unsigned int	mlx_get_color_value(void *m_ptr, int c);
int				mlx_mouse_hook(void *w_ptr, int (*funct_ptr)(), void *p);
int				mlx_key_hook(void *w_ptr, int (*funct_ptr)(), void *p);
int				mlx_expose_hook(void *w_ptr, int (*funct_ptr)(), void *p);
int				mlx_loop_hook(void *m_ptr, int (*funct_ptr)(), void *p);
int				mlx_loop(void *m_ptr);
int				mlx_string_put(void *m_ptr, void *w_ptr, int x, int y,
						int c, char *s);
void			*mlx_xpm_to_image(void *m_ptr, char **xpm_data,
						int *x, int *y);
void			*mlx_xpm_file_to_image(void *m_ptr, char *filename,
						int *x, int *y);
void			*mlx_png_file_to_image(void *m_ptr, char *file, int *x, int *y);
int				mlx_destroy_window(void *m_ptr, void *w_ptr);
int				mlx_destroy_image(void *m_ptr, void *i_ptr);
int				mlx_hook(void *w_ptr, int x_event, int x_mask,
						int (*funct)(), void *p);
int				mlx_mouse_hide(void);
int				mlx_mouse_show(void);
int				mlx_mouse_move(void *w_ptr, int x, int y);
int				mlx_mouse_get_pos(void *w_ptr, int *x, int *y);
int				mlx_do_key_autorepeatoff(void *m_ptr);
int				mlx_do_key_autorepeaton(void *m_ptr);
int				mlx_do_sync(void *m_ptr);
int				mlx_sync(int cmd, void *p);
int				mlx_get_screen_size(void *m_ptr, int *sizex, int *sizey);

#endif
