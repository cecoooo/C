//
// Created by User on 27/06/2023.
//
#include <stdexcept>
#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H
template <typename T>

class LinkedList {
private:
    class Node{
        T value;
        Node *next;
    public:
        Node(){}
        void set_value(T value){
            this->value = value;
        }
        void set_next(Node *next){
            this->next = next;
        }
        Node* get_next(){
            return this->next;
        }
        T get_value(){
            return this->value;
        }
    };
    Node *first = NULL;
    Node *last = NULL;
    int count;
    void clear(Node* node){
        if(node == NULL) return;
        Node *new_node = node->get_next();
        free(node);
        clear(new_node);
    }
public:
    LinkedList(){
        this->count = 0;
    }
    void add(T value){
        if(this->count){
            Node* node = new Node();
            node->set_value(value);
            this->last->set_next(node);
            this->last = node;
            this->last->set_next(NULL);
            this->count++;
        }else{
            this->first = new Node();
            this->first->set_value(value);
            this->last = this->first;
            this->last->set_next(NULL);
            this->count++;
        }
    }
    void insert(int index, T element){
        if(this->count <= index || index < 0){
            throw std::invalid_argument("index outside the bound of the Linked List.");
        }
        else if(index == 0){
            Node *node0 = new Node();
            node0->set_value(element);
            node0->set_next(first);
            first = node0;
        }
        else if(index == this->count-1){
            add(element);
            return;
        }
        else {
            Node *node = first;
            for (int i = 0; i < this->count; ++i) {
                if (i == index - 1) {
                    Node *newNode = new Node();
                    newNode->set_value(element);
                    Node* next_to_current_node = node->get_next();
                    node->set_next(newNode);
                    newNode->set_next(next_to_current_node);
                    break;
                }
                node = node->get_next();
            }
        }
        this->count++;
    }
    T get_first(){
        return this->first->get_value();
    }
    T get_last(){
        return this->last->get_value();
    }
    T get_at(int index){
        if(this->count <= index || index < 0){
            throw std::invalid_argument("index outside the bound of the Linked List.");
        }
        Node *node = this->first;
        for (int i = 0; i < this->count; ++i) {
            if(i == index){
                return node->get_value();
            }
            node = node->get_next();
        }
    }
    void remove_first(){
        this->first = this->first->get_next();
        this->count--;
    }
    void remove_last(){
        Node *node = this->first;
        for (int i = 1; i < this->count-1; ++i) {
            node = node->get_next();
        }
        this->last = node;
        this->last->set_next(NULL);
        this->count--;
    }
    void remove_at(int index){
        if(this->count <= index || index < 0){
            throw std::invalid_argument("index outside the bound of the Linked List.");
        }
        else if(index == 0){
            remove_first();
            return;
        }
        else if(index == this->count-1){
            remove_last();
            return;
        }
        Node* node = this->first;
        for (int i = 0; i < this->count; ++i) {
            if(i == index-1){
                node->set_next(node->get_next()->get_next());
                break;
            }
            node = node->get_next();
        }
        this->count--;
    }
    void clear(){
        clear(this->first);
        this->count=0;
        this->first = NULL;
        this->last = NULL;
    }
    void reverse(){

    }
    int size(){
        return this->count;
    }
};

//add()
//remove_first()
//remove_last()
//remove_at()
//remove_all()
//insert()
//get_first()
//get_last()
//get_at()
//clear()
//reverse()
//size()

#endif //DATA_STRUCTURES_LINKEDLIST_H
