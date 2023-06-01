#include <stdlib.h>
#include "strfuncs.h"

size_t string_length(const char *str){
    unsigned int count = 0u;
    size_t tamaño = 0;
    while (str[count] != '\0'){
        tamaño = tamaño + sizeof(str[count]);
        count++;
    }
    return tamaño;
}

char *string_filter(const char *str, char c){
    char *new_cad = malloc(sizeof(char)*string_length(str)+1); 
    unsigned int indNew = 0u;

    for (unsigned int i = 0u; str[i]!= '\0'; i++){
        if (str[i]!=c){
            new_cad[indNew] = str[i];  
            indNew++;
        }
    }
    new_cad[indNew] = '\0';
    return new_cad;
}

