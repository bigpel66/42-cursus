# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap_vsimple.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:09:43 by jseo              #+#    #+#              #
#    Updated: 2021/06/20 11:09:43 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG="2 1 0" ; echo -e "\033[1;33mArguments : $ARG\033[0;0m"
CNT=$(exec ./push_swap $ARG | wc -l)
if [ "$CNT" -gt 3 ]; then
	echo -e "CNT : [ \033[0;31mKO\033[0;0m ]\t"
else
	echo -e "CNT : [ \033[0;32mOK\033[0;0m ]\t"
fi
RET=$(exec ./push_swap $ARG | exec ./checker $ARG)
if [ "$RET" == "OK" ]; then
	echo -e "RET : [ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "RET : [ \033[0;31mKO\033[0;0m ]\n"
fi
ARG=""
CNT=""
RET=""

ARG="1 5 2 4 3" ; echo -e "\033[1;33mArguments : $ARG\033[0;0m"
CNT=$(exec ./push_swap $ARG | wc -l)
if [ "$CNT" -gt 12 ]; then
	echo -e "CNT : [ \033[0;31mKO\033[0;0m ]\t"
else
	echo -e "CNT : [ \033[0;32mOK\033[0;0m ]\t"
fi
RET=$(exec ./push_swap $ARG | exec ./checker $ARG)
if [ "$RET" == "OK" ]; then
	echo -e "RET : [ \033[0;32mOK\033[0;0m ]\n"
else
	echo -e "RET : [ \033[0;31mKO\033[0;0m ]\n"
fi
ARG=""
CNT=""
RET=""

echo -e "\033[1;33mAverage and Result of 5 Random Values Testing\033[0;0m\n"
SUM="0"
STAT="OK"
TEST="10"
for ((i = 0; i < $TEST; ++i))
do
	echo -e "\033[1;30mProcessing $(( i + 1 ))...\033[0;0m\x1b[1A\x1b[M"
	ARG=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')")
	CNT=$(exec ./push_swap $ARG | wc -l)
	RET=$(exec ./push_swap $ARG | exec ./checker $ARG)
	SUM=$(echo $(( SUM + CNT)))
	if [ "$RET" == "KO" ]; then
		STAT="KO"
	fi
done
SUM=$(echo $(( SUM / TEST)))
if [ "$STAT" == "OK" ]; then
	echo -e "RET : [ \033[0;32mOK\033[0;0m ] (avg \033[0;32m$SUM\033[0;0m instructions)\n"
else
	echo -e "RET : [ \033[0;31mKO\033[0;0m ] (avg \033[0;31m$SUM\033[0;0m instructions)\n"
fi
SUM=""
STAT=""
TEST=""
ARG=""
CNT=""
RET=""
