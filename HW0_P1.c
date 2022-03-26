#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset
#include <math.h> //floor, log2

#define DEBUG 0

void seperate_two_int(char *strarry, char *BigInt1, char *BigInt2){
    int ASSIGN2BIGINT2=0;
    int STOPOFSTR=0;
    for(int i=0; i<600; i++){
        if(!((strarry[i]>='0')&&(strarry[i]<='9'))){
            STOPOFSTR+=1;
            if(STOPOFSTR==2){
                break;
            }
            ASSIGN2BIGINT2=i+1;
            continue;
        }
        if(ASSIGN2BIGINT2==0){BigInt1[i]=strarry[i];}
        else{BigInt2[i-ASSIGN2BIGINT2]=strarry[i];}
    }
}

void show_BigInt(char *BigInt, int digits_BigInt, const char *Name, const char *description){
    printf("%s", description);
    printf("%s = ", Name);
    for(int i=0; i<256; i++){
        printf("%c", BigInt[i]);
    }
    printf(", digits = %d", digits_BigInt);
    printf(", ptr = %p\n", BigInt);
}

int get_digits(char *BigInt){
    for(int i=0; i<256; i++){
        if(BigInt[i]=='\0'){return i;}
    }
    return 256;
}

void orderSWAP(char *BigInt, int digits){
    int MaxIndex = 0;
    MaxIndex=digits-1;
    for(int i=0; i<floor(digits/2); i++){
        char tmp=0;
        tmp = BigInt[MaxIndex-i];
        BigInt[MaxIndex-i] = BigInt[i];
        BigInt[i] = tmp;
    }
}

#if (DEBUG==1)
int get_large_num(char *BigInt1, char *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int condition=0;
    if(digits_BigInt1>digits_BigInt2){
        condition=1; //digits_BigInt1>digits_BigInt2
        printf("condition=1, digits_BigInt1>digits_BigInt2, ");
        return 1;
    }
    else if(digits_BigInt1==digits_BigInt2){
        for(int i=(digits_BigInt1-1); i>=0; i--){
            if(BigInt1[i]>BigInt2[i]){
                condition=2; //digits_BigInt1==digits_BigInt2 & BigInt1[i]>BigInt2[i]
                printf("condition=2, digits_BigInt1==digits_BigInt2 & BigInt1[i]>BigInt2[i] @digits%d, ", i+1);
                return 1;
            }
            else if(BigInt1[i]==BigInt2[i]){continue;}
            else{
                condition=3; //digits_BigInt1==digits_BigInt2 & BigInt1[i]<BigInt2[i]
                printf("condition=3, digits_BigInt1==digits_BigInt2 & BigInt1[i]<BigInt2[i] @digits%d, ", i+1);
                return 2;
            }
        }
        condition=4; //digits_BigInt1==digits_BigInt2 & BigInt1[i]==BigInt2[i]
        printf("condition=4, digits_BigInt1==digits_BigInt2 & BigInt1[i]==BigInt2[i], ");
        return 0;
    }
    else{
        condition=5; //digits_BigInt1<digits_BigInt2
        printf("condition=5, digits_BigInt1<digits_BigInt2, ");
        return 2;
    }
}
#else
int get_large_num(char *BigInt1, char *BigInt2, int digits_BigInt1, int digits_BigInt2){
    int condition=0;
    if(digits_BigInt1>digits_BigInt2){return 1;}
    else if(digits_BigInt1==digits_BigInt2){
        for(int i=(digits_BigInt1-1); i>=0; i--){
            if(BigInt1[i]>BigInt2[i]){return 1;}
            else if(BigInt1[i]==BigInt2[i]){continue;}
            else{return 2;}
        }
        return 0; // return 0 == two BigInts are equal!!
    }
    else{return 2;}
}
#endif

