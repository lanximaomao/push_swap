# <center>Push Swap - 42 School project</center>

## Description
Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from integers configuration to another, the most efficient sorting solution can differ.

In the programme, we will have a stacks named a and b. At the beginning, stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty.

The goal is to sort in ascending order numbers into stack a with lowest possible number of operations. Only following operations are allowed:

| Operations | descriptions |
| :------ | :----------- |
| sa      |    swap the first 2 elements at the top of stack a       |
| sb      |    swap the first 2 elements at the top of stack b       |
| ss      |    sa and sb at the same time       |
| pa      |    Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.       |
| pb      |    Take the first element at the top of a and put it at the top of b. Do nothing if a is empty      |
| ra      |    Shift up all elements of stack a by 1. The first element becomes the last one      |
| rb      |    Shift up all elements of stack b by 1. The first element becomes the last one       |
| rr      |    ra and rb at the same time       |
| rra     |    Shift down all elements of stack a by 1. The last element becomes the first one       |
| rrb     |    Shift down all elements of stack b by 1. The last element becomes the first one |
| rrr     |    rra and rrb at the same time       |

<br>

## Language used
[![Language used](https://skills.thijs.gg/icons?i=c)](https://skills.thijs.gg)

<br>

## Algorithm

![Algo](https://github.com/lanximaomao/push_swap/blob/46babb5b0899727e44a3320a2cb55fcd45ce0569/push_swap_algo.png)

<br>

## Bonus: Write your own checker
Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.

It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.

If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.

- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
- In case of error, you must display "Error" followed by a ’\n’ on the standard er- ror. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

<br>

## Usage
**1- To compile the programme:**

    Make

**2- Run your program with arguments:**

	./push_swap 5 3 2 -100
	ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

**3- Run your program with checker:**

	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

## Testing

*External links:*

+ [push_swap_tester](https://github.com/LeoFu9487/push_swap_tester.git)
+ [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
