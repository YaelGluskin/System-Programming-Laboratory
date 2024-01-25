#include "permut.h"

int main(int argc, char *argv[]) {

	int i; /* Index in the file */
	int status; /* Status variable of permutations */
	
    /* variables for the file */
	char *string;
	FILE *file;
	long int fsize;
	
	/* variables for the word */
	char *str_permut;
	int length_str;
	
	/* Check the input */
    if(argc != 3) { /* Checking if there are 3 arguments */
        if(argc < 3) {
            printf("Missing argument\n");  
        }
        else  {
        printf("Too many argument\n");
        }
        return 1;;
    }
	
	length_str = strlen(argv[2]);
    if(length_str < 2) { /* Checks the length of the word */
        printf("The word is too short\n");  
        return 1;  
    }
    printf("The word for permut check is: %s\n", argv[2]);
    str_permut = (char *)malloc(length_str);
	strcpy(str_permut, argv[2]);
    
    /* Open the file */ 
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    /* Read the entire file into a single string */
    fseek(file, 0, SEEK_END);
    fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    string = (char *)malloc(fsize+1);
    fread(string, 1, fsize, file);
    fclose(file);
    string[fsize] = '\0'; 
    
    i = 0;
    status = 0;
    while(i < fsize) { /* The loop call is_permut to check every character if it's the beginning of a permut */
        i = i + is_permut(string, i, str_permut, &status); 
    }

    if(status == 0) { /* Check if there was permut in the file */
        printf("There is no permut in the file\n");
    }
    /* Free the memory */
    free(string);
    free(str_permut);
    return 0;
}


int is_permut(char *string, int index, char *word, int *status){

    int k, j, i;
    int length_word = strlen(word);
    char *copy_word;
    char *copy_print;
    copy_word = (char *)malloc(length_word+1);
    strcpy(copy_word, word);
    copy_print = (char *)malloc(length_word);
    copy_word[length_word] = '\0';
    copy_print[length_word] = '\0';
    j = 0;
    k = 0;
    i = index;
    while(j < length_word) {
        if(string[i] == copy_word[j]) {
            copy_print[k] = copy_word[j];
            while(j < length_word) {
                copy_word[j] = copy_word[j+1];
                j++;
            }
            k++;
            i++;
            j = 0;
        }
        else {
            j++;
        }
    }
    if(k == length_word) {
        printf("%s\n",copy_print);
        free(copy_word);
        free(copy_print);
        *status = 1;
        return k;
    }
    free(copy_word);
    free(copy_print);
    return 1;
}

