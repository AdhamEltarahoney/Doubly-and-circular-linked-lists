#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node() { next = nullptr; }
private:
    int data;
    Node* next;
    friend class SLinkedList;
};

class SLinkedList {
private:
    int numNodes;
    Node* head;
public:
    SLinkedList();
    ~SLinkedList();
    void addBack(int x);
    void addFront(int x);
    int removeFront();
    void print();
    int getSize() { return numNodes; }
    void addAfterIndex(int index, int x);
};

SLinkedList::SLinkedList() {
    head = nullptr;
    numNodes = 0;
}

SLinkedList::~SLinkedList() {
    while (head != nullptr) {
        removeFront();  // Remove all nodes to free memory
    }
}

void SLinkedList::addBack(int x) {
    // Step 1: create the node
    Node* newNode = new Node;
    newNode->data = x;
    
    // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        // Traverse to the end of the list
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    numNodes++;
}

void SLinkedList::addFront(int x) {
    // Step 1: create the node
    Node* newNode = new Node;
    newNode->data = x;

    // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    numNodes++;
}

int SLinkedList::removeFront() {
    if (head == nullptr) {
        cout << "List is already empty" << endl;
        return -1;
    }
    Node* t = head;
    int num = head->data;
    head = head->next;
    delete t;
    numNodes--;
    return num;
}

void SLinkedList::print() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void SLinkedList::addAfterIndex(int index, int x) {
    Node* newNode = new Node;
    newNode->data = x;

    Node* curr = head;
    for (int i = 0; i < index && curr != nullptr; i++) {
        curr = curr->next;
    }
    
    if (curr == nullptr) {
        cout << "Index out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    numNodes++;
}

int main() {
    SLinkedList list;
    list.addFront(3);
    list.addBack(4);
    list.addBack(5);
    list.addBack(7);
    list.addBack(12);
    list.addBack(15);
    list.addBack(19);
    list.addAfterIndex(4, 4);
    list.print();
    return 0;
}
