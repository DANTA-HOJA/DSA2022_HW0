#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset

int main(){
    int fake_a [] = {1, 3};
    int fake_b [] = {2, 4};
    int *real_a = fake_a;
    int *real_b = fake_b;
    for (int i=0; i<2; i++){
        printf("%d ", *(real_a + i));
    }
    for (int i=0; i<2; i++){
        printf("%d ", *(real_b + i));
    }

    int *tmp = real_a;
    real_a = real_b; //----------------------------------> ans(1)(2)
    real_b = tmp; //----------------------------------> ans(3)(4)

    for (int i=0; i<2; i++){
        printf("%d ", *(real_a + i));
    }
    for (int i=0; i<2; i++){
        printf("%d ", *(real_b + i));
    }

}