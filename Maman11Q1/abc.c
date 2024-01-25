#include <stdio.h>

/*
Yael Gkuskin 213303035
This program get a string as a parameter and sends it to a function that detects sequences in it,
shortens it accordingly, and prints it when it is shortened.
*/

#define MAX 81

int solution(char string[]);
int s(char string[]);
	/*
	The main get a string from the user, prints it, and prints it again when it is shortened after a call to function solution.
	*/
int main() 
{
	char str[MAX];
	int i;
	int c;
	printf("\nEnter your string:\t");
		
	for(i=0;((c = getchar())!= EOF) && (i < MAX);i++) 
	{
		str[i] = c;	
	} 
	str[i] = '\0';
	printf("\nYour string is:\t%s",str);
	solution(str);
	printf("\nThe short string is:\t%s\n",str);
	return 0;  
	}
	
	/*
	This function get a string, on which it makes changes every time it detects a sequence of three letters,
	in the case of a larger sequence the function will shorten the string.
	The function ends when it reaches the end of the string.
	*/
  
int solution(char str[]) {
	int i = 0;
	int j = 0;
	while(str[i] != EOF) { /* the loop will run as long as the string has not reached its end */
		if((( 'A' <= str[i] && str[i] <= 'X') || ( 'a' <= str[i] && str[i] <= 'x')) && (str[i]+1 == str[i+1]) && (str[i]+2 == str[i+2])) { /* identifies a sequence of three letters (not numbers) */
			str[i+1] = '-';
			i++;
		}
		if(str[i] == '-' && str[i+2] != EOF && str[i+1]+1 == str[i+2] && str[i+2] != '[' && str[i+2] != '{') { /* the condition checks whether there is an identified sequence of letters that continues) */
		    for(j = i+1; str[j] != '\0'; j++) { /* the loop shortens the string*/
					str[j] = str[j+1];
			}
					str[j] = '\0'; /* In the end of the string */
		}
        	else i++; /* when no sequence or continuation of a sequence is found, the index moves to the next character */
	}
	return 0;
}
