#include <iostream>
using namespace std;

int len(int arr[]){
    int i = 0;
    while(arr[i] != NULL)
        i++;
    return i++;
}

typedef struct Item{
    char name[5];
    int age;
}Item;

typedef struct LinkedList{
    Item* item;
    Item *next;
}Linked_list;

int main() {

}
