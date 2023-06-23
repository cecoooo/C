#include <iostream>
#include <stdio.h>

int addition(int num1, int num2);
int subtraction(int num1, int num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);

int main() {
    int num1=0, num2=0;
    printf("Enter number:");
    scanf("%d", &num1);
    printf("Enter number:");
    scanf("%d", &num2);
    printf("Results('+', '-', '*', '/'): %d, %d", addition(num1, num2), subtraction(num1, num2));
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

