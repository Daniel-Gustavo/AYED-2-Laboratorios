#include <stdbool.h>
#include <assert.h>
#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
unsigned int cc = 0;
for(unsigned int i=0; i<FIXSTRING_MAX; i++){
    if(s[i] != '\0'){
        cc = cc + 1;
    }
}
return cc;
}

bool fstring_eq(fixstring s1, fixstring s2) {
bool v = true;
for(unsigned int i=0; i<FIXSTRING_MAX; i++){
    if(s1[i] != s2[i] && v==true){
        v = false;
    }
}
return v;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool v = false;
    int e = fstring_length(s1);
    int t = fstring_length(s2);
    if(e == t){
        for(unsigned int i=0; i<FIXSTRING_MAX; i++){
            if(s1[i]<=s2[i]){
                    v = true;
            }
        }
    }
    return v;
}

/*
 gcc -Wall -Werror -Wextra -pedantic -std=c99 -c fixstring.c
 gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c

 gcc -Wall -Werror -Wextra -pedantic -std=c99 fixstring.o main.o -o reader

*/
