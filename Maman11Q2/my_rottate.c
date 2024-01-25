#include <stdio.h>
/*
Yael Gluskn 213303035

This program get two numbers from the user, 
it first prints the  first number in various bases,
then rotates the entered number by the size of the entered second number, 
then prints the rotated number again in the various bases.
(There is a reference to a positive or negative number).
*/
#define BYTE 8

unsigned int my_rottate (unsigned int a, int b);
    /*
    The main grt two numbers and, it prints the first number in base 10, 2, 8 and 16 and sends the two numbers to function my_rottate,
    After calling the function, it prints the number that the function returned in the various bases.
    */
int main() {
	unsigned int x; /* variable for the number on which the rotation is performed */
	int y; /* variable for the number with which the rotation is performed */
	unsigned int mask; /* variable for the binary print */
	int i;
	printf("\nEnter a number to rotate:\t");
	scanf("%u",&x);
	printf("\nEnter a number to rotate with:\t");
	scanf("%d",&y);
	printf("\n Your number is: %d and its size in memory is %d .\n",x ,sizeof(int)*BYTE);
	printf("\n Your number as binary base =  ");
	mask = 1 << (BYTE*sizeof(int)-1);
	for(i = 0; i < BYTE*sizeof(x); i++) { /* loop for printing the number in binary base */
		if(mask&x) {
		    printf("1"); 
		}
		else {
 			printf("0");	
		}
		mask>>=1;
	}
	printf("\n\n Your numbre as octal base = %o \n",x); /*base 8*/ 
	printf("\n Your numbre as hexadecimal base = %x \n",x); /*base 16*/
	
	
	if(y == 0) { /* In case the number is equal to 0, there is no call to the function */
		printf("\n\nThere is no change in your number!\n");
	}
	else { /* when y is not equal to 0 */
	    x = my_rottate(x,y); /* The function performs the rotation, then the resulting number is printed. */
	    printf("\n\n Your number after the rotation is %d ",x);
    	printf("\n\n The number as binary base =  ");
    	mask = 1 << (BYTE*sizeof(int)-1);
    	for(i=0; i< BYTE*sizeof(x);i++) { /* loop for printing the number in binary base */
    		if(mask&x) {
    		    printf("1");
    		}
    		else {
    		    printf("0");
    		}
    		mask >>= 1;
        }
    	printf("\n\n The numbre as octal base = %o \n",x); /*base 8*/
    	printf("\n The numbre as hexadecimal base = %x \n",x); /*base 16*/	
    }
	return 0;
}
    /*
    The function rotates b bits on a:
    The function first checks whether b is positive or negative and accordingly the rotation is performed:
    it saves the bits that rotate, moves a b times to the right when b is positive, and to the left when b is left,
    after it copies the copied bits back to a on the other side from which they were copied.
    Then the function returns the rotated a.
    */
unsigned int my_rottate(unsigned int a, int b) 
{
	int i = 1;
	int j = 1;
	int move; /* variable for the bits that are copied to the left side of a, when b is positive */
	unsigned int step; /* variable for the bits that are copied to the right side of a, when b is negative */
	if(b > 0) { /* check if b is positive */
		move = 0;
		move = move|(1);
		while(i <= b) { /* turns on the b bits on the right*/
			move = move|(1 << (i-1));
			i++;
		}
		move = move & a; /* the bits that rotate are copied to moveS */
		move = move << (32 - b);
		a = a >> b;
		a = a | move;
	}
	if(b < 0) { /* check if b is negative */
	step = 0;
	    while(j <= (-b)) { /* turns on the b bits on the left*/
			step = step|(1 << ((sizeof(int)*BYTE)-j));
			j++;
	}
	step = step & a; /* the bits that rotate are copied to step */
	step = step >> (32+b);
	a = a << (-b);
	a = a | step;
	}
	return a;
}
