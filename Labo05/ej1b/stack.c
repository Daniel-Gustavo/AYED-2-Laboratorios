#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct node {
    stack_elem elem ;
    struct node *next ;
}; 

struct _s_stack{
    unsigned int cant ;
    struct node *first ;
} ;

stack stack_empty(){
    stack p = malloc(sizeof(struct _s_stack));
    p->cant = 0;
    p->first = NULL;
    return p;
}

stack stack_push(stack s, stack_elem e){
    struct node *new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = s->first; 
    if(s != NULL){
        s->cant ++;; 
    } else {
        s->cant = 1; 
    } 
    s->first = new; 

    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    struct node *p; 
    p = s->first;
    s->first = (s->first)->next;
    s->cant--;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int res = 0;
    if (s != NULL){
        res = s->cant;
    }
    return res;
}

stack_elem stack_top(stack s){ 
    assert(!stack_is_empty(s));
    stack_elem res;
    res = (s->first)->elem;
    return res;
}

bool stack_is_empty(stack s){
    return (s == stack_empty());
}

stack stack_destroy(stack s){
    stack p; 
    p = s;
    while ((s->first)->next != NULL){
        p = s;
        s->first = s->first->next;
        free(p);
    }
    return s;
}

stack_elem *stack_to_array(stack s){
    stack_elem *arreglo = NULL;    
    if (stack_size(s) > 0){
        size_t e = stack_size(s) - 1; 
        arreglo = calloc(stack_size(s),sizeof(stack_elem));
        struct node *i = s->first; 
        while (i != NULL){ 
            arreglo[e] = i->elem; 
            e--; 
            i = i->next;
        }
    }
    return arreglo;
}


