    #include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem; //entero
    stack next; //puntero a _s_stack
};


stack stack_empty(){
    stack p = NULL;
    return p;
}

stack stack_push(stack s, stack_elem e){
    stack q = malloc(sizeof(struct _s_stack));
    q->elem = e;
    q->next = s;
    s = q;  
    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack p; 
    p = s;
    s = s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int contador = 0u; 
    stack p; 
    p = s;
    while (p != NULL){
        p = p->next;
        contador++;
    }
    return contador;
}

stack_elem stack_top(stack s){ 
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return (s == stack_empty());
}

stack_elem *stack_to_array(stack s){
    stack_elem *arreglo = NULL;    
    if (stack_size(s) > 0){
        arreglo = calloc(stack_size(s),sizeof(stack_elem));
        stack i = s; 
        for(unsigned int e=stack_size(s)-1;i!=NULL;i--){
        arreglo[e]=i->elem;
        i=i->next;
    }
    }
    return arreglo;
}

stack stack_destroy(stack s){
    stack p; 
    p = s;
    while (p->next != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}
