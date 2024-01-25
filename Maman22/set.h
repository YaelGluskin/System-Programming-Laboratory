#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>


typedef char set[16];


/*
	The read_set function receives the set of integers values that the user entered, in the range 0 to 127.
	Each call to this function will delete the previous data in the used set.

	parameters:
			first_set - pointer to destination set.
			arry - pointer to int array.
*/

void read_set(set *first_set, int *arry);

/*
    The print_set function prints the set of integers values found in the set that the user requested to be printed.
    
    parameters:
			first_set - pointer to destination set.
*/
void print_set(set *first_set);

/*
	union_set function provides the user with the option to perform the mathematical
	operation of sets union on 2 sets. 
	A third set will be inserted with the result.

	parameters:
				first_set - pointer to set argument 1.
				second_set - pointer to set argument 2.
				third_set - pointer to set to be inserted with union result.
	
	NOTE: the same set can be passed as any argument in the argument list.

*/
void union_set(set *set1,set *set2,set *set3);

/*
	intersect_set function provides the user with the option to perform the 
	mathematical operation of sets intersection on 2 sets. 
	A third set will be inserted with the result.

	parameters:
				first_set - pointer to set argument 1.
				second_set - pointer to set argument 2.
				third_set - pointer to set to be inserted with intersection result.
	
	NOTE: the same set can be passed as any argument in the argument list.
*/
void intersect_set(set *set1,set *set2,set *set3);

/*
	sub_set function provides the user with the option to perform the mathematical
	operation of sets subtraction on 2 sets. 
	A third set will be inserted with the result.

	parameters:
				first_set - pointer to set argument 1.
				second_set - pointer to set argument 2.
				third_set - pointer to set to be inserted with subtraction result.
	
	NOTE: the same set can be passed as any argument in the argument list.
*/
void sub_set(set *set1,set *set2,set *set3);

/*
	symdiff_set function provides the user with the option to perform the mathematical
	operation of sets symmetrical difference on 2 sets. 
	A third set will be inserted with the result.

	parameters:
				first_set - pointer to set argument 1.
				second_set - pointer to set argument 2.
				third_set - pointer to set to be inserted with subtraction result.
	
	NOTE: the same set can be passed as any argument in the argument list.
*/
void symdiff_set(set *set1,set *set2,set *set3);

/*
	stop function provides the user with a way to terminate the set operations
	program.

	If the stop function is invoked, then the program will exit successfully.
*/
void stop(void);


int bit_on(set *first_set, int num);
int bit_off(set *first_set, int num);
int check_bit_on(set *first_set, int num);

