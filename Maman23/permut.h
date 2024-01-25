#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    by Yael Gluskin 213303035
    This program takes 3 arguments from the terminal.
    The program accepts a file name and a word, and prints the permutations of the word found in the file.
*/


int is_permut(char *string, int index, char *word, int *status);
/*
    The function receives a string (the file), an index in it, a word whose permutations will be checked and a pointer to the status.
    The function checks if there is a permut. If so, she will print it, update the status and return the length of the exchange.
	If not she will return one.
	
	    parameters:
	        string - A pointer string containing the file.
	        index - An integr index to the string containing the file.
	        word - The current word being tested (basically any character from which the start of a word is considered).
	        status - A pointer to the variable integer in that changes if there is a permut.
	        
	   return: 
	        An integer, if a permutation is found then its length, and if not -  one.
*/
