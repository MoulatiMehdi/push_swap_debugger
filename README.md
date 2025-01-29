# Push Swap Debugger

`push_swap` is a project that implements sorting algorithms using a stack-based approach. The goal is to sort a stack of integers using the fewest number of operations. This program allows users to interact with a game-like interface to simulate the sorting process using a set of predefined commands.

## Table of Contents

- [Compiling](#compiling)
- [Usage](#usage)
- [Commands](#commands)

## Compiling

To run `debug`, you need to have a C compiler installed on your system, such as `gcc`.

1. Clone the repository:

```bash
git clone https://github.com/MoulatiMehdi/push_swap_debugger.git
```
2. Navigate to the project directory and compile it to create an executable binary:

```bash
cd push_swap_debugger
make
```

## Usage

Once the project is compiled, you can run the program using:

```bash
./debug <numbers>
```
Where <numbers> are integers separated by spaces. For example:

```bash
./debug 3 2 1 5 4
```

## Commands :

After running the program, you can use the following commands to interact with the game and manipulate the stack:

`sa` - Swap the first two elements of stack A.

`sb` - Swap the first two elements of stack B.

`pa` - Push the top element of stack B to stack A.

`pb` - Push the top element of stack A to stack B.

`ra` - Rotate stack A (shift all elements up by 1).

`rb` - Rotate stack B (shift all elements up by 1).

`rra` - Reverse rotate stack A (shift all elements down by 1).

`rrb` - Reverse rotate stack B (shift all elements down by 1).

`rrr` - Reverse rotate both stacks A and B.  

`rr` - Rotate both stacks A and B.

`restart` or `re` - Restart the game with the initial input numbers.

`exit` or `q` - Exit the program.
