#include "set.h"

/*
	The what_next function checks whether the sets entered by the user are correct, and returns an integer larger than ten, 
	 

	parameters:
			str - pointer to the entered string.
			counter - the index of the string.
	Return: 
		   an integer larger than ten if the values entered by the user are correct.
		   a code number that indicates the first error found

*/
int what_next(char *str, int *counter);

/*
	The vaild_int function checks whether the values entered by the user are complete, positive and within the range of 0 to 127.
	
	parameters:
			str - pointer to the entered string.
			array - the index of the string.

	Return: 
		   0 - if the values entered by the user are correct.
		   a code number that indicates the first error found
*/
int vaild_int(char *str, int *array);

/*
	The aild_comma function checks whether there are commands whose values are invalid characters.
	
	parameters:
			str - pointer to the entered string.
	Return: 
		0  - if the values entered by the user are correct.
		a code number that indicates the first error found.
*/
int vaild_comma(char *str);

/*
	The boot_sets function tests initializes all bits in sets to be zero.
	
	parameters:
			The six sets on which group operations are performed.
*/
void boot_sets(set* setA, set* setB, set* setC, set* setD, set* setE, set* setF);

