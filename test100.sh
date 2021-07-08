#!/bin/bash

NTESTS=100
count=1
avg=0
MAX=0
MIN=2147483647
while [ "$count" -le $NTESTS ]
do
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
	TOT=`./push_swap $ARG | wc -l`
	./push_swap $ARG | ./checker $ARG >> test.out
	if [ "$TOT" -ge "$MAX" ]
		then
			MAX=${TOT}
	fi
	if [ "$TOT" -le "$MIN" ]
		then
			MIN=${TOT}
	fi
	avg=$((avg+TOT))
	let "count += 1"
done

avg=$((avg/NTESTS))
echo -n "Average move count is :"
echo $avg
echo "MAX =${MAX}"
echo "MIN =${MIN}"

RES=`grep KO test.out`
if [ $RES ]
	then
		echo "$red $RES $reset"
	else
		echo "checker => $green OK ! $reset"
fi
