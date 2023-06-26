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
    T head = this->count ? this->data[0]: NULL;
public:
    Queue():data(new T[1]){
        this->count = 0;
    }
    void push(T element){
        this->data[this->count] = element;
        this->count++;
        T* newData = (T*) realloc(this->data, count+1);
        this->data = newData;
    }
    T peek(){
        return this->head;
    }
    T poll(){
        T res = this->head;
        this->count--;
        this->data = (T*)realloc(this->data, count+1);
        return res;
    }
};


#endif //DATA_STRUCTURES_QUEUE_H
