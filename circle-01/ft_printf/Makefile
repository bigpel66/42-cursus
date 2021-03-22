# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 16:08:00 by jseo              #+#    #+#              #
#    Updated: 2021/03/09 22:52:13 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
AR			=	ar rc

NAME		=	libftprintf.a
HEADER		=	includes

FOLDER		=	srcs
BNS_FOLDER	=	bonus_srcs

SRC_LIST	=	console_out.c				\
				dalloc.c					\
				form_init.c					\
				form_read.c					\
				form_write.c				\
				free_ptr.c					\
				ft_memset.c					\
				ft_printf.c					\
				ft_strchr.c					\
				ft_strlen.c					\
				ft_wcheck_mb_cur_max.c		\
				ft_wputchar_fd.c			\
				ft_wputstr_fd.c				\
				ft_wstrlen.c				\
				ft_wtob.c					\
				get_dec_signed.c			\
				get_dec_unsigned.c			\
				get_flag.c					\
				get_hex.c					\
				get_index.c					\
				get_length.c				\
				get_oct.c					\
				get_precision.c				\
				get_width.c					\
				is_digit.c					\
				is_error.c					\
				is_flag.c					\
				is_length.c					\
				is_type.c					\
				padd_non_str.c				\
				padd_str.c					\
				padd_swap.c					\
				padd_with_dot.c				\
				padd_without_dot.c			\
				parse_check.c				\
				parse_format.c				\
				prnt_dec_signed.c			\
				prnt_dec_unsigned.c			\
				prnt_hex.c					\
				prnt_oct.c					\
				prnt_str.c					\
				prnt_wstr.c					\
				process_asterisk.c			\
				process_bonus.c				\
				process_dot.c				\
				process_length_nbr.c		\
				process_length_nothing.c	\
				process_length_str.c		\
				process_nbr_h.c				\
				process_nbr_hh.c			\
				process_nbr_l.c				\
				process_nbr_ll.c			\
				process_nbr.c				\
				process_nothing_h.c			\
				process_nothing_hh.c		\
				process_nothing_l.c			\
				process_nothing_ll.c		\
				process_nothing.c			\
				process_str_l.c				\
				process_str.c
BNS_SRC_LIST	=	console_out_bonus.c				\
					dalloc_bonus.c					\
					form_init_bonus.c				\
					form_read_bonus.c				\
					form_write_bonus.c				\
					free_ptr_bonus.c				\
					ft_memset_bonus.c				\
					ft_printf_bonus.c				\
					ft_strchr_bonus.c				\
					ft_strlen_bonus.c				\
					ft_wcheck_mb_cur_max_bonus.c	\
					ft_wputchar_fd_bonus.c			\
					ft_wputstr_fd_bonus.c			\
					ft_wstrlen_bonus.c				\
					ft_wtob_bonus.c					\
					get_dec_signed_bonus.c			\
					get_dec_unsigned_bonus.c		\
					get_flag_bonus.c				\
					get_hex_bonus.c					\
					get_index_bonus.c				\
					get_length_bonus.c				\
					get_oct_bonus.c					\
					get_precision_bonus.c			\
					get_width_bonus.c				\
					is_digit_bonus.c				\
					is_error_bonus.c				\
					is_flag_bonus.c					\
					is_length_bonus.c				\
					is_type_bonus.c					\
					padd_non_str_bonus.c			\
					padd_str_bonus.c				\
					padd_swap_bonus.c				\
					padd_with_dot_bonus.c			\
					padd_without_dot_bonus.c		\
					parse_check_bonus.c				\
					parse_format_bonus.c			\
					prnt_dec_signed_bonus.c			\
					prnt_dec_unsigned_bonus.c		\
					prnt_hex_bonus.c				\
					prnt_oct_bonus.c				\
					prnt_str_bonus.c				\
					prnt_wstr_bonus.c				\
					process_asterisk_bonus.c		\
					process_bonus_bonus.c			\
					process_dot_bonus.c				\
					process_length_nbr_bonus.c		\
					process_length_nothing_bonus.c	\
					process_length_str_bonus.c		\
					process_nbr_h_bonus.c			\
					process_nbr_hh_bonus.c			\
					process_nbr_l_bonus.c			\
					process_nbr_ll_bonus.c			\
					process_nbr_bonus.c				\
					process_nothing_h_bonus.c		\
					process_nothing_hh_bonus.c		\
					process_nothing_l_bonus.c		\
					process_nothing_ll_bonus.c		\
					process_nothing_bonus.c			\
					process_str_l_bonus.c			\
					process_str_bonus.c

SRCS		=	$(addprefix $(FOLDER)/, $(SRC_LIST))
BNS_SRCS	=	$(addprefix $(BNS_FOLDER)/, $(BNS_SRC_LIST))

OBJS		=	$(SRCS:.c=.o)
BNS_OBJS	=	$(BNS_SRCS:.c=.o)

%.o		:	%.c
		$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)	:	$(OBJS)
		$(AR) $(NAME) $(OBJS)

.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
		$(RM) $(OBJS)
		$(RM) $(BNS_OBJS)

.PHONY	:	fclean
fclean	:	clean
		$(RM) $(NAME)

.PHONY	:	re
re		:	fclean all

.PHONY	:	bonus
bonus	:	$(BNS_OBJS)
		$(AR) $(NAME) $(BNS_OBJS)