char *max(char *BigInt1, char *BigInt2, const char *Name1, const char *Name2){
    int LargeNum = get_large_num(BigInt1, BigInt2, get_digits(BigInt1), get_digits(BigInt2));
    if(LargeNum==0){
        printf("After max() check, two BigInts are equal!!\n");
        return BigInt1; //兩數相等時，統一max()回傳BigInt1
    }
    else if(LargeNum==1){
        printf("After max() check, Larger = %s\n", Name1);
        return BigInt1;
    }
    else{
        printf("After max() check, Larger = %s\n", Name2);
        return BigInt2;
    }
}

char *min(char *BigInt1, char *BigInt2, const char *Name1, const char *Name2){
    int LargeNum = get_large_num(BigInt1, BigInt2, get_digits(BigInt1), get_digits(BigInt2));
    if(LargeNum==0){
        printf("After min() check, two BigInts are equal!!\n");
        return BigInt2; //兩數相等時，統一min()回傳BigInt2
    }
    else if(LargeNum!=1){
        printf("After min() check, Larger = %s\n", Name1);
        return BigInt1;
    }
    else{
        printf("After min() check, Larger = %s\n", Name2);
        return BigInt2;
    }
}

int is_even(char *BigInt){
    if(BigInt[0]%2 == 0){return 1;}
    else{return 0;}
}

int not_zero(char *BigInt){
    if(BigInt[0] != '\0'){return 1;}
    else{return 0;}
}

int NULL_correction(char *BigInt){
    int digits = get_digits(BigInt);
    if((BigInt[digits-1]=='0')&&(BigInt[digits]=='\0')){
        BigInt[digits-1]='\0';
        digits = NULL_correction(BigInt);
        return digits;
    }
    return digits;    
}

void divid_2(char *BigInt, int carry, int step){
    // printf("1. %p, BigInt[0] = %c, carry = %d\n", BigInt, BigInt[0], carry);
    if (step == 0){return;}
    int tmp = (int)BigInt[0]-(int)'0';
    tmp += carry;
    int quotient = tmp/2;
    int remainder = tmp%2;
    carry = remainder*10;
    // printf("2. quotient = %d, remainder = %d\n", quotient, remainder);
    BigInt[0] = (char)(quotient+48);
    // printf("3. BigInt[0] = %c, carry = %d\n\n", BigInt[0], carry);
    step-=1;
    divid_2(&BigInt[-1], carry, step);
}

void multiply_2(char *BigInt, int carry, int step){
    // printf("1. BigInt[0] = %c, carry = %d, step = %d\n", BigInt[0], carry, step);
    if (step==-1){return;}
    int tmp = (int)BigInt[0]-(int)'0';
    if(tmp<0){tmp=0;}
    tmp = tmp*2+carry;
    // printf("2. BigInt[0] = %d\n", tmp);
    carry=0;
    if(tmp>9){
        tmp-=10;
        carry++;
    }
    BigInt[0] = (char)(tmp+48);
    // printf("3. BigInt[0] = %c, carry = %d\n\n", BigInt[0], carry);
    step -= 1;
    multiply_2(&BigInt[1], carry, step);
}

void M_minus_N(char *m, char*n, int step){
    // printf("1. m[0] = %c, n[0] = %c, step = %d\n", m[0], n[0], step);
    if(step==0){return;}
    int tmp_m = (int)m[0]-(int)'0';
    int tmp_n = (int)n[0]-(int)'0';
    if(tmp_n<0){tmp_n=0;}
    int result = tmp_m-tmp_n;
    // printf("2. result =  %d\n", result);
    if(result<0){
        m[1]-=1;
        result = tmp_m+10-tmp_n;
        // printf("3. borrow 1, new result =  %d\n", result);
    }
    m[0]=(char)(result+48);
    step-=1;
    // printf("4. m[0] = %c, n[0] = %c, step = %d\n\n", m[0], n[0], step);
    M_minus_N(&m[1], &n[1], step);
}

