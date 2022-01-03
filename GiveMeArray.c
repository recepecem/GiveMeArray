//Stupid Random Array maker.
//recepecem
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * GiveMeArray(int*, int ArraySize);

int main(int argc, char *argv[]){
    srand(time(NULL));
    
    if(argc!=2){
	fprintf(stderr,"\nusage:\n\t\t%s [array size]\n\n",argv[0]);
	return -1;
    }

    int ARR_SIZ = atoi(argv[1]);

    int array[ARR_SIZ];
    GiveMeArray(array, ARR_SIZ);

    FILE *fptr = fopen("array.txt", "w");
    
    for (int i = 0; i < ARR_SIZ; ++i)
        fprintf(fptr,"%d,",array[i]);
 
    printf("\nsaved\n");


    return 0;
}//end of main


int * GiveMeArray(int array[], int ARR_SIZ){
    int num, chk = -1;

    for (int i = 0; i < ARR_SIZ; ++i) {
        num = rand() % ARR_SIZ + 1;
        array[i] = num;

        if(!(i%(ARR_SIZ/100)) && chk != i){	//%x 
            system("clear");	//works on linux
            
            for (int j = 0; j < i/(ARR_SIZ/10); ++j)
                printf("|");
            printf("%%%d\n", i / (ARR_SIZ / 100));
        }
        chk = i;

        for (int j = 0; j <= i; ++j) {
            if ((array[i] == array[j]) && i != j){
                i--;
                break;
            }
        }
    }
    printf("\n||||||||||%%100\n\ndone...\n\n");
    return array;
}
