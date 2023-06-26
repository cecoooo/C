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
    Queue():data(new T[1]){
        this->count = 0;
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
    T poll(){
        T res = this->head;
        this->count--;
        T* newData = (T*)malloc(sizeof(T)*(this->count+1));
        for (int i = 1, j = 0; i < this->count+2, j < this->count+1; ++i, j++) {
            newData[j] = this->data[i];
        }
        this->data = newData;
        return res;
    }
};

#endif //DATA_STRUCTURES_QUEUE_H
