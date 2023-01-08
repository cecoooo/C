#include <iostream>
using namespace std;

int lowestCountOfCoin(int num);

int count = 0;

int main() {
    cout << lowestCountOfCoin(120);
}

int lowestCountOfCoin(int num){
    if(num==1){
        count++;
        lowestCountOfCoin(num-1);
    }
    else if(num>=100){
        count++;
        lowestCountOfCoin(num-100);
    }
    else if(num>=50){
        count++;
        lowestCountOfCoin(num-50);
    }
    else if(num>=20){
        count++;
        lowestCountOfCoin(num-20);
    }
    else if(num>=10){
        count++;
        lowestCountOfCoin(num-10);
    }
    else if(num>=5){
        count++;
        lowestCountOfCoin(num-5);
    }
    else if(num>=2){
        count++;
        lowestCountOfCoin(num-2);
    }
    else{
        return count;
    }
}