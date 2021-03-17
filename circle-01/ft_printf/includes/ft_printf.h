#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	int fd;
	ssize_t size;

	long long i;
	long long dig;

	unsigned char flg;
	long long width;
	long long prec;
	unsigned char len;
	int t;
} t_form;

char *allocate_null_str(void);
int allocate_with_dot(t_form *f, char **p, char **s, int padd);
int allocate_without_dot(t_form *f, char **p, char **s, int padd);

t_form *form_create(t_form *f);
void form_init(t_form *f);
void form_read(t_form *f, const char *format, va_list ap);
void form_write(t_form *f, va_list ap);

void free_unit_ptr(void **ptr);
void free_multi_ptr(void **optr, void **pptr, void **ptr);

void *ft_calloc(size_t cnt, size_t n);
void *ft_memset(void *s, int c, size_t n);
int ft_printf(const char *format, ...);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);

char *get_dec(t_form *f, long long val);
void get_flag(t_form *f, const char *format, va_list ap);
char *get_hex(t_form *f, unsigned long long val, int capital);
int get_index(const char *s, char c);
void get_length(t_form *f, const char *format);
long long get_precision(t_form *f, const char *format);
int get_width(t_form *f, const char *format);

int is_digit(int c);
int is_error(t_form *f);
int is_flag(int c);
int is_length(int c);
int is_type(int c);

int padd_non_str(t_form *f, char **p, char **s, int padd);
char *padd_str(t_form *f, long long *p_len, int string);

int parse_check(const char *format, va_list ap);
int parse_format(t_form *f, const char *format, va_list ap);

int print_dec(t_form *f, long long arg, int sign);
int print_hex(t_form *f, unsigned long long val, int capita, int adr);
int print_str(t_form *f, char *s, int string);

void process_asterisk(t_form *f, va_list ap);
int process_bonus(t_form *f, va_list ap);
int process_nbr(t_form *f, va_list ap);
void process_dot(t_form *f, const char *format, va_list ap);
int process_str(t_form *f, va_list ap);

#endif
