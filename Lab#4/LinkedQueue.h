#include <iostream>
using namespace std;

class RuntimeException{
public:
    RuntimeException(const string& err){
        errMsg = err;
    }
    string getMessage() const { return errMsg; }
private:
    string errMsg;
}; 

class QueueEmpty : public RuntimeException {
public:
    QueueEmpty(const string& err) : RuntimeException(err){} 
};

typedef int Elem;
struct Node{
    Elem elem;
    Node *next;
};

class LinkedQueue{
public:
    LinkedQueue();
    ~LinkedQueue();
    void enqueue(const Elem& e);
    bool empty() const;
    int size() const;
    const Elem& front() const throw(QueueEmpty);
    void dequeue() throw(QueueEmpty);
    void print() const;
private:
    Node *f, *r;
    int n;
};