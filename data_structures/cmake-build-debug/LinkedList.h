//
// Created by User on 27/06/2023.
//

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
    };
    Node *first;
    Node *last;
    int count;
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
            this->count++;
        }else{
            this->first = new Node();
            this->first->set_value(value);
            this->last = this->first;
            this->count++;
        }
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
//size()

#endif //DATA_STRUCTURES_LINKEDLIST_H
