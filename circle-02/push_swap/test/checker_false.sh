# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker_false.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:09:35 by jseo              #+#    #+#              #
#    Updated: 2021/06/20 11:09:36 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo -e "\033[1;33mArguments : 0 9 1 8 2 7 3 6 4 5\033[0;0m"
echo -e "\033[1;33mInstructions : sa pb rrr\033[0;0m"
RET=$(echo -e "sa\npb\nrrr" | exec ./checker 0 9 1 8 2 7 3 6 4 5)
if [ "$RET" == "KO" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 1 3 5 2 6 4 8 10 9 7 11\033[0;0m"
echo -e "\033[1;33mInstructions : rrr rra pb ra pa pb pb rb pa pa\033[0;0m"
RET=$(echo -e "rrr\nrra\npb\nra\npa\npb\npb\nrb\npa\npa" | exec ./checker 1 3 5 2 6 4 8 10 9 7 11)
if [ "$RET" == "KO" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 4 5 1 2 3\033[0;0m"
echo -e "\033[1;33mInstructions : rra pa pa rrb sa pb pb\033[0;0m"
RET=$(echo -e "rra\npa\npa\nrrb\nsa\npb\npb" | exec ./checker 4 5 1 2 3)
if [ "$RET" == "KO" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""

echo -e "\033[1;33mArguments : 0 3 2 1\033[0;0m"
echo -e "\033[1;33mInstructions : ra\033[0;0m"
RET=$(echo -e "ra" | exec ./checker 0 3 2 1)
if [ "$RET" == "KO" ]; then
	echo -e "[ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "[ \033[0;31mKO\033[0;0m ]\n"
fi
RET=""
