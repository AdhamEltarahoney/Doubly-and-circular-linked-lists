//Doubly linked lists
#include <iostream>
#include <string>
using namespace std;


class Node{
public:
    Node(){prev = nullptr; next = nullptr;}
private:
    Node *prev;
    int data;
    Node *next;
    friend class DLinkedList;
};

class DLinkedList{
private:
    int numNodes;
    Node *head;
public:
    DLinkedList();
    ~DLinkedList();
    void addBack(int x);
    void addFront(int x);
    int removeFront();
    void print();
    int getSize(){ return numNodes;}
    void addAfterIndex(int index, int x);
};
DLinkedList :: DLinkedList(){
    head = nullptr;
    numNodes = 0;
}
DLinkedList :: ~DLinkedList() {
    while (head != nullptr) {
        removeFront();  // Remove all nodes to free memory
    }
}

void DLinkedList :: addBack(int x){
    // step 1: create the node
    Node *newNode = new Node;
    newNode -> data = x;
     // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
    }
    else{
        Node *curr = head;
        //now its time to insert
        for (int i = 0; curr->next!= nullptr; i++){
            curr = curr->next;
        }
        //now insert and link
        newNode -> prev = curr;
        curr -> next = newNode;
    }
        numNodes ++;
}

void DLinkedList :: addFront(int x) {
    // Step 1: create the node
    Node *newNode = new Node;
    newNode->data = x;

    // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    numNodes++;
}

int DLinkedList :: removeFront(){
    if (head == nullptr){
        cout<<"List is already empty"<<endl;
        return -1;
    }
    Node *t = head;
    int num=head->data;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete t;
    return num;
}

void DLinkedList :: print(){
    Node *curr = head;
    while (curr!= nullptr){
        cout<<curr->data<<" ";
        curr = curr ->next;
    }
    cout<<endl;
}

void DLinkedList :: addAfterIndex(int index, int x){
    Node *t = new Node;
    t->data = x;

    Node *before = head;
    for (int i = 0; i < index; i++){
        before = before->next;
    }
    Node *after = before ->next;
    t->prev=before;
    t->next=after;
    before->next = t;
    after->prev = t;
    numNodes ++;
}


int main(){

    DLinkedList list;
    list.addFront(3);
    list.addBack(4);
    list.addBack(5);
    list.addBack(7);
    list.addBack(12);
    list.addBack(15);
    list.addBack(19);
    list.addAfterIndex(4,4);
    list.print();
    return 0;
}


