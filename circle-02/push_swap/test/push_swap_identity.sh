# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap_identity.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:09:29 by jseo              #+#    #+#              #
#    Updated: 2021/06/20 11:09:30 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo -e "\033[1;33mArguments : 42\033[0;0m"
RET=$(exec ./push_swap 42 | wc -l)
if [ "$RET" -eq 0 ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 0 1 2 3\033[0;0m"
RET=$(exec ./push_swap 0 1 2 3 | wc -l)
if [ "$RET" -eq 0 ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""
echo -e "\033[1;33mArguments : 0 1 2 3 4 5 6 7 8 9\033[0;0m"
RET=$(exec ./push_swap 0 1 2 3 4 5 6 7 8 9 | wc -l)
if [ "$RET" -eq 0 ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""
