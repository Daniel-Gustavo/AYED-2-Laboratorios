/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
      Al finalizar la ejecución las variables deben tener los siguientes valores
      x = 9
      m = (100, F)
      a[1] = 42

      Las restricciones son:
      - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
      - Se pueden agregar líneas de código, pero no modificar las que ya existen.
      - Se pueden declarar hasta 2 punteros.
      AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */
    int *q = NULL;
    q = &x;
    *q = 9;

    q = &a[1];
    *q = 42;

    person_t *p = NULL;
    p = &m;
    p->age = 100;
    p->name_initial='F';
    
    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}


/*
El valor de la variable y será 3. Veamos cómo se llega a este resultado:

Se declara una variable x y se le asigna el valor 3.
Se declara una variable y y se le asigna el valor 10.
La expresión &x obtiene la dirección de memoria de la variable x.
El operador de indirección * se utiliza para acceder al valor almacenado en esa dirección de memoria.
El valor de x (que es 3) se asigna a la variable y.
Como resultado, la variable y se actualiza con el valor de x, que es 3. Por lo tanto, después de ejecutar el código, y contendrá el valor 3.
*/
