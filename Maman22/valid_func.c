#include "valid_func.h"


int what_next(char *str, int *counter) 
{
	/*const char *str = string;  */
	char const *pointer;
	int i = *counter;
	int case_to_return;
	int str_equal =1;
	while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		i++;
	}
	if(i+1 == strlen(str)) { /* "Undefined command name" */
		return 1;
	}
	pointer = &str[i];
	str_equal = strncmp((const char *)pointer,"SET", 3);
	if(str_equal == 0) {
		i = i+3;
		if(str[i] >= 'A' && str[i] <= 'F') {
		    if(str[i] == 'A') {
		        case_to_return = 10;
		    }
		    if(str[i] == 'B') {
		        case_to_return = 20;
		    }
		    if(str[i] == 'C') {
		        case_to_return = 30;
		    }
		    if(str[i] == 'D') {
		        case_to_return = 40;
		    }
		    if(str[i] == 'E') {
		        case_to_return = 50;
		    }
		    if(str[i] == 'F') {
		        case_to_return = 60;
		    }
		i++;
		} /* end chek of first vaild set*/ 
		else { /* "Undefined set name" */
		    return 2;
		}
	} /* end of ther is a first set*/
	else { /* "Undefined set name" */
	    return 2;
	}
	
		/* check space */
		while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(i+1 == strlen(str)) {
		    return 3; /* "Missing parameter" */
	    }
	    
	    
		if(str[i] == ',') { /* there is a first comma*/
	    	
	    	i++;
	    	/* check space */
	    	while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	    i++;
	        }
	        if(i+1 == strlen(str)) {
	    	    return 3; /* "Missing parameter" */
	            }
	            
    		if(str[i] == ',') {
	    	    return 5; /* "Multiple consecutive commas" */
	    	}
	    	pointer = &str[i];
	    	if(strncmp((const char *)pointer,"SET", 3) == 0) {
	    	    i = i+3;
	    	    if(str[i] >= 'A' && str[i] <= 'F') {
	    	        if(str[i] == 'A') {
	    	            case_to_return = case_to_return + 100;
	    	        }
        		    if(str[i] == 'B') {
	        	        case_to_return = case_to_return + 200;
	        	    }
	        	    if(str[i] == 'C') {
	        	        case_to_return = case_to_return + 300;
	        	    }
	        	    if(str[i] == 'D') {
	        	        case_to_return = case_to_return + 400;
	        	    }
	        	    if(str[i] == 'E') {
	        	        case_to_return = case_to_return + 500;
	        	    }
	        	    if(str[i] == 'F') {
	        	        case_to_return = case_to_return + 600;
	        	    }
	        	i++;
	        	} /* end chek of vaild second set*/
	    	    else { /* "Undefined set name" */
	    	        return 2;
	    	    }
	    	} /* ther is a second vaild set*/
	    	else { /* "Undefined set name" */
	    	    return 2; 
	    	} 
	    	}
	    	else {
	    	    return 4; /* "Missing comma" */
	    	}    
	    	/* START CHECKING THE THIRD SET */
	    	    /* check space */
		        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
        		    i++;
	            }
        	    if(i+1 == strlen(str)) {
           		    return 3 ; /* "Missing parameter" */
	           }
	    
	    
    		if(str[i] == ',') { /* there is a second comma*/
	    	
	    	    i++; 
	        	/* check space */
	        	while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	        	    i++;
	            }
	            if(i+1 == strlen(str)) {
	            	    return 3; /* "Missing parameter" */
	                }
	                    
        		if(str[i] == ',') {
	        	    return 5; /* "Multiple consecutive commas" */
	        	}
	        	pointer = &str[i];
	        	if(strncmp((const char *)pointer,"SET", 3) == 0) {
	        	    i = i+3;
	        	    if(str[i] >= 'A' && str[i] <= 'F') {
	        	        if(str[i] == 'A') {
	        	            case_to_return = case_to_return + 1000;
	        	        }
            		    if(str[i] == 'B') {
	            	        case_to_return = case_to_return + 2000;
	            	    }
	            	    if(str[i] == 'C') {
	            	        case_to_return = case_to_return + 3000;
	            	    }
	            	    if(str[i] == 'D') {
	            	        case_to_return = case_to_return + 4000;
	            	    }
	            	    if(str[i] == 'E') {
	            	        case_to_return = case_to_return + 5000;
	            	    }
	            	    if(str[i] == 'F') {
	            	        case_to_return = case_to_return + 6000;
	            	    }
	                	i++;
	                	} /* end chek of vaild second set*/
	        	      else { /* "Undefined set name" */
	        	        return 2;
	        	      }
	        	    } /*there is third set*/
	            else {
	                return 2; /* "Undefined set name" */
	            } 
	            }/* end of second comma*/
	            else {
	                return 4; /* "Missing comma" */
	           }
	            /* check space */
	        	while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	        	    i++;
	            }
	            if(i+1 == strlen(str)) {
	            	    return case_to_return; /* VAILD COMMAND */
	                }
	                    
        		if(str[i] == ',') {
	        	    return 5; /* "Multiple consecutive commas" */
	        	}
	        	else {
	        	    return 6; /* "Extraneous text after end of command" */ 
	        	}
	        	    
    } /* end of function */

