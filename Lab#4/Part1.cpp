#include "LinkedQueue.h"

int main(int argc, char const *argv[])
{
    LinkedQueue queue;
    char option;
    cout << "FIND BELOW THE FOLLOWING OPTIONS: " << endl;
    cout << "m: To check if the queue is empty." << endl;
    cout << "d: To dequeue." << endl;
    cout << "e: To enqueue an element." << endl;
    cout << "p: To print the queue." << endl;
    cout << "f: To get the front of the queue." << endl;
    cout << "s: To get the size of the queue." << endl;
    cout << "q: to quit" << endl;
    while(true)
    {
        cout << "Please enter an option: ";
        cin >> option;
        if (toupper(option) == 'Q'){
            break;
        }

        else if(toupper(option) == 'M'){
            if(queue.empty())
                cout << "Queue is empty." << endl;
            else 
                cout << "Queue is not empty." << endl;
        }
        
        else if(toupper(option) == 'F'){
            try
            {
                cout << "Front: " << queue.front() << endl;
            }
            catch(const RuntimeException& e)
            {
                cout << e.getMessage() << endl;
            }  
            
        }
        
        else if(toupper(option) == 'S'){
            cout << "Size: " << queue.size() << endl;
        }
        else if(toupper(option) == 'P'){
            queue.print();
        }
        else if(toupper(option) == 'E'){
            int element;
            cout << "Enter the element: ";
            cin >> element;
            queue.enqueue(element);
        }
        else if(toupper(option) == 'D'){
            try
            {
                queue.dequeue();
            }
            catch(const RuntimeException& e)
            {
                cout << e.getMessage() << endl;
            }  
        }
        else {
            cout << "Enter a valid character!" << endl;
        }
    }
    return 0;
}
