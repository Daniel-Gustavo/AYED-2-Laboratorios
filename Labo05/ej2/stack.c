#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila (va de 1 al 3 por ejemplo)
    unsigned int capacity;  // Capacidad actual del arreglo elems 
};

bool inv_rep(stack s){
    return (s != NULL ? (s->size <= s->capacity) && (s->capacity > 0 && s->elems != NULL) : (s->size == 0 && s->capacity == 0 && s->elems == NULL));
}

stack stack_empty(){
    stack p = malloc(sizeof(struct _s_stack));
    p->elems = malloc(sizeof(stack_elem));
    p->size = 0u;
    p->capacity = 1u;
    assert(stack_is_empty(p) && inv_rep(p));
    return p;
}

stack stack_push(stack s, stack_elem e){
    assert(inv_rep(s));
    s->size++; 
    if(s->size > s->capacity){ 
        s->elems = realloc(s->elems,sizeof(stack_elem)*s->capacity*2); 
        s->capacity *= 2;
    }
    s->elems[s->size-1] = e;
    assert(inv_rep(s));
    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s) && inv_rep(s));
    s->size--; 
    return s;
    assert(inv_rep(s));
}

unsigned int stack_size(stack s){
    if (s == NULL){
        return 0u;
    }
    return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s) && inv_rep(s));
    return s->elems[s->size-1]; 
    assert(inv_rep(s));
}

bool stack_is_empty(stack s){
    return s->size == 0; 
    assert(inv_rep(s));
}

stack_elem *stack_to_array(stack s){
    stack_elem *new_array = calloc(s->size,sizeof(stack_elem)); 
    for (unsigned int i = 0u ; i < s->size; ++i){
        new_array[i] = s->elems[i];  
    }
    return new_array;
}

stack stack_destroy(stack s){
    free(s->elems); 
    free(s); 
    s = NULL; 
    return s;
}

