#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE * fp;
    unsigned int size;
    fp = fopen (filepath, "r");
    if (fp == NULL){
        printf("Couldn't open file \n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%u", &size);
    if (size > max_size){
        printf ("Max size allowed is %d \n", max_size);
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i < size; i++){
        fscanf (fp, "%d", &array[i]);
        if(i == size - 1 && feof(fp)){
            printf ("Invalid size \n");
            exit(EXIT_FAILURE);
        }
    }   
    fclose(fp);
return size;
}

void array_dump(int a[], unsigned int length) {
    printf ("[ ");
    for (unsigned int i = 0; i < length; i++) { 
        printf("%d ", a[i]);
    }
    printf("]");
    printf("\n");
}

bool array_is_sorted(int a[], unsigned int length){
    bool result = true;
    for (unsigned int i = 0; i < length - 1 && result == true; i++){
        if (a[i] > a[i+1]){
            result = false;
        }
    }
    return result;
}



