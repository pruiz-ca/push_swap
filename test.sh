#/bin/bash

MIN=-$1/2
MAX=($1/2)-1
ARG=`ruby -e "puts ($MIN..$MAX).to_a.shuffle.join(' ')"`

make > /dev/null

printf "%s\n\n" "$ARG"
printf "checker_Mac: %s\n" "$(./push_swap $ARG | ./checker_Mac $ARG)"

if [[ $2 == "bonus" ]]; then
	make bonus > /dev/null
	printf "checker_bonus: %s\n" "$(./push_swap $ARG | ./checker $ARG)"
fi

printf "Moves: %s\n" "$(./push_swap $ARG | wc -l)"