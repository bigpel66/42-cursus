# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker_true.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:09:33 by jseo              #+#    #+#              #
#    Updated: 2021/06/20 11:09:33 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo -e "\033[1;33mNo Arguments\033[0;0m"
RET=$(exec ./checker)
if [ "$RET" == "" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mAlready Sorted\033[0;0m"
RET=$(echo -e "" | exec ./checker 0 1 2)
if [ "$RET" == "OK" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 0 9 1 8 2\033[0;0m"
echo -e "\033[1;33mInstructions : pb ra pb ra sa ra pa pa\033[0;0m"
RET=$(echo -e "pb\nra\npb\nra\nsa\nra\npa\npa" | exec ./checker 0 9 1 8 2)
if [ "$RET" == "OK" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 4 5 1 2 3\033[0;0m"
echo -e "\033[1;33mInstructions : rra rra\033[0;0m"
RET=$(echo -e "rra\nrra" | exec ./checker 4 5 1 2 3)
if [ "$RET" == "KO" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""
