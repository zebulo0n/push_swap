*This project has been created as part of the 42 curriculum by zoeschne.*

# push_swap

This project is about sorting algorithms : this version uses a greedy algorithm implemented with a longest increasing subsequence (LIS).

Sorts a stack of integers using a second stack and a limited set of operations (`sa sb ss pa pb ra rb rr rra rrb rrr`), in as few moves as possible.

## Usage

```sh
make
./push_swap 3 2 5 1 4
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG   # bonus
```
