#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset
#include <math.h> //floor

#define DEBUG 1

void seperate_two_int(char *strarry, int *BigInt1, int *BigInt2){
    int ASSIGN2BIGINT2=0;
    int STOPOFSTR=0;
    for(int i=0; i<600; i++){
        if(!(((int)strarry[i]>47)&&((int)strarry[i]<58))){
            STOPOFSTR+=1;
            if(STOPOFSTR==2){
                break;
            }
            ASSIGN2BIGINT2=i+1;
            continue;
        }
        if(ASSIGN2BIGINT2==0){BigInt1[i]=(int)strarry[i]-(int)'0';}
        else{BigInt2[i-ASSIGN2BIGINT2]=(int)strarry[i]-(int)'0';}
    }
    //print Info
    printf("BigInt1 = ");
    for(int i=0; i<256; i++){
        printf("%d", BigInt1[i]);
    }
    printf("\n");
    printf("BigInt2 = ");
    for(int i=0; i<256; i++){
        printf("%d", BigInt2[i]);
    }
    printf("\n");
}

int orderSWAP(int *BigInt){
    int digits = 0;
    int MaxIndex = 0;
    for(int i=0; i<256; i++){
        // printf("BigInt[%d] = %d\n", i, BigInt[i]);
        if((char)BigInt[i]=='\0'){
            digits=i;
            MaxIndex=i-1;
            break;
        }
    }
    for(int i=0; i<floor(digits/2); i++){
        int tmp=0;
        tmp = BigInt[MaxIndex-i];
        BigInt[MaxIndex-i] = BigInt[i];
        BigInt[i] = tmp;
    }
    printf("After orderSWAP, BigInt = ");
    for(int i=0; i<256; i++){
        printf("%d", BigInt[i]);
    }
    printf(", digits = %d\n", digits);
    return digits;
}

#if (DEBUG==1)
int get_large_num(int *BigInt1, int *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int condition=0;
    if(digits_BigInt1>digits_BigInt2){
        condition=1; //digits_BigInt1>digits_BigInt2
        printf("condition=1, digits_BigInt1>digits_BigInt2\n");
        return 1;
    }
    else if(digits_BigInt1==digits_BigInt2){
        for(int i=(digits_BigInt1-1); i>=0; i--){
            if(BigInt1[i]>BigInt2[i]){
                condition=2; //digits_BigInt1==digits_BigInt2 & BigInt1[i]>BigInt2[i]
                printf("condition=2, digits_BigInt1==digits_BigInt2 & BigInt1[i]>BigInt2[i] @digits%d\n", i+1);
                return 1;
            }
            else if(BigInt1[i]==BigInt2[i]){continue;}
            else{
                condition=3; //digits_BigInt1==digits_BigInt2 & BigInt1[i]<BigInt2[i]
                printf("condition=3, digits_BigInt1==digits_BigInt2 & BigInt1[i]<BigInt2[i] @digits%d\n", i+1);
                return 2;
            }
        }
        condition=4; //digits_BigInt1==digits_BigInt2 & BigInt1[i]==BigInt2[i]
        printf("condition=4, digits_BigInt1==digits_BigInt2 & BigInt1[i]==BigInt2[i]\n");
        return 0;
    }
    else{
        condition=5; //digits_BigInt1<digits_BigInt2
        printf("condition=5, digits_BigInt1<digits_BigInt2\n");
        return 2;
    }
}
#else
int get_large_num(int *BigInt1, int *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int condition=0;
    if(digits_BigInt1>digits_BigInt2){return 1;}
    else if(digits_BigInt1==digits_BigInt2){
        for(int i=(digits_BigInt1-1); i>=0; i--){
            if(BigInt1[i]>BigInt2[i]){return 1;}
            else if(BigInt1[i]==BigInt2[i]){continue;}
            else{return 2;}
        }
        return 0;
    }
    else{return 2;}
} // return 0 == two BigInts are equal!!
#endif

int *max(int *BigInt1, int *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int LargeNum = get_large_num(BigInt1, BigInt2, digits_BigInt1, digits_BigInt2);
    if(LargeNum==0){
        printf("two BigInts are equal!!\n");
        return BigInt1; //例外：兩數相等時，為使程式可往下運算，統一max()回傳BigInt1
    }
    else{printf("Larger = BigInt%d\n", LargeNum);}
    if(LargeNum==1){return BigInt1;}
    else{return BigInt2;}
}

int *min(int *BigInt1, int *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int LargeNum = get_large_num(BigInt1, BigInt2, digits_BigInt1, digits_BigInt2);
    if(LargeNum==0){
        printf("two BigInts are equal!!\n");
        return BigInt2; //例外：兩數相等時，為使程式可往下運算，統一min()回傳BigInt2
    }
    else{printf("Larger = BigInt%d\n", LargeNum);}
    if(LargeNum!=1){return BigInt1;}
    else{return BigInt2;}
}

int is_even(int *BigInt){
    if(BigInt[0]%2 == 0){return 1;}
    else{return 0;}
}

int not_zero(int *BigInt){
    if(BigInt[0] != NULL){return 1;}
    else{return 0;}
}

void divid_2(){
    
}

void multiply_2(int *BigInt, int preDigits_carry){
    //printf("1. BigInt[0] = %d, preDigits_carry = %d\n", BigInt[0], preDigits_carry);
    BigInt[0] = BigInt[0]*2+preDigits_carry;
    if (BigInt[0]==0){
        return;
    }
    int add2NextDigits;
    // printf("2. BigInt[0] = %d\n", BigInt[0]);
    if(BigInt[0]>9){
        BigInt[0]-=10;
        add2NextDigits++;
    }
    // printf("3. BigInt[0] = %d, add2NextDigits = %d\n\n", BigInt[0], add2NextDigits);
    multiply_2(&BigInt[1], add2NextDigits);
}

void multiply_2K(){

}

void A_minus_B(){

}

void SWAP(){
    
}

int main(){
    int a = 38;
    printf(" %c\n %d\n", a, a);
    char strarry[600]={NULL};
    int BigInt1[256]={NULL}; 
    int BigInt2[256]={NULL};
    int ans[256]={NULL};
    printf("Please input two big integer\n");
    fgets(strarry, sizeof(strarry), stdin);
    seperate_two_int(strarry, BigInt1, BigInt2);
    int digits_BigInt1 = orderSWAP(BigInt1);
    int digits_BigInt2 = orderSWAP(BigInt2);
    int *m = max(BigInt1,BigInt2,digits_BigInt1,digits_BigInt2);
    int *n = min(BigInt1,BigInt2,digits_BigInt1,digits_BigInt2);
    printf("ptr_BigInt1= %p, ptr_BigInt2= %p\nptr_m= %p, ptr_n= %p\n",&BigInt1, &BigInt2, m, n);
    printf("is_even(BigInt1) = %d, is_even(BigInt2) = %d\n", is_even(BigInt1), is_even(BigInt2));
    printf("not_zero(BigInt1) = %d, not_zero(BigInt2) = %d\n", not_zero(BigInt1), not_zero(BigInt2));


    multiply_2(BigInt1, 0); //個位數沒有上一位，進位填0
    printf("After mutiply_2(), new BigInt1 = ");
    for(int i=0; i<256; i++){
        // printf("I am here--------------------------");s
        if((char)BigInt1[i] == (char)NULL){break;}
        printf("%d", BigInt1[i]);
    }
    printf("\n");


    return 0;
}