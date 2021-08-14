# 🔀 push_swap
Algorithm to sort a stack of random numbers with the minimum possible number of operations. Currently it sorts 500 in less than 5500 movements.

![pushswap](https://user-images.githubusercontent.com/74905890/129445832-2c861a61-8135-4ac0-a660-8c4861ce0880.gif)  
*Visualizer made by [o-reo](https://github.com/o-reo/push_swap_visualizer)*

## Rules
- There are 2 stacks named A and B:
  - A starts with a random number of + or - numbers without duplicates.
  - B starts empty.

## Available operations:
  - sa: swap the first 2 elements at the top of stack A.
  - sb: swap the first 2 elements at the top of stack B.
  - ss: sa and sb at the same time.
  - ra: shift up all elements of stack A by 1. The first element becomes the last one.
  - rb: shift up all elements of stack B by 1. The first element becomes the last one.
  - rr: ra and rb at the same time.
  - rra: shift down all elements of stack A by 1. The last element becomes the first one.
  - rrb: shift down all elements of stack B by 1. The last element becomes the first one.
  - rrr: rra and rrb at the same time.
  - pa: take the first element of stack B and put it at the top of A.
  - pb: take the first element of stack A and put it at the top of B.

## Algorithm
First, thanks to [krios-fu](https://github.com/krios-fu) for the help and letting me use his ideas ✨.

1. This algorithm starts by converting all numbers to 0-n based on relative value. The smallest number will always be 0, the next one will be 1 and so on.
2. Then it starts rotating A and pushing numbers to B if it belongs to a chunk. The chunk size varies but for 100 numbers it's 30, so all numbers between 0-30 will be pushed to stack B as soon as it finds them in A. It does it in a 'sandwich' manner so half of the second chunk will be on top of chunk 1 and the other half at the bottom. This way it reduces movements by using rotations and reverse rotations to find the number we have to push back to stack A.
3. After all chunks are in stack B, it starts looking for the biggest number in stack B and pushes it to stack A.

## How to use
1. Run `make` at the root of the folder
2. Run `./push_swap num1 num2 ...` or `ARG="-65 2 412 5 295 9" ; ./push_swap $ARG`

## Checker program
It can be made by running `make bonus`. Run it like push_swap and introduce the list of operations that sorts those numbers. If the list actually sorts the numbers the checker returns 'OK', if not it returns 'KO'.

## Tester
I included it to make it easier for evaluations. It displays the numbers generated, the checker result and the number of instructions. To execute it push_swap and tester_Mac has to be in the same folder as "tester.sh".

It accepts two arguments:
- How many numbers to test
- Bonus

![pushswap-tester](https://user-images.githubusercontent.com/74905890/129448066-89b7c037-187d-4acb-a153-725535ef95e8.jpg)
