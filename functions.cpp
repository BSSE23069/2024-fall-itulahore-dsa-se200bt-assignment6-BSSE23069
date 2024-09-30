using namespace std;
#include <iostream>
#include "functions.h"
Node::Node() {
    data = 0;
    next = nullptr;
}

Node::Node(int d) {
    data = d;
    next = nullptr;
}

void Node::setNext(Node* val) {
    next = val;
}

Node* Node::getNext() {
    return next;
}

void Node::setData(int d) {
    data = d;
}

int Node::getData() {
    return data;
}

// Stack class
Stack::Stack() {
    top = nullptr;
    count = 0;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(int data) {
    Node* n = new Node(data);
    n->setNext(top);  // Push the new node to the top
    top = n;
    count++;
}

void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->getNext();
        delete temp;  // Free the memory of the removed node
        count--;
    }
}

int Stack::size() {
    return count;  // Return the size of the stack
}

int Stack::peek() {
    if (!isEmpty()) {
        return top->getData();  // Return the top element
    }
    return -1;  // Return -1 if the stack is empty
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();  // Pop all elements
    }
}

void Stack::printStack() {
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}

// Queue class
Queue::Queue() {
    top = nullptr;
    count = 0;
}

Queue::~Queue() {
    clear();  // Clear the queue when destroyed
}

bool Queue::isEmpty() {
    return top == nullptr;
}

void Queue::enqueue(int data) {
    Node* n = new Node(data);
    if (isEmpty()) {
        top = n;  // Set the first element
    } else {
        Node* temp = top;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();  // Traverse to the end
        }
        temp->setNext(n);  // Append the new node
    }
    count++;
}

void Queue::dequeue() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->getNext();
        delete temp;  // Free the memory of the removed node
        count--;
    }
}

int Queue::size() {
    return count;  // Return the size of the queue
}

void Queue::printQueue() {
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << "Value: " << temp->getData() << std::endl;
        temp = temp->getNext();
    }
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();  // Dequeue all elements
    }
}
