#include "LinkedQueue.h"

void enqueue_ordered(LinkedQueue &Q, int e){
    int s = Q.size();
    int tmp;
    bool placed = false;
    for(int i=0; i<s; i++) {
        tmp = Q.front();
        if(!placed && e < tmp){
            placed = true;
            Q.dequeue();
            Q.enqueue(e);
            Q.enqueue(tmp);
        }
        else {
            Q.dequeue();
            Q.enqueue(tmp);
        }     
    }
}

int main(int argc, char const *argv[])
{
    LinkedQueue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.print();
    enqueue_ordered(Q, 4);
    Q.print();

    return 0;
}
