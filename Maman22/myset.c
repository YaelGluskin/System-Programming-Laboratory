
#include "valid_func.h"

/*
 	This program serves as a kind of interactive pocket calculator for performing operators on sets.
	The program receives commands from the user, and accordingly performs various actions.
	The user can enter a maximum of 100 characters per line.
	The sort is assisted by many functions that check the correctness of the user's input.
	By Yael Gluskin 213303035
*/


int main() 
{	
   
	/* Array of strings for error output messages */
	static char *erros_print[] = {"Illegal stop","Undefined command name","Undefined set name","Missing parameter","Missing comma",
	                              "Multiple consecutive commas","Extraneous text after end of command", "Invalid set member – not an integer",
	                              "Invalid set member – value out of range","List of set members is not terminated correctly","Illegal comma", 
	                              "There is no command"}; 
	/* Pointers to the input string */
	const char *pointer;
	char *string_input; 
	/* String tracking indexes */
	int i = 0;
	int j = 0;
	/* Variables for the commands */
	int num_func;
	int num_case;
	int arr[500];
	
	/* Set varibails and pointers*/
	set SETA;
    set SETB, SETC, SETD, SETE, SETF;
	set* first_set; 
	set* second_set;
	set* third_set;
	
	boot_sets(&SETA, &SETB, &SETC, &SETD, &SETE, &SETF); /* Initialize the sets */
	
	/* Instructions for  the user */
	printf("Welcome to SET OPERATIONS!\n");
	printf("Let's play around with sets and a few operations on them.\n\n");
	printf("1. Valid set names only: SETA, SETB, SETC, SETD, SETE, SETF.\n");
	printf("2. Valid opertaions only: read_set, print_set, union_set, ");
	printf("intersect_set, sub_set.\n");
	printf("3. Valid range of numbers: 0-127 inc.\n");
	printf("4. To perform read_set, input as follows:\t");
	printf("read_set <setname>,<number>,...,<number>,-1 <ENTER>\n");
	printf("\tExample: read_set SETA, 12, 13 ,14 ,-1\n");
	printf("5. To perform print_set, input as follows:\t");
	printf("print_set <setname><ENTER>\n");
	printf("\tExample: print_set SETA\n");
	printf("6. To perform union/intersect/sub_set/symdiff_set, input as follows:\t");
	printf("<operation> <setname1>,<setname2>,<setname3><ENTER>\n");
	printf("\tExample: intersect_set SETB, SETF, SETD\n");
	printf("NOTE: the same set can be used twice or 3 times ");
	printf("in uni/inter/sub/sym operations.\n");
	printf("7. To quit: stop<ENTER>\n");
	printf("NOTE: extraneous text after end of command is not allowd\n\nenjoy (-;");

	
	while(1) { /* An infinite loop that continues until a command to stop is received */

	    printf("\n\n ~ Please enter your command ~\n");
	    string_input = (char *) malloc(1000);
	    if(fgets (string_input, 1000, stdin) != NULL ) {
          	puts(string_input);
        }
        else {
            printf("\n%s", erros_print[0]); 
	        free(string_input);
	       exit(1);
        }
	    i = 0;
	       
	    /* A loop that advances the index when it sees a gain */ 
        while(i+1 < strlen(string_input) && (string_input[i] == ' ' || string_input[i] == '\t')) { 
		    i++;
	    }

	    for(j = 0; j < strlen(string_input); j++) {
	        if(string_input[strlen(string_input)-1] != '\n') {
	            printf("\n%s", erros_print[0]); 
	            free(string_input);
		    	exit(1);  /*the line end not corecctly*/
	        }
	    }
	    if(i+1 == strlen(string_input)) { /* "There is no command" */
		    printf("%s", erros_print[11]); 
	        free(string_input);
		    continue;  /*the line end not corecctly*/
	    }
	    pointer = &string_input[i]; /* the pointer point on the index in the string */
	    
	    num_func = vaild_comma(string_input);
	    if(num_func != 0) {
	        printf("\n%s", erros_print[num_func]);
		    free(string_input);
		    continue; /*end this loop and scan the next command*/
	    }
	    
	    /* read set*/
	    if((strncmp((const char*)string_input,"read_set ", 9) == 0) || (strncmp( (const char*)pointer,"read_set\t", 9) == 0) ) {
	        i = i+9;
	        while(i+1 < strlen(string_input) && (string_input[i] == ' ' || string_input[i] == '\t')) {
	    	    i++;
	        }
	        pointer = &string_input[i];
	        if((strncmp((const char*)pointer,"SET", 3)) != 0) { /* Undefined set name */
	            printf("\n%s", erros_print[2]);
	            free(string_input);
	            continue; /*end this loop, and scan the next command*/
	        } 
	        else {
	            i = i+3;
	            switch(string_input[i]) {
	                case 'A':
	                    first_set = &SETA;
	                    break;
	                case 'B':
	                    first_set = &SETB;
	                    break;
	                case 'C':
	                    first_set = &SETC;
	                    break;
	                case 'D':
	                    first_set = &SETD;
	                    break;
	                case 'E':
	                    first_set = &SETE;
	                    break;
	                case 'F':
	                    first_set = &SETF;
	                    break;
	                default:
	                    printf("\n%s", erros_print[2]);
	                    free(string_input);
	                    continue;
	            } /* end of first switch*/ 
                i++;
                while(i+1 < strlen(string_input) && (string_input[i] == ' ' || string_input[i] == '\t')) {
	    	        i++;
	            }
	            switch(string_input[i]) {
	                case ',': 
	                    i++;
	                    break;
	                default:
	                    printf("\n%s", erros_print[4]);
	                    free(string_input);
	                    continue;
	            }
	            for(j = 0; j < 500; j++){
	                *(arr+j) = -1;
	            }
                if(arr == NULL ) {
                    printf("sorry, but there is no memory for command. you can try again");
                    free(string_input);
                    continue;
            }
            
	        num_func = vaild_int((char *)(string_input+i), (int *)arr);
    	    if(num_func != 0) {
	           printf("\n%s", erros_print[num_func]); 
	        }
	        else {
	            read_set(first_set, (int *)arr); /*char * */
	             
	            } /* end of vaild numbers*/
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/
	        }/* end of else */
	    } /* end of read set*/
	
		/*print set*/
		if( (strncmp((const char*)pointer,"print_set ", 10) == 0) || (strncmp( (const char*)pointer,"print_set\t", 10) == 0) ) {
	    	i = i+10;
	    	while(i+1 < strlen(string_input) && (string_input[i] == ' ' || string_input[i] == '\t')) {
			    i++;
	   	    }
	    pointer = &string_input[i];
	    
	    if((strncmp((const char*)pointer,"SET", 3)) != 0) { /* Undefined set name */
	        printf("\n%s", erros_print[2]);
	    } 
	    else {
	    i = i+3;
	    switch(string_input[i]) {
	        case 'A':
	            first_set = &SETA;
	            break;
	        case 'B':
	            first_set = &SETB;
	            break;
	        case 'C':
	            first_set = &SETC;
	            break;
	        case 'D':
	            first_set = &SETD;
	            break;
	        case 'E':
	            first_set = &SETE;
	            break;
	        case 'F':
	            first_set = &SETF;
	            break;
	        default:
	             printf("\n%s", erros_print[2]);
	             free(string_input);
	             continue;
	    } /* end of first switch*/ 
	    i = i+1;
	    if(what_next(string_input, &i) == 1) { /*chack there is no extra text*/
	        print_set((set *)first_set);
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/   
	    }
	    else {
	        printf("\n%s", erros_print[6]);
	        free(string_input);
	            continue; /*end this loop, and scan the next command*/
	    }    
	    } /* end of else */
	 }/*end of print set*/   
	 
	/* union_set set*/
	if( (strncmp((const char*)pointer,"union_set ", 10) == 0) || (strncmp((const char*)pointer,"union_set\t", 10) == 0) ){
	    i = i+10;
	    num_func = what_next(string_input, &i);
	    if(num_func <= 10) {
	        printf("\n%s", erros_print[num_func]);
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/
	    } /* end of errors prints*/
	    
	    num_case = num_func%100;
	    switch(num_case) {
	        case 10:
	            first_set = &SETA;
	            break;
	        case 20:
	            first_set = &SETB;
	            break;
	        case 30:
	            first_set = &SETC;
	            break;
	        case 40:
	            first_set = &SETD;
	            break;
	        case 50:
	            first_set = &SETE;
	            break;
	        case 60:
	            first_set = &SETF;
	            break;
	    } /* end of first switch*/
	    
	    num_case = (num_func/100)%10;
	    switch(num_case) {
	        case 1:
	            second_set = &SETA;
	            break;
	        case 2:
	            second_set = &SETB;
	            break;
	        case 3:
	            second_set = &SETC;
	            break;
	        case 4:
	            second_set = &SETD;
	            break;
	        case 5:
	            second_set = &SETE;
	            break;
	        case 6:
	            second_set = &SETF;
	            break;
	    } /* end of second switch*/
	    
	    num_case = num_func/1000;
	    switch(num_case) {
	        case 1:
	            third_set = &SETA;
	            break;
	        case 2:
	            third_set = &SETB;
	            break;
	        case 3:
	            third_set = &SETC;
	            break;
	        case 4:
	            third_set = &SETD;
	            break;
	        case 5:
	            third_set = &SETE;
	            break;
	        case 6:
	            third_set = &SETF;
	            break;
	    } /* end of third switch*/ 
	    free(string_input);
	    union_set(first_set, second_set, third_set);
	    continue; /*end this loop, and scan the next command*/  
    } /* end of union_set*/
    
    /* intersect set*/
	if( (strncmp((const char*)pointer,"intersect_set ", 14) == 0) || (strncmp((const char*)pointer,"intersect_set\t", 14) == 0) ){
	    i = i+14;
	    num_func = what_next(string_input, &i);
	    if(num_func <= 10) {
	        printf("\n%s", erros_print[num_func]);
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/
	    } /* end of errors prints*/

	    num_case = num_func%100;
	    switch(num_case) {
	        case 10:
	            first_set = &SETA;
	            break;
	        case 20:
	            first_set = &SETB;
	            break;
	        case 30:
	            first_set = &SETC;
	            break;
	        case 40:
	            first_set = &SETD;
	            break;
	        case 50:
	            first_set = &SETE;
	            break;
	        case 60:
	            first_set = &SETF;
	            break;
	    } /* end of first switch*/
	    
	    num_case = (num_func/100)%10;
	    switch(num_case) {
	        case 1:
	            second_set = &SETA;
	            break;
	        case 2:
	            second_set = &SETB;
	            break;
	        case 3:
	            second_set = &SETC;
	            break;
	        case 4:
	            second_set = &SETD;
	            break;
	        case 5:
	            second_set = &SETE;
	            break;
	        case 6:
	            second_set = &SETF;
	            break;
	    } /* end of second switch*/
	    
	    num_case = num_func/1000;
	    switch(num_case) {
	        case 1:
	            third_set = &SETA;
	            break;
	        case 2:
	            third_set = &SETB;
	            break;
	        case 3:
	            third_set = &SETC;
	            break;
	        case 4:
	            third_set = &SETD;
	            break;
	        case 5:
	            third_set = &SETE;
	            break;
	        case 6:
	            third_set = &SETF;
	            break;
	    } /* end of third switch*/ 	    

	    intersect_set(first_set, second_set, third_set);
	    free(string_input);
	    continue; /*end this loop, and scan the next command*/  
    } /* end of intersect_set*/
    
    /* sub set*/
	if( (strncmp((const char*)pointer,"sub_set ", 8) == 0) || (strncmp((const char*)pointer,"sub_set\t", 8) == 0) ){
	    i = i+8;
	    num_func = what_next(string_input, &i);
	    if(num_func <= 10) {
	        printf("\n%s", erros_print[num_func]);
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/
	    } /* end of errors prints*/
	    
	    num_case = num_func%100;
	    switch(num_case) {
	        case 10:
	            first_set = &SETA;
	            break;
	        case 20:
	            first_set = &SETB;
	            break;
	        case 30:
	            first_set = &SETC;
	            break;
	        case 40:
	            first_set = &SETD;
	            break;
	        case 50:
	            first_set = &SETE;
	            break;
	        case 60:
	            first_set = &SETF;
	            break;
	    } /* end of first switch*/
	    
	    num_case = (num_func/100)%10;
	    switch(num_case) {
	        case 1:
	            second_set = &SETA;
	            break;
	        case 2:
	            second_set = &SETB;
	            break;
	        case 3:
	            second_set = &SETC;
	            break;
	        case 4:
	            second_set = &SETD;
	            break;
	        case 5:
	            second_set = &SETE;
	            break;
	        case 6:
	            second_set = &SETF;
	            break;
	    } /* end of second switch*/
	    
	    num_case = num_func/1000;
	    switch(num_case) {
	        case 1:
	            third_set = &SETA;
	            break;
	        case 2:
	            third_set = &SETB;
	            break;
	        case 3:
	            third_set = &SETC;
	            break;
	        case 4:
	            third_set = &SETD;
	            break;
	        case 5:
	            third_set = &SETE;
	            break;
	        case 6:
	            third_set = &SETF;
	            break;
	    } /* end of third switch*/	    
	    
        sub_set(first_set, second_set, third_set);   
	    free(string_input);
	            continue; /*end this loop, and scan the next command*/
    } /* end of sub set*/
    
    /* symdiff set */
	if( (strncmp((const char*)pointer,"symdiff_set ", 12) == 0) || (strncmp((const char*)pointer,"symdiff_set\t", 12) == 0) ){
	    i = i+12;
	    num_func = what_next(string_input, &i);
	    if(num_func <= 10) {
	        printf("\n%s", erros_print[num_func]);  
	        free(string_input);
	        continue; /*end this loop, and scan the next command*/
	    } /* end of errors prints*/
	    
	    num_case = num_func%100;
	    switch(num_case) {
	        case 10:
	            first_set = &SETA;
	            break;
	        case 20:
	            first_set = &SETB;
	            break;
	        case 30:
	            first_set = &SETC;
	            break;
	        case 40:
	            first_set = &SETD;
	            break;
	        case 50:
	            first_set = &SETE;
	            break;
	        case 60:
	            first_set = &SETF;
	            break;
	    } /* end of first switch*/
	    
	    num_case = (num_func/100)%10;
	    switch(num_case) {
	        case 1:
	            second_set = &SETA;
	            break;
	        case 2:
	            second_set = &SETB;
	            break;
	        case 3:
	            second_set = &SETC;
	            break;
	        case 4:
	            second_set = &SETD;
	            break;
	        case 5:
	            second_set = &SETE;
	            break;
	        case 6:
	            second_set = &SETF;
	            break;
	    } /* end of second switch*/
	    
	    num_case = num_func/1000;
	    switch(num_case) {
	        case 1:
	            third_set = &SETA;
	            break;
	        case 2:
	            third_set = &SETB;
	            break;
	        case 3:
	            third_set = &SETC;
	            break;
	        case 4:
	            third_set = &SETD;
	            break;
	        case 5:
	            third_set = &SETE;
	            break;
	        case 6:
	            third_set = &SETF;
	            break;
	    } /* end of third switch*/		    
	    
	    symdiff_set(first_set, second_set, third_set); 
	    free(string_input);
	    continue; /*end this loop, and scan the next command*/  
        } /* end of symdiff set */
        pointer = &string_input[i];
	    if(strncmp((const char*)pointer,"stop", 4) == 0)  {
	        i = i + 4;
	        num_func = what_next(string_input, &i);
	        free(string_input);
	        if(num_func == 1) {
	        	stop();
	        }
		    else {
	            printf("\n%s",erros_print[6]);
	            continue;
		        }
	 } /*end of stop*/
	     

        printf("\n%s", erros_print[1]);
        free(string_input);
        
    } /*end of whilel loop*/
    printf("Error: no 'stop' command at EOF redirection.\n");
    
return 1;

} /* end of main*/
