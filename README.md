# PushSwap
Push Swap: Algorithmic project 

<pre>
The Push swap project is a very simple and a highly straightforward algorithm project:
data must be sorted.<br>
The main goal is to sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions.
</pre>


## The rules
*  You have 2 stacks named a and b. <br>
*  At the beginning: <br>
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated. <br>
◦ The stack b is empty. <br>
*  The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal <br>


| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |


## Execution
After cloning the repository to execute the program type the command below <br>
 <b> make </b> <br>
 <b> ./push_swap arguments </b> <br>
 
 ### Example
 <pre>
 $>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
</pre>
