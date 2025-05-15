#include <iostream>
using namespace std;

typedef struct node{
    node *link;
    string name;
} node;

void forward_traverse(node **head){
    node *current = *head;
    while(current != NULL){
        cout << current->name << "  ";
        current = current->link;
    }
    cout << endl;
}

void insert(node** head, node** tail, string name, int position){
    if(*head == NULL && *tail == NULL){
        (*head) = new node;
        (*head)->link = NULL;
        (*head)->name = name;
        *tail = NULL;
    }
    else if(*head != NULL && *tail == NULL){
        node *p = new node;
        p->name = name;
        p->link = NULL;
        *tail = p;
        (*head)->link = p;
    }
    else {
        if(position == 0){
            node* newnode = NULL;
            newnode = new node;
            newnode->name = name;
            newnode->link = (*head);
            (*head) = newnode;
        }
        else {
            node *p = *head, *newnode = NULL;
            for (int i = 0; i < position - 1; i++)
            {
                if (p->link != NULL)
                {
                    p = p->link;
                }
                else
                {
                    cout << "There is no such position." << endl;
                    break;
                }
            }
            newnode = new node;
            newnode->name = name;
            newnode->link = p->link;
            p->link = newnode;
        }
        
    }
    
}

void remove(node** head, node** tail, int position){
    if(*head == NULL && *tail == NULL){
        cout << "List is empty." << endl;
    }
    else {
        if(position == 0){
            node *p = *head;
            *head = (*head)->link;
            delete p;
        }
        else {
            node *p = *head, *q = NULL;
            for (int i = 0; i < position - 1; i++)
            {
                if (p->link != NULL)
                {
                    p = p->link;
                }
                else
                {
                    cout << "There is no such position." << endl;
                    break;
                }
            }
            q = p->link;
            p->link = q->link;
            delete q;
        }
    }
}

void search(node** head, node** tail, string name){
    if(*head == NULL && *tail == NULL){
        cout << "List is empty." << endl;
    }
    else {
        node *current = *head;
        bool found = false;
        int position = 0;
        while(current != NULL && !found){
            if((current->name).compare(name) == 0){
                cout << "The name " << name << " is found at position " << position << endl;
                found = true;
            }
            else {
                current = current->link;
                position++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    node *head = NULL, *tail = NULL; 
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

        else if(toupper(option) == 'I'){
            string name;
            int p;
            cout << "Enter the name you wish to insert: ";
            cin >> name;
            cout << "Enter the position: ";
            cin >> p;
            insert(&head, &tail, name, p);
        }
        //cout << "\nafter i";
        else if(toupper(option) == 'F'){
            forward_traverse(&head);
        }
        
        else if(toupper(option) == 'D'){
            int p;
            cout << "Enter the position whose name will be deleted: ";
            cin >> p;
            remove(&head, &tail, p);
        }
        //cout << "after d\n";
        else if(toupper(option) == 'S'){
            string name;
            cout << "Enter the name you wish to find its first position: ";
            cin >> name;
            search(&head, &tail, name);
        }
        else {
            cout << "Enter a valid character!" << endl;
        }
    }
    
    return 0;
}
