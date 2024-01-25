myset:myset.o set.o valid_func.o
	gcc -Wall -ansi -pedantic -g myset.o set.o valid_func.o -o myset
myset.o: myset.c set.h valid_func.h
	gcc -Wall -ansi -pedantic -c myset.c -o myset.o
set.o: set.c set.h
	gcc -Wall -ansi -pedantic -c set.c -o set.o
valid_func.o: valid_func.c valid_func.h set.h
	gcc -Wall -ansi -pedantic -c valid_func.c -o valid_func.o

