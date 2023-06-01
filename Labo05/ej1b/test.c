#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){

    stack pila1 = stack_empty();
    pila1 = stack_push(pila1, 60); //agrego un elemento
    pila1 = stack_pop(pila1); //saco el elemento
    printf("%d\n", stack_is_empty(pila1)); // si funciona la lista me queda vacia 
   
    pila1 = stack_push(pila1, 60); //inserto un elemento
    printf("%d\n", stack_size(pila1));
   
    stack pila2 = stack_empty();
    pila2 = stack_push(pila2, 60);
    pila2 = stack_push(pila2, 70);
    pila2 = stack_push(pila2, 80);
    stack_elem *q = stack_to_array(pila2);
    for(unsigned int i = 0u ; stack_size(pila2) > i ; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
    
    stack pila3 = stack_empty();
    printf("%d\n", stack_size(pila3));
   
    return 0;
}