void multiply_2powK(char *BigInt, int digits_BigInt, char* coeff_2k){
    int _ans = 0;
    for(int i=0; i<256; i++){
        int tmp = (int)coeff_2k[i]-(int)'0';
        if(tmp<0){break;}
        else{
            _ans+=tmp*pow(10,i);
            // printf("tmp = %d, coeff_2k[i] = %c, ", tmp, coeff_2k[i]);
            // printf("10^i = %d", pow(10,i));
            // printf("_ans = %d\n", _ans);
        }
    }
    for(int i=0; i<(log2(_ans)); i++){
        multiply_2(BigInt, 0, digits_BigInt);
        digits_BigInt = NULL_correction(BigInt);
        show_BigInt(BigInt, digits_BigInt, "BigInt", "After mutiply_2(), "); // ------------------- print BigInt
    }
}

void Div_2(char *BigInt, int *digits_BigInt, const char *Name){
    divid_2(&BigInt[*digits_BigInt-1], 0, *digits_BigInt);
    *digits_BigInt = NULL_correction(BigInt);
    show_BigInt(BigInt, *digits_BigInt, Name, "After __divid_2(_), "); // ------------------- print BigInt
}

void Muti_2(char *BigInt, int *digits_BigInt, const char *Name){
    multiply_2(BigInt, 0, *digits_BigInt); //個位數沒有上一位，進位填0    
    *digits_BigInt = NULL_correction(BigInt);
    show_BigInt(BigInt, *digits_BigInt, Name, "After mutiply_2(), "); // ------------------- print BigInt
}

void M_Minus_N(char *m, char *n, int *digits_m, int *digits_n, const char *Name_m, const char *Name_n){
    M_minus_N(m, n, *digits_m);
    *digits_m = NULL_correction(m);
    *digits_n = NULL_correction(n);
    show_BigInt(m, *digits_m, Name_m, "After M_minus_N(), "); // ------------------- print BigInt
    show_BigInt(n, *digits_n, Name_n, "After M_minus_N(), "); // ------------------- print BigInt
}

void Muti_2PowK(char *BigInt, int *digits_BigInt, char *coeff_2k, const char *Name){
    multiply_2powK(BigInt, *digits_BigInt, coeff_2k);
    *digits_BigInt = NULL_correction(BigInt);
    show_BigInt(BigInt, *digits_BigInt, Name, "After multiply_2powK(), "); // ------------------- print BigInt
}

