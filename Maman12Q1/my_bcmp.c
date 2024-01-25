/*
This program receives from the user a string, two indices and a length of bytes.
The program prints the inputs and sends them to the function that checks whether the memory sections starting with the different indexes,
in the length received, are the same.
Wirtten by by Yael Gluskin
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 513

int my_bcmp(const void *b1, const void *b2, size_t len);
/*
The main program recieves a length, two indexes. After each receive, it performs input validity checks, and prints an error message if the input is invalid.
If the input is valid, it prints the received input. The program then receives a string, checks that it is not null, and also checks that the values previously received do not out of border of the length of the received string. If all the values are valid, a call will be made to function my_bcmp and according to the value returned from it, a message is printed as to whether the segments are identical or not.
*/
int main(void) {
	/* string variables for user-input */
	char str_len[MAX_STRING];
	char str_index1[MAX_STRING];
	char str_index2[MAX_STRING];
	char str[MAX_STRING] = {0};
	int c, i = 0; /* variables for receiving the string */
	size_t len, index1, index2; /* variables for validity testing */
	char *pointer; /* a pointer type variable for validity testing */
	char *b1, *b2; /* variables for the function my_bcmp */
	int result; /* a variable for the result of the function my_bcmp */ 	

	/* The reception of the length, and three conditions that test a natural number, a positive number and a number within the limits of the array. */
	printf("Please enter len (number of bytes to be compared):\t");
	fgets(str_len, MAX_STRING, stdin);
	len = strtol(str_len, &pointer, 10); /* convert input string to int */
	while(*pointer != '\n' && *pointer != '\0')  {
		if(*pointer < '0' || *pointer > '9') { /* check that length is a nutural number */
			printf("\nEROROR: length is not a natural number.You entered: %s", str_len);
			return 1;
		}
	}
	if(str_len[0] == '-') { /* check that the length is a positive number */
		printf("\nEROROR: the length is not a positive number. You entered: %s", str_len); 
		return 1;
	}
	if(len > MAX_STRING - 1) { /* check that the length is in the string limit */
		printf("\nEROROR: the length is out of bounds. You entered: %s", str_len);
		return 1;
	}
    printf("\nThe number of bytes you entered for comparison is\t %d" ,len);
    
	/* The reception of the input for the first index and four conditions that check the vailds of the input. */
	printf("\n\nEnter the first index for the memory segment to be compared\t");
	fgets(str_index1, MAX_STRING, stdin);
	
    index1 = strtol(str_index1, &pointer, 10); /* convert input string to int */
	while(*pointer != '\n' && *pointer != '\0') {
		if(*pointer < '0' || *pointer > '9') { /* check that index1 is a nutural number */
			printf("\nEROROR: the first index is not a natural number. You entered: %s", str_index1);
			return 1;
		}
	}
	if(str_index1[0] == '-') { /* check that index1 is a positive number */
		printf("\nEROROR: the first index is not a positive number. You entered: %s", str_index1); 
		return 1;
	}
	if(MAX_STRING - 1 < index1) { /* check that index1 is in the string limit */ 
		printf("\nEROROR: the first index is out of bounds (large of the maximum). You entered: %s", str_index1); 
		return 1;
	}
	
	if(MAX_STRING - 1 < (len + index1)) {  /* check that index1 + length are in the string limit */
		printf("EROROR: the memory segment starting at the first index is out bounds (large of the maximum). You entered: %s", str_index1); 
		return 1;
	}
	printf("\nThe first index you entered is\t %d", index1); /* the input is vaild */
	
	
	/* The reception of the input for the second index and four conditions that check the valids of the input. */
	printf("\n\nEnter a second index for the memory segment to be compared\t");
	fgets(str_index2, MAX_STRING, stdin);
	index2 = strtol(str_index2, &pointer, 10); /* convert input string to int */
	while(*pointer != '\n' && *pointer != '\0') {
		if(*pointer < '0' || *pointer > '9') { /* check that index2 is a nutural number */
			printf("\nEROROR: the second index is not a natural number. You entered: %s", str_index2);
			return 1;
		}
	}
    if(str_index2[0] == '-') { /* check that index2 is a positive number */
		printf("\nEROROR: the second index is not a positive number. You entered: %s", str_index2); 
		return 1;
	}
	if(MAX_STRING - 1 < index2) { /* check that index2 is in the string limit */
		printf("\nEROROR: the second index is out of bounds (large of the maximum).You entered: %s", str_index2); 
		return 1;
	}
	if(MAX_STRING - 1 < (len + index2)) { /* check that index2 + length are in the string limit */
		printf("\nEROROR: the memory segment starting at the second index is out bounds (large of the maximum). You entered: %s", str_index2);
		return 1;
	}
    printf("\nThe second index you entered is\t %d", index2); /* the input is vaild */
	
	/** Receiving the string and checking that it is not null */
	printf("\n\nEnter your string\n");
	/*
    for(i = 0; ((c = getchar())!= EOF) && (i < MAX_STRING); i++) {
		str[i] = c;	
	} 
	*/
	if (fgets(str, sizeof(str), stdin) != NULL) {
        /* Remove the newline character at the end of the string */
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
			i = len;
        }
	}
	
	if(i == 0) { /* chaek that the string is not null */
        printf("\nEROROR: The string is NULL.\n"); 
		return 1;
	} 
	
    printf("\n\nThe string you entered is\n%s", str);
    
    /* Five conditions that check the legality of the length and the tow indexes relative to the entered string. */
    
	if(i < len) { /* check that the length is in the string limit */
		printf("\nEROROR: The length of bytes entered is larger than the length of the string.\n"); 
		return 1;
	}
	if(i < index1) { /* check that index2 is in the string limit */
		printf("\nEROROR: the first index is out of the entered string bounds.\n"); 
		return 1;
	}
	if(i < (len + index1)) { /* check that index1 + length are in the string limit */
		printf("\nEROROR: the memory segment starting at the first index is out of the entered string bounds.\n"); 
	    return 1;
	}		
	if(i < index2) { /* check that index2 is in the string limit */
		printf("\nEROROR: the second index is out of the entered string bounds.\n"); 
		return 1;
	}
	if(i < (len + index2)) { /* check that index2 + length are in the string limit */
		printf("\nEROROR: the memory segment starting at the second index is out of the entered string bounds.\n"); 
		return 1;
	}
	/* all input is valid */
	b1 = str + index1;
	b2 = str + index2;
	result = my_bcmp(b1, b2, len);
	if(result == 0) { /* when the memory segments are indeed identical */
	    printf("\n\nThe compared memory segments are identical!!\n");
     }
    else {
        printf("\n\nThe compared memory segments are not identical!\n"); 
	}
	return(0);
}
/*
This function accepts two indices that point to a string, and a length. The function checks whether the length of the bytes in the memory segment from the first index is the same as the length of the bytes in the memory segment starting from the second index. It returns 0 if the segments are the same, and 1 if not.
*/

int my_bcmp(const void *b1, const void *b2, size_t len)
    {
	return(memcmp(b1, b2, len));	
}

