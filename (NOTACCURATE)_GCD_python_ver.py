import random
import math
import os
from this import d
import numpy as np

np.set_printoptions(suppress=True) 

from matplotlib.pyplot import show

## init BigInt"a" and BigInt"b"
# a = random.randint(10^56-1,10^256-1)
# b = random.randint(10^56-1,10^256-1)
# while(a==b):
#     b = random.randint(1,10^256-1)
os.system("cls")
str_a = input("please input BigInt\"a\": ")
str_b = input("please input BigInt\"b\": ")
BigInt_arrayarray = np.array([int(str_a), int(str_b)])
print("")

def get_digits(num):
    if num > 0:
        digits = int(math.log10(num))+1
    elif num == 0:
        digits = 1
    return digits

def show_BigInt(BigInt, digits, name, description):
    print("{:s}, {:s} = {:d}, digits = {:d}, id = {:s}".format(description, name, int(BigInt), int(digits), hex(int(id(BigInt)))))
    
m = max(BigInt_arrayarray[0],BigInt_arrayarray[1])
n = min(BigInt_arrayarray[0],BigInt_arrayarray[1])
ans = 1
show_BigInt(m, get_digits(m), "m", "init, ")
show_BigInt(n, get_digits(n), "n", "init, ")
show_BigInt(ans, get_digits(ans), "ans", "init, ")
input()
os.system("cls")

loop_count=1
while((n!=0) and (m!=0)):
    print("loop = "+str(loop_count)+" ==>")
    show_BigInt(m, get_digits(m), "m", " -> ")
    show_BigInt(n, get_digits(n), "n", " -> ")
    show_BigInt(ans, get_digits(ans), "ans", " -> ")
    print("\nnot_zero(m), not_zero(n)")
    if ((n%2==0) and (m%2==0)):
        print("n, m is even")
        ans*=2
        m/=2
        n/=2
        show_BigInt(m, get_digits(m), "m", "After __divid_2(), ")
        show_BigInt(n, get_digits(n), "n", "After __divid_2(), ")
        print("")
    elif(n%2==0):
        print("only n is even")
        n/=2
        show_BigInt(m, get_digits(m), "m", "After __divid_2(), ")
        show_BigInt(n, get_digits(n), "n", "After __divid_2(), ")
        print("")
    elif(m%2==0):
        print("only m is even")
        m/=2
        show_BigInt(m, get_digits(m), "m", "After __divid_2(), ")
        show_BigInt(n, get_digits(n), "n", "After __divid_2(), ")
        print("")
    else: 
        print("n, m is NOT even")
        print("\n\n")
    if(n>m):
        print("Need to SWAP n, m")
        tmp = m
        m = n
        n = tmp
        show_BigInt(m, get_digits(m), "m", "After __SWAP_NM(), ")
        show_BigInt(n, get_digits(n), "n", "After __SWAP_NM(), ")
        print("")
    else:
        print("DON'T need to SWAP n, m")
        print("\n\n")
    m = m-n
    show_BigInt(m, get_digits(m), "m", "After M_minus_N(), ")
    show_BigInt(n, get_digits(n), "n", "After M_minus_N(), ")
    print("")
    loop_count+=1
    input()
    os.system("cls")

show_BigInt(n*ans, get_digits(n*ans), "Ans", "Binary Algorithm for Greatest Common Divisor => ")
