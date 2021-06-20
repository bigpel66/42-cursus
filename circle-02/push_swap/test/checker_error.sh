# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker_error.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:09:18 by jseo              #+#    #+#              #
#    Updated: 2021/06/20 11:09:18 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo -e "\033[1;33m1. Non-Numeric Test\033[0;0m"
RET=$(exec ./checker non-numeric 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33m2. Duplicate Test\033[0;0m"
RET=$(exec ./checker 1 1 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33m3. Range Test\033[0;0m"
RET=$(exec ./checker 2147483648 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]"
fi
RET=$(exec ./checker -2147483649 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33m4. Instruction Test\033[0;0m"
RET=$(echo -e "pa\nsa\nasdf" | exec ./checker 1 2 3 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]"
fi
RET=$(echo -e "pa\nsa\t\t\n" | exec ./checker 1 2 3 2>&1) || true
if [ "$RET" == "Error" ]; then
	echo -e "[ \033[1;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[1;31mKO\033[0;0m ]\n"
fi
RET=""