/* *************** */

int vaild_int(char *str, int* array) 
{
   /*char *pointer;*/
   int to_send;	
   int i = 0;
   int j = 0;
   int seq = 0;
   int num = -2;
   while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		i++;
	}
	if(i+1 == strlen(str)) { /* "Undefined command name" */
		return 9; /*the line end not corecctly*/
	}
	while('9' >= str[i] && str[i] >= '0') { /* the loop start*/
        to_send = i+1;
	    if(what_next(str, &to_send) == 1) {
	       return 9;
	    }
	    if(str[i] == '0') {
	        to_send = i+1;
	        if(what_next(str, &to_send) == 1) {
	            return 9;
	        }
	        i++;
	        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	    i++;
	        }
	        if(str[i] == ',') {
	            while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	        i++;
	            }
	       *(array+j) = 0;
	       j++;
	       i++;
	       while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	        i++;
	       }
	       continue;
	        } /* end of comma*/
	        else {
	            return 5;
	        }
	        return 7; /* proberly not invaid number*/
	    } /*end case '0'*/ 
	    /*pointer = &str[i]; */
	    num = atoi((const char *)(str+i));
	    if(num == 0) {
	        return 7; /* not vaild */
	    }
	    while(str[i] != ' ' && str[i] != '\t' && str[i] != ',') {
	        seq = seq +1;
	        i= i+1 ;
	    }
	    if(num/10 == 0) {
	        if(seq > 1) {
	            return 7;
	        }
	    }
	    else {
	        if(num/100 == 0) {
	            if(seq > 2) {
	                return 7;
	            }
	        } /* if 2*/
	        else {
	            if(num/1000 == 0) {
	                if(seq > 3) {
	                    return 7;
	                }
	            } 
	            else { /* num larger then 1000*/
	                return 8;   
	            }
	        } /* end of else */
	    } /* enf of else */
	    if(num < 0 || num > 127) { /* out of range*/
	        return 8;
	    }
	    while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	i++;
	    }
	    if(i+1 == strlen(str)) { /* "Undefined command name" */
		    return 9;
	    }
	    if(str[i] == ',') {
	        i++;
	        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
	    	    i++;
	        } 
	            *(array+j) = num;
	            j++;
	            seq = 0;
	            continue;
	    } /*enf of comma if*/
	    else {
	        return 4;    
	    }    
	    
	} /* end of while*/
	
	if(i+1 == strlen(str) || str[i] == EOF) { /* "Undefined command name" */
		return 9; /*the line end not corecctly*/
	}
	if(str[i] == ',') {
	    return 5;
	}
	if(strncmp((str+i), "-1", 2) == 0) {;
	    to_send = i+2;
	    if(what_next(str, &to_send) == 1) {
	        return 0; /* the string is over in good way*/
	    }
	    else {
	        return 9; /* ther is -1 but char after*/
	    }
	} /* end of -1 */
	if(str[i] == '-') { /*out of rage*/
	    return 8;
	}
    return 7; /* the number is not vaild */
}

/* ************* */



int vaild_comma(char *str) {
    int i = 0;
    if(strncmp((const char *)str, "read_set", 8) == 0) {
        i = i+8;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    if(strncmp((const char *)str, "print_set", 9) == 0) {
        i = i+9;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    if(strncmp((const char *)str, "union_set", 9) == 0) {
        i = i+9;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    if(strncmp((const char *)str, "sub_set", 7) == 0) {
        i = i+7;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    if(strncmp((const char *)str, "intersect_set", 13) == 0) {
        i = i+13;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    if(strncmp((const char *)str, "simdiff_set", 10) == 0) {
        i = i+10;
        while(i+1 < strlen(str) && (str[i] == ' ' || str[i] == '\t')) {
		    i++;
	    }
	    if(str[i] == ',') {
	        return 10;
	    }
	    if(i+1 == strlen(str)) { /* "Missing parameter" */
		    return 3; 
	    }
    }
    return 0;    
}

void boot_sets(set* setA, set* setB, set* setC, set* setD, set* setE, set* setF) {
    int j;
    for(j = 0; j < 128; j++)  {
        bit_off(setA, j);
    }
    for(j = 0; j < 128; j++)  {
        bit_off(setB, j);
    }
    for(j = 0; j < 128; j++)  {
        bit_off(setC, j);
    }
    for(j = 0; j < 128; j++)  {
        bit_off(setD, j);
    }
    for(j = 0; j < 128; j++)  {
        bit_off(setE, j);
    }
    for(j = 0; j < 128; j++)  {
        bit_off(setF, j);
    }
    
}

