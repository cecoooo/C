#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList{

private: class Node{
    public:
        T value;
        Node *previous;
        Node *next;
        Node(T value){
            this->value = value;
        }
    };

private:
    Node head;
    Node tail;
    int count;
public:
    int getCount(){
        return this->count;
    }
    DoublyLinkedList(){

    }

public:
    void AddFirst(T element){
        if(this->count == 0){
            this->head = this->tail = *new Node(element);
        }
        else{
            Node newHead = *new Node(element);
            *newHead.next = this->head;
            newHead.previous = NULL;
            *this->head.previous = newHead;
            this->head = newHead;
        }
        this->count++;
    }
};

int main() {
    DoublyLinkedList<int> list = new DoublyLinkedList<int>();
    cout << list.getCount();
    list.AddFirst(3);
}

