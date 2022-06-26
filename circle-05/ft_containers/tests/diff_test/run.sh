#!/bin/bash
# Copyright @nesvoboda
# Modified by @bigpel66

test_container () {
    printf "\n\e[34m$1: \e[0m"
    (time ./run_$1.sh) 2> >( awk 'NR==2{print $2}')
    printf "Diff: "

    DIFF=$(diff std_output_$1 test_output_$1)
    if [ "$DIFF" != "" ] 
    then
        echo -e "\033[1;31m[FAIL]\033[0m\n"
    else
        echo -e "\033[1;32m[PASS]\033[0m\n"
    fi
}

printf "\033[1;94m\
# ****************************************************************************** #
#                                                                                #
#                              containers diff test                              #
#                                                                                #
# ****************************************************************************** #
\033[0m"

test_container "map"
test_container "set"
test_container "stack"
test_container "vector"
