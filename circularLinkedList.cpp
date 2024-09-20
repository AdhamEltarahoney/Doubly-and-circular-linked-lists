#include <iostream>
using namespace std;

class Node {
public:
    Node() { next = nullptr; }
private:
    int data;
    Node* next;
    friend class CLinkedList;
};

class CLinkedList {
private:
    int numNodes;
    Node* head;
    Node* tail;  // Tail pointer to track the last node
public:
    CLinkedList();
    ~CLinkedList();
    void addBack(int x);
    void addFront(int x);
    int removeFront();
    void print();
    int getSize() { return numNodes; }
    void addAfterIndex(int index, int x);
};

CLinkedList::CLinkedList() {
    head = nullptr;
    tail = nullptr;
    numNodes = 0;
}

CLinkedList::~CLinkedList() {
    while (numNodes > 0) {
        removeFront();  // Remove all nodes to free memory
    }
}

void CLinkedList::addBack(int x) {
    // Step 1: create the node
    Node* newNode = new Node;
    newNode->data = x;

    // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Point to itself to make it circular
    } else {
        tail->next = newNode;
        newNode->next = head;  // Make it circular
        tail = newNode;  // Update tail to the new node
    }
    numNodes++;
}

void CLinkedList::addFront(int x) {
    // Step 1: create the node
    Node* newNode = new Node;
    newNode->data = x;

    // Step 2: Handle empty list case
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Point to itself to make it circular
    } else {
        newNode->next = head;
        tail->next = newNode;  // Update the last node's next to the new head
        head = newNode;  // Update head to the new node
    }
    numNodes++;
}

int CLinkedList::removeFront() {
    if (head == nullptr) {
        cout << "List is already empty" << endl;
        return -1;
    }
    Node* t = head;
    int num = head->data;

    if (head == tail) {
        // Only one node in the list
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;  // Maintain the circular structure
    }
    delete t;
    numNodes--;
    return num;
}

void CLinkedList::print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

void CLinkedList::addAfterIndex(int index, int x) {
    if (index < 0 || index >= numNodes) {
        cout << "Index out of bounds" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    if (curr == tail) {
        tail = newNode;  // Update tail if we're adding after the last element
    }
    numNodes++;
}

int main() {
    CLinkedList list;
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
