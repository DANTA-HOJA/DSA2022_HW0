#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset

void count_two_digits(char *strarray, int lens, int *digits_1, int *digits_2){
    for(int i=0; i<lens; i++){
        // printf("strarry[i] = %c, i=%d\n", strarray[i], i);
        if(strarray[i]==' '){
            *digits_1 = i;
            continue;
        }
        if((strarray[i]=='\n')||(strarray[i]==NULL)){
            *digits_2 = (i-1)-*digits_1;
            break;
        }
    }
    printf("digits_1 = %d, digits_2 = %d\n", *digits_1, *digits_2);
}

int get_large_one(int *BigInt1, int *BigInt2, int digits_1, int digits_2){
    if(digits_1>digits_2){return 1;}
    else if(digits_1==digits_2){
        for(int i=(digits_1-1); i>=0; i--){
            printf("BigInt1[%d] = %d, BigInt2[%d] = %d\n", i, BigInt1[i], i, BigInt2[i]);
            if(BigInt1[i]==BigInt2[i]){continue;}
            else if(BigInt1[i]>BigInt2[i]){return 1;}
            else{return 2;}
        }
        return 0;
    }
    else{return 2;}
}

int main(){
    char strarry[600];
    printf("Please input two big integer\n");
    fgets(strarry, sizeof(strarry), stdin);
    int digits_1=0, digits_2=0;
    count_two_digits(strarry, sizeof(strarry), &digits_1, &digits_2);
    // create BigInt2
    int *BigInt1 = (int *)calloc((digits_1+1), sizeof(int));
    printf("BigInt1 = ");
    for(int i=0; i<digits_1; i++){
        BigInt1[i] = (int)strarry[(digits_1-1)-i]-(int)'0';
        // printf("BigInt1[i] = %d, i = %d\n", BigInt1[i], i);
    }
    for(int i=0; i<(digits_1+1); i++){
        printf("%d", BigInt1[i]);
    }
    printf("\n");
    // create BigInt2
    int *BigInt2 = (int *)calloc((digits_2+1), sizeof(int)); 
    printf("BigInt2 = ");
    for(int i=0; i<digits_2; i++){
        BigInt2[i] = (int)strarry[(digits_1+digits_2)-i]-(int)'0';
        // printf("BigInt1[i] = %d, i = %d\n", BigInt1[i], i);
    }
    for(int i=0; i<(digits_2+1); i++){
        printf("%d", BigInt2[i]);
    }
    printf("\n");
    
    int a = get_large_one(BigInt1,BigInt2,digits_1,digits_2);
    if(a==0){printf("two BigInts are equal!!\n");}
    else{printf("BigInt%d is large one\n", a);}


}