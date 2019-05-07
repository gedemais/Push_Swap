while [ 1 ]
do 
	ARG=`ruby -e "puts (0..999).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
done

