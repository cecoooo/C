#include <iostream>
#include "cmake-build-debug/Queue.h"
#include "cmake-build-debug/Stack.h"
#include "cmake-build-debug/LinkedList.h"

using namespace std;

void func(int M, int N){
    for(unsigned i = 5; i >= 0; i--){
        cout<<i;
    }
}

int main() {
//    Queue<int> *queue = new Queue<int>();
//    queue->push(1);
//    queue->push(2);
//    queue->push(3);
//    queue->push(4);
//    cout << "head:" << queue->peek()<<"\n";
//    queue->pop();
//    cout << "head:" << queue->peek();
//    free(queue);


//    int *a, *b, *c, *d;
//    a = (int*) calloc(3, sizeof (int));
//    b = (int*) calloc(3, sizeof (int));
//    c = (int*) calloc(3, sizeof (int));
//    d = (int*) calloc(3, sizeof (int));
//    Stack<int*> *stack = new Stack<int*>();
//    stack->push(a);
//    stack->push(b);
//    stack->push(c);
//    stack->push(d);
//    cout << stack->peek() << "\n" << stack->size()<< "\n";
//    stack->pop();
//    cout << stack->peek() << "\n" << stack->size();
//    free(stack);

//    LinkedList<int> *ll = new LinkedList<int>();
//    try {
//        ll->add(1);
//        ll->add(2);
//        ll->add(3);
//        ll->add(4);
//        ll->insert(2, 5);
//        ll->insert(0, 6);
//        ll->insert(5, 7);
//        cout << ll->get_first() << "\n";
//        cout << ll->get_last() << "\n";
//        cout << ll->get_at(3) << "\n";
//        cout << ll->get_at(2) << "\n";
//        ll->remove_at(3);
//        ll->reverse();
//        ll->clear();
//        free(ll);
//    }catch (const invalid_argument e){
//        free(ll);
//        cout << e.what();
//        exit(3);
//    }

    func(5, 6);

}
