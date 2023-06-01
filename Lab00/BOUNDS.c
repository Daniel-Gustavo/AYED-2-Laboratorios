#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;//lo inicio en true por el resultado del if            
    res.is_lowerbound = true;//lo inicio en true por el resultado del if
    res.exists= false;//lo inicio en false por si no existe en el array
   
    for(int i= 0; i<length; i++) {
        if (value >= arr[i] && res.is_upperbound) {//tiene que cumplir la condicion de mayor o igual, sino por el and, entra por else
            res.is_upperbound = true;//valor de verdad si se cumple la condicion de cota superior
        }
        else {
            res.is_upperbound = false;
        }
        if (value <= arr[i] && res.is_lowerbound) {//tiene que cumplir la condicion de mayor o igual, sino por el and, entra por else
            res.is_lowerbound= true;//valor de verdad si se cumple la condicion de cota inferior
        }
        else {
            res.is_lowerbound = false;
        }
        if (value == arr[i]) {//se fija si el valor es igual a algun elemento, en caso de que lo sea:
            res.exists = true;//da el aviso de que existe;
            res.where = i;//dice donde existe.

        }
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
for (int i= 0; i<ARRAY_SIZE; i++) {
        printf("Ingrese el elemento %d del arreglo\n", i);
        scanf ("%d", &a[i]); //ingresa cada elemento del arreglo y lo guardca en el array
        }
    printf("Ingrese el valor que quiere comparar\n");
    scanf("%d", &value); //guarda el valor para comparar

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound == true && result.exists == true) {
        printf("Su valor es el maximo dentro del arreglo\n"); //comprueba con la funcion que value sea el maximo y lo imprime junto con la posicion
        printf("La posicion de su valor es: %d\n", result.where);
    }
    else if (result.is_upperbound == true && result.exists == false){
        printf("Su valor es cota superior\n"); //si no lo encuentra dentro del array pero es mayor que todos, es una cota sup
    }
    else if (result.is_lowerbound == true && result.exists == true) {
        printf("Su valor es el minimo dentro del arreglo\n");//comprueba con la funcion que value sea el minimo y lo imprime junto con la posicion
        printf("La posicion de su valor es: %d\n",result.where);

    }
    else if (result.is_lowerbound == true && result.exists == false){
        printf("Su valor es cota inferior\n");//si no lo encuentra dentro del array pero es menor que todos, es una cota inf
    }
    else if(result.exists==true && result.is_upperbound == false){
        printf("su valor solo existe y su posicion es: %d\n",result.where);
    }
    else if (result.exists==true && result.is_lowerbound == false){
        printf("su valor solo existe y su posicion es: %d\n",result.where);
    } //en estos dos else, solo verifica de que value exista dentro del array, pero que no sea ni maximo ni minimo, ya que esto significa que no es una cota inf 
    // ni sup, printea que el valor existe.
    
    return EXIT_SUCCESS;
}
