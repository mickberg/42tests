#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_base_convert.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 18:39:18 by mberglun          #+#    #+#              #
#    Updated: 2019/12/18 20:46:44 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT=$(dirname "$0")
source "$ROOT/vars.sh"

START=0
END=1000
IN=10;
OUT=10;
PRINT=0

while getopts 's:e:i:o:p' opt
do
	case $opt in
		s) START=$OPTARG ;;
		e) END=$OPTARG ;;
		i) IN=$OPTARG ;;
		o) OUT=$OPTARG ;;
		p) PRINT=1 ;;
	esac
done

if [[ $PRINT -eq 1 ]]; then 
	echo -e "\033[2J"
else
# keep one empty line for errors 
# TODO mvoe only on first error
	echo ""
fi

i=$START
while [ $i -lt $END ]; do
	nb=$(echo "obase=$IN; $i" | bc)
	ob=$(echo "obase=$IN; $OUT" | bc)

	test=$($ROOT/../printf $nb $IN $OUT)
	exp=$(echo "ibase=$IN; obase=$ob; $nb" | bc)
	echo "$test" > test_tmp
	echo "$exp" > exp_tmp
	diff=$(diff exp_tmp test_tmp)

	if [[ ! -z "$diff" ]]; then
		echo -en "\033[1A\r\033[K"
		echo -en "$red"
		echo -en "Error on $nb in base $IN. expected: $exp got: $test"
		echo -en "$def"
		echo -en "\n\r\033[K\033[1B\n"
	elif [[ $PRINT -eq 1 ]]; then
		echo -en "\033[1A\r\033[K"
		echo -en "$green"
		echo -en "$nb\t> $test"
		echo -en "$def"
		echo -en "\n\r\033[K\033[1B\n"
	fi

	echo -en "\r\033[K"
	echo -en "Testing input $cyan$nb$def in base $lmagenta$IN$def"
	echo -en ", converting to base $lmagenta$OUT$def ($i)"
	i=$((i+1))
done

# remove temporary files
rm test_tmp exp_tmp
