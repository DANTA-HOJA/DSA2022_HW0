#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset
#include <math.h> //floor, log2

// https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm

int main(){
    char a[257];
    char b[257];
    scanf("%s", a);
    scanf("%s", b);
    printf("%s, %ld ", a, strlen(a));
    printf("%s, %ld ", b, strlen(b));


    char c[257] = {'1', '4', '5', '7', '9', '1', '3', '2', '\0', '\0'};
    printf("%s, %ld ", c, strlen(c));

    return 0;
}