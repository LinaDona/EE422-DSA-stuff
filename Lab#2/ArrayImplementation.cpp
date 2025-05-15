#include <iostream>
#include <cctype>
using namespace std;

const int maxSize= 1000;

typedef struct{
    string array[maxSize];
    unsigned size;
} list;

void insert(list &l, string name, int p){
    if(l.size == maxSize){
        cout << "List is full. No other name can be stored." << endl;
    }
    else{
        if(p < 0 || p > maxSize){
            cout << "There is no such position." << endl;
        }
        else {
            for(int i = l.size - 1; i >= p; i--){
                l.array[i+1] = l.array[i];
            }
            l.array[p] = name;
            l.size++;
        }
    }
} 

void remove(list &l, int p){
    if(l.size == 0){
        cout << "list is empty." << endl;
    }
    else {
        if(p > l.size){
            cout << "There is no such position." << endl;
        }
        else {
            cout << "The name " << l.array[p] << " at position " << p << " is removed" << endl;
            for(int i = p; i < l.size-1; i++){
                l.array[i] = l.array[i+1];
            }
            l.size--;
        }
    }
}

void search(list &l, string name){
    for(int i=0; i<l.size; i++){
        if(l.array[i].compare(name) == 0){
            cout << name << " is found at location " << i << endl;
            break;
        }
    }
}

void forward_traverse(list l){
    for(int i=0; i<l.size; i++){
        cout << l.array[i] << "  ";
    }
    cout << endl;
}

void backward_traverse(list l){
    for(int i=l.size; i>0; i--){
        cout << l.array[i-1] << "  ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    list l;
    char option;
    cout << "FIND BELOW THE FOLLOWING OPTIONS: " << endl;
    cout << "i : To insert a new name at a given position." << endl;
    cout << "d: To delete a name at a given position." << endl;
    cout << "s: To search for a name." << endl;
    cout << "f: To traverse the list forwardly." << endl;
    cout << "b: To traverse the list backwardly." << endl;
    cout << "q: to quit" << endl;

    while(true)
    {
        cout << "Please enter an option: ";
        cin >> option;
        if (toupper(option) == 'Q'){
            break;
        }
        //cout << "\nafter q ";
        else if(toupper(option) == 'I'){
            string name;
            int p;
            cout << "Enter the name you wish to insert: ";
            cin >> name;
            cout << "Enter the position: ";
            cin >> p;
            insert(l, name, p);
        }
        //cout << "\nafter i";
        else if(toupper(option) == 'F'){
            forward_traverse(l);
        }
        //cout << "after f\n";
        else if(toupper(option) == 'B'){
            backward_traverse(l);
        }
        //cout << "after b\n";
        else if(toupper(option) == 'D'){
            int p;
            cout << "Enter the position whose name will be deleted: ";
            cin >> p;
            remove(l, p);
        }
        //cout << "after d\n";
        else if(toupper(option) == 'S'){
            string name;
            cout << "Enter the name you wish to find its first position: ";
            cin >> name;
            search(l, name);
        }
        else {
            cout << "Enter a valid character!" << endl;
        }
    }

    return 0;
}

