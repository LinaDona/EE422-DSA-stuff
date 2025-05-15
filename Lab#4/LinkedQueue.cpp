#include "LinkedQueue.h"

LinkedQueue::LinkedQueue(){
    f = r = 0;
    n = 0;
}

LinkedQueue::~LinkedQueue(){
    while(!empty())
        dequeue();
}

bool LinkedQueue::empty() const{
    return(n == 0);
}

int LinkedQueue::size() const{
    return n;
}

void LinkedQueue::enqueue(const Elem& e){
    Node *tmp = new Node;
    tmp->elem = e;
    tmp->next = 0;
    if(empty())
        f = r = tmp;
    else {
        r->next = tmp;
        r = tmp;
    }
    n++;
}

void LinkedQueue::dequeue() throw(QueueEmpty) {
    if(empty())
        throw QueueEmpty("Dequeue an empty queue");
    else {
        Node *tmp = f;
        f = f->next;
        delete tmp;
        if(n == 1) // rear has to be set null
            r = 0;
        n--;
    } 
}

const Elem& LinkedQueue::front() const throw(QueueEmpty) {
    if(empty())
        throw QueueEmpty("front of an empty queue");
    else {
        return f->elem;
    }
}

void LinkedQueue::print() const {
    if(!empty()){
        Node* tmp = f;
        cout << "[ ";
        while(tmp != 0){
            cout << tmp->elem << " ";
            tmp = tmp->next;
        }
        cout << "]" << endl;
    }
}