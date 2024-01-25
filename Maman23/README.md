# Permutation Checker

## Overview

A program that accepts two arguments on the command line: a name of an input file, and a string of characters.
The program will scan the contents of the file, and print to the standard output all the permutations of the string that will be found in the file.

**Files:**
- `permut.c`:  Utilizes the `is_permut` function to identify and print permutations found in the specified file.
- `permut.h`: Header file.
- `makefile.h`:

## Usage

To run the program, follow these steps:

1. **Compile the Code:**
   - Open a terminal and navigate to the directory containing the code.
   - Use the appropriate compiler command (e.g., `gcc`) to compile the code.

     ```bash
     gcc -o permutation_checker permut.c
     ```

2. **Run the Program:**
   - Execute the compiled program, providing the filename and the word to check for permutations.

     ```bash
     ./permutation_checker <filename> <word>
     ```

     Replace `<filename>` with the path to the text file and `<word>` with the word you want to check for permutations.

3. **Review Output:**
   - The program will display the identified permutations in the terminal.

## Program Structure

### `permut.h`

The header file contains the function prototype for `is_permut`, which checks for permutations.

### `permut.c`

The main source file contains the `main` function, which orchestrates the entire program. It opens the specified file, reads its contents, and checks for permutations using the `is_permut` function.

### `is_permut` Function

The `is_permut` function takes three parameters: a string representing the text file, an index for the starting position, and the word to check for permutations. It returns the length of the identified permutation and prints the permutation to the console. The function is utilized in a loop to scan the entire file for permutations.

## Example

```bash
./permutation_checker sample.txt abc
```
This command checks for permutations of the word "abc" in the "sample.txt" file.

## Notes
    - Ensure that you have the necessary permissions to read the specified file.
    - The word to check for permutations must have a length greater than 1.
    Feel free to customize and extend the program based on your specific requirements.
    Feel free to copy and paste this code into your README.md file.
    ```sql
    
Copy and paste this code into your README.md file. If you have any more requests or modifications, feel free to let me know!

    ```