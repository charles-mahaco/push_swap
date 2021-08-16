
<!-- ABOUT THE PROJECT -->
## About The Project
The program is made up of two stacks of numbers named A and B.
In the beginning, B will be empty and A will contain a certain amount of positive or negative numbers.
The obective is to sort A.

##### In order to do this, we will only have access to the following operation:
* `sa` swap the first two elements of A (nothing will happen if there aren’t enough elements).
* `sb` swap the first two elements of A (nothing will happen if there aren’t enough elements).
* `sc` sa and sb at the same time.
* `pa` take the first element from B and move it to the first position on the A list (nothing will happen if B is empty).
* `pb` take the first element from A and move it to the first position on the B list (nothing will happen if A is empty).
* `ra` rotate A toward the beginning, the first element will become the last.
* `rb` rotate B toward the beginning, the first element will become the last.
* `rr` ra and rb at the same time.
* `rra` rotate A toward the end, the last element will become the first.
* `rrb` rotate B toward the end, the last element will become the first.
* `rrr` rra and rrb at the same time.

### Built With
* Makefile using gcc

<!-- GETTING STARTED -->
## Getting Started
Test the program with your list of number as parameter
```shh
./push_swap 1 12 3 -4
```
