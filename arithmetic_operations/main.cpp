#include <iostream>
#include <stdio.h>

int additionInt(int num1, int num2);
int subtractionInt(int num1, int num2);
int multiplicationInt(int num1, int num2);
int divisionInt(int num1, int num2);
bool isIntegerOdd(int num);

int main() {
    int num1=0, num2=0;
    printf("Enter number:");
    scanf("%d", &num1);
    printf("Enter number:");
    scanf("%d", &num2);
    int add = additionInt(num1, num2);
    int sub = subtractionInt(num1, num2);
    int mul = multiplicationInt(num1, num2);
    int div = divisionInt(num1, num2);
    printf("Results('+', '-', '*', '/'): %d, %d, %d, %d", add, sub, mul, div);
}

bool isIntegerOdd(int num){
    if((num & 1) == 1) return true;
    return false;
}

int additionInt(int num1, int num2){
    int carry = num1 & num2;
    carry<<=1;
    int sum = num1 ^ num2;
    if(carry == 0) return sum;
    num2 = carry;
    num1 = sum;
    additionInt(num1, num2);
}

int subtractionInt(int num1, int num2){
    num2 = additionInt(1, ~num2);
    return additionInt(num1, num2);
}

int multiplicationInt(int num1, int num2){
    bool isNegative = false;
    if(num1 < 0 && num2 < 0){
        num1 = additionInt(~num1, 1);
        num2 = additionInt(~num2, 1);
    }
    else if(num1 < 0){
        num1 = additionInt(~num1, 1);
        isNegative = true;
    }
    else if(num2 < 0){
        num2 = additionInt(~num2, 1);
        isNegative = true;
    }
    int res = 0;
    if(num1 == 0 || num2 == 0) return 0;
    while(num2 != 0) {
        if (isIntegerOdd(num2)) res = additionInt(res, num1);
        num1 <<= 1;
        num2 >>= 1;
    }
    return isNegative ? additionInt(~res, 1) : res;
}

int divisionInt(int num1, int num2){
    bool isNegative = false;
    if(num1 < 0 && num2 < 0){
        num1 = additionInt(~num1, 1);
        num2 = additionInt(~num2, 1);
    }
    else if(num1 < 0){
        num1 = additionInt(~num1, 1);
        isNegative = true;
    }
    else if(num2 < 0){
        num2 = additionInt(~num2, 1);
        isNegative = true;
    }
    int res=0;
    while(num1>=num2){
        num1 = subtractionInt(num1, num2);
        res = additionInt(res, 1);
    }
    return isNegative ? additionInt(~res, 1) : res;
}
