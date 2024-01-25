#include "set.h"

void read_set(set *first_set, int *arry) {
    int j;
    int k;
    for(j = 0; j < 128; j++)  {
        bit_off(first_set, j);
    }
    for(k = 0; j < 500 && arry[k] != -1; k++) {
        bit_on(first_set, arry[k]);
    }
}	

void print_set(set *first_set) {
    int j;
    int k;
    int m;
    int arry[128];
    k = 0;
    for(m = 0; m < 128; m++) { /**/
	        arry[m] = -1;
	} 
    printf("\nThe set is:\t"); 
    for(j = 0; j < 128; j++) {
        if(check_bit_on(first_set, j) == 1) {
            printf("%d ", j);
            k++;
        }
    }
    if(k == 0) {
        printf("empty");

    }
} /* end of func */

	
void union_set(set *set1,set *set2,set *set3){
	int i;
	if(set1 != set3 && set2 != set3) {
        for(i = 0;i < 16; i++) {
            (*set3)[i] = 0;
        }
    }
	for(i = 0; i < 128; i++) {
        if(check_bit_on(set1, i) == 1 || check_bit_on(set2, i) == 1) {
            bit_on(set3, i);
        }
    }
}

void intersect_set(set *set1,set *set2,set *set3) {
    int i;
    for(i = 0;i < 128; i++){
        (*set3)[i] = (*set1)[i] & (*set2)[i];
    }
}

void sub_set(set *set1,set *set2,set *set3) {
    int i;
    for(i = 0;i < 128; i++){
        (*set3)[i] = (*set1)[i] & (~(*set2)[i]);
    }
}

void symdiff_set(set *set1,set *set2,set *set3) {
		
	int i;
	for(i = 0;i < 128; i++){
		if(check_bit_on(set1, i) == 1 && check_bit_on(set2, i) == 1) {
			   bit_off(set3, i);
		}
		else {
	        if(check_bit_on(set1, i) == 1 || check_bit_on(set2, i) == 1) {
                bit_on(set3, i);
            }
        }
    }
         
}

void stop(void) {
	
	exit(0);
}
	

int bit_on(set *first_set, int num) {
    int index_set = num/8;
    int index_char = num%8;
    unsigned char mask = 1 << (index_char);
    (*first_set)[index_set] = (*first_set)[index_set] | mask; /* */
    return 0;
    
}

int bit_off(set *first_set, int num) {
    int index_set = num/8;
    int index_char = num%8;
    unsigned char mask = 1 << (index_char);
    (*first_set)[index_set] = (*first_set)[index_set] &(~ mask);
    return 0;
    
}

int check_bit_on(set *first_set, int num) {
    int index_set = num/8;
    int index_char = num%8;
    unsigned char mask = 1 << (index_char);
    unsigned char mask_set = (*first_set)[index_set] & mask;
    mask_set = mask_set >> index_char;
    if(mask_set == 0){
        return 0;
    }
    else return 1;
}	

