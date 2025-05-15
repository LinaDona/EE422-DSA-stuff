#include "LinkedQueue.h"

int queue_sum(LinkedQueue &Q){
    int s = Q.size(), sum = 0, tmp;
    for(int i=0; i<s; i++) {
        tmp = Q.front();
        sum += tmp;
        Q.dequeue();
        Q.enqueue(tmp);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    LinkedQueue Q;
    Q.enqueue(3); Q.enqueue(5); Q.enqueue(3); Q.enqueue(7);
    Q.print();
    cout << queue_sum(Q) << endl;
    Q.print();  
    return 0;
}
