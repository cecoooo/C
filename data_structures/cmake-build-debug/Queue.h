//
// Created by User on 25/06/2023.
//

#include <cstdlib>

template <typename T>

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H


class Queue {
private:
    T* data;
    int count;
    T head;
public:
    Queue(){
        this->count = 0;
        this->data = new T[1];
    }
    void push(T element){
        this->data[this->count] = element;
        this->count++;
        this->data = (T*) realloc(this->data, sizeof(T)*(count+1));
    }
    T peek(){
        this->head = this->count ? this->data[0]: NULL;
        return this->head;
    }
    void pop(){
        this->count--;
        this->head = this->data[this->count-1];
        this->data = (T*)realloc(this->data, sizeof(T)*this->count);
    }
    int size() {
        return this->count;
    }
};

#endif //DATA_STRUCTURES_QUEUE_H