int main(){

    //### initialize array.
    char strarry[600]={'\0'};
    char BigInt1[257]={'\0'}; 
    char BigInt2[257]={'\0'};
    char ans[257]={'\0'};
    // printf("Please input two big integer\n");
    fgets(strarry, sizeof(strarry), stdin);

    //### sperate two BigInt.
    seperate_two_int(strarry, BigInt1, BigInt2);
    int digits_BigInt1 = get_digits(BigInt1);
    int digits_BigInt2 = get_digits(BigInt2);
    show_BigInt(BigInt1, digits_BigInt1, "BigInt1", "User input, "); // ------------------- print BigInt
    show_BigInt(BigInt2, digits_BigInt2, "BigInt2", "User input, "); // ------------------- print BigInt
    printf("\n");

    //### Change LSB <-> HSB.
    orderSWAP(BigInt1, digits_BigInt1);    
    orderSWAP(BigInt2, digits_BigInt2);
    show_BigInt(BigInt1, digits_BigInt1, "BigInt1", "After orderSWAP(), "); // ------------------- print BigInt
    show_BigInt(BigInt2, digits_BigInt2, "BigInt2", "After orderSWAP(), "); // ------------------- print BigInt
    printf("\n");

    //### n ← min(a, b), m ← max(a, b), ans ← 1.
    char *m = max(BigInt1, BigInt2, "BigInt1", "BigInt2");
    char *n = min(BigInt1, BigInt2, "BigInt1", "BigInt2");
    ans[0]='1';
    int digits_m = get_digits(m);
    int digits_n = get_digits(n);
    int digits_ans = get_digits(ans);
    // printf("ptr_BigInt1= %p, ptr_BigInt2= %p\nptr_m= %p, ptr_n= %p\n\n",&BigInt1, &BigInt2, m, n);
    printf("\n");
    show_BigInt(m, digits_m, "m", "init, "); // ------------------- print BigInt
    show_BigInt(n, digits_n, "n", "init, "); // ------------------- print BigInt
    show_BigInt(ans, digits_ans, "ans", "init, "); // ------------------- print BigInt
    getchar(); // ------------------- wait
    system("clear"); // ------------------- clear

    //### st. while loop
    int loop_count = 1;
    while(not_zero(n)&&not_zero(m)){
        printf("loop = %d ==>\n", loop_count); // ------------------- print #th loop
        printf("\nnot_zero(m), not_zero(n)\n"); // ------------------- print status
        show_BigInt(m, digits_m, "m", " -> "); // ------------------- print BigInt
        show_BigInt(n, digits_n, "n", " -> "); // ------------------- print BigInt
        show_BigInt(ans, digits_ans, "ans", " -> "); // ------------------- print BigInt
        if(is_even(n)&&is_even(m)){
            printf("n, m is even\n"); // ------------------- print status
            
            //### ans ← ans × 2
            Muti_2(ans, &digits_ans, "ans");
            
            //### m ← m/2
            Div_2(m, &digits_m, "m");
            
            //### n ← n/2
            Div_2(n, &digits_n, "n");
            printf("\n"); // ------------------- print new lines to align
        }
        else if(is_even(n)){
            printf("only n is even\n"); // ------------------- print status
            
            //### n ← n/2
            Div_2(n, &digits_n, "n");
            show_BigInt(m, digits_m, "m", "After __divid_2(n), "); // ------------------- print BigInt
            printf("\n\n"); // ------------------- print new lines to align
        }
        else if(is_even(m)){
            printf("only m is even\n"); // ------------------- print status
            
            //### m ← m/2
            Div_2(m, &digits_m, "m");
            show_BigInt(n, digits_n, "n", "After __divid_2(m), "); // ------------------- print BigInt
            printf("\n\n"); // ------------------- print new lines to align
        }
        else{
            printf("n, m is NOT even\n\n\n\n\n"); // ------------------- print status
        }
        if(max(n,m,"n","m")!=m){

            //### swap(n,m)
            printf("Need to SWAP n, m\n"); // ------------------- print status
            char *tmp = m;
            m = n;
            n = tmp;
        }
        else{
            printf("DON'T need to SWAP n, m\n"); // ------------------- print status
        }
        digits_m = NULL_correction(m);
        digits_n = NULL_correction(n);
        show_BigInt(m, digits_m, "m", "After __SWAP_NM(), "); // ------------------- print BigInt
        show_BigInt(n, digits_n, "n", "After __SWAP_NM(), "); // ------------------- print BigInt
        printf("\n"); // ------------------- print new lines to align
        
        //### m ← (m − n)
        M_Minus_N(m, n, &digits_m, &digits_n, "m", "n");
        loop_count++;
        getchar(); // ------------------- wait
        system("clear"); // ------------------- clear
    }

    Muti_2PowK(n, &digits_n, ans, "n");

    orderSWAP(n, digits_n);
    show_BigInt(n, digits_n, "Ans", "Binary Algorithm for Greatest Common Divisor => "); // ------------------- print BigInt

    //### output
    for(int i=0; i<256; i++){
        if(n[i]=='\0'){
            printf("\n");
            break;
        }
        printf("%c", n[i]);
    }

    printf("\n=> total loop = %d\n", loop_count); // ------------------- print total loop
    
    return 0;

    // Div_2(m, &digits_m, "m");
    // orderSWAP(m, digits_m);
    // show_BigInt(m, digits_m, "m", "After orderSWAP(), ");
    // orderSWAP(m, digits_m);

    // Muti_2(m, &digits_m, "m");
    // orderSWAP(m, &digits_m);
    // show_BigInt(m, digits_m, "m", "After orderSWAP(), ");
    // orderSWAP(m, &digits_m);

    // ans[0] = '8';
    // show_BigInt(ans, digits_ans, "ans", ""); // ------------------- print BigInt
    // Muti_2PowK(m, &digits_m, ans, "m");

    // M_Minus_N(m, n, &digits_m, &digits_n, "m", "n");
}