#include <iostream>
#include <stdio.h>

int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);
bool isNumberOdd(int num);

int main() {
    int num1=0, num2=0;
    printf("Enter number:");
    scanf("%d", &num1);
    printf("Enter number:");
    scanf("%d", &num2);
    int add = addition(num1, num2);
    int sub = subtraction(num1, num2);
    int mul = multiplication(num1, num2);
    int div = division(num1, num2);
    printf("Results('+', '-', '*', '/'): %d, %d, %d, %d", add, sub, mul, div);
}

bool isNumberOdd(int num){
    if((num & 1) == 1) return true;
    return false;
}

int addition(int num1, int num2){
    int carry = num1 & num2;
    carry<<=1;
    int sum = num1 ^ num2;
    if(carry == 0) return sum;
    num2 = carry;
    num1 = sum;
    addition(num1, num2);
}

int subtraction(int num1, int num2){
    num2 = addition(1, ~num2);
    return addition(num1, num2);
}

int multiplication(int num1, int num2){
    bool isNegative = false;
    if(num1 < 0 && num2 < 0){
        num1 = addition(~num1, 1);
        num2 = addition(~num2, 1);
    }
    else if(num1 < 0){
        num1 = addition(~num1, 1);
        isNegative = true;
    }
    else if(num2 < 0){
        num2 = addition(~num2, 1);
        isNegative = true;
    }
    int res = 0;
    if(num1 == 0 || num2 == 0) return 0;
    while(num2 != 0) {
        if (isNumberOdd(num2)) res = addition(res, num1);
        num1 <<= 1;
        num2 >>= 1;
    }
    return isNegative? addition(~res, 1): res;
}

int division(int num1, int num2){
    bool isNegative = false;
    if(num1 < 0 && num2 < 0){
        num1 = addition(~num1, 1);
        num2 = addition(~num2, 1);
    }
    else if(num1 < 0){
        num1 = addition(~num1, 1);
        isNegative = true;
    }
    else if(num2 < 0){
        num2 = addition(~num2, 1);
        isNegative = true;
    }
    int res = 0;
    if(num1 == 0 || num2 == 0) return 0;
    while(num2 != 0) {
        if (isNumberOdd(num2)) res = subtraction(res, num1);
        num1 >>= 1;
        num2 >>= 1;
    }
    return isNegative? addition(~res, 1): res;
}
