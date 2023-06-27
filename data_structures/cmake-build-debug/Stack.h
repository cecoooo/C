//
// Created by User on 26/06/2023.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <cstdlib>

template <typename T>


class Stack {
private:
    T* data;
    T head;
    int count;
public:
    Stack(){
        this->count = 0;
        this->data = new T[1];
    }
    void push(T element){
        this->data[this->count] = element;
        this->head = element;
        this->count++;
        this->data = (T*)realloc(this->data, sizeof(T)*(this->count+1));
    }
    T peek(){
        return this->head;
    }
    void pop(){
        this->count--;
        this->head = this->data[this->count-1];
        this->data = (T*)realloc(this->data, sizeof(T)*this->count);
    }
    int size(){
        return this->count;
    }
};


#endif //DATA_STRUCTURES_STACK_H
