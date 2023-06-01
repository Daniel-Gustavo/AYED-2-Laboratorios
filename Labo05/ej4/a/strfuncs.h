#ifndef _STRFUNCS_H_
#define _STRFUNCS_H_

#include <stdbool.h>

size_t string_length(const char *str);
/*Calcula la longitud de la cadena apuntada por str*/

char *string_filter(const char *str, char c);
/*Devuelve una nueva cadena en memoria dinámica que se obtiene tomando los
caracteres de str que son distintos del caracter c.*/

#endif