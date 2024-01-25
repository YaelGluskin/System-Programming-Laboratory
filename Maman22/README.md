# Set Operations Program

## Overview
This program performs set operations on six sets (A, B, C, D, E, F) using various commands. It includes C files for set operations (`myset.c`), set functions (`set.h`), and validation functions (`valid_func.h`).

## Files
- `myset.c`: Main program that utilizes set operations and functions.
- `set.h`: Header file defining set operations and functions.
- `valid_func.h`: Header file containing validation functions for the program.

## Set Operations
- `read_set`: Reads integer values (0-127) into a set.
- `print_set`: Prints the elements of a set.
- `union_set`: Performs the union of two sets.
- `intersect_set`: Performs the intersection of two sets.
- `sub_set`: Performs the subtraction of one set from another.
- `symdiff_set`: Performs the symmetrical difference of two sets.
- `stop`: Exits the program.

## How to Run
1. Open a terminal in the project directory.
2. Run the following commands:
    ```bash
    make
    ./myset
    ```
   (Note: On Ubuntu, the `make` command should work out of the box.)

## Additional Notes
- Ensure you have a compatible C compiler (e.g., GCC) installed on your system.
- If running on Windows with MinGW, use `mingw32-make` instead of `make`.

Feel free to contact [your email] for any issues or inquiries.

