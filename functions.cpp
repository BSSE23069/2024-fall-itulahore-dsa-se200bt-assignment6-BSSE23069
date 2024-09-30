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
// push is stack
void Stack::push(int data)
 {
    Node* n = new Node(data);
    n->setNext(top);  
    top = n;
    count++;
}

void Stack::pop() {
    if (!isEmpty()) {
        top = top->getNext();
        count--;
    }
}
// size of stack
int Stack::size() {
    return count; 
}

int Stack::peek() 
{
    if (!isEmpty())
     {
        return top->getData();  
    }
    return -1;  
}

void Stack::clear()
 {
    while (!isEmpty()) {
        pop();  
    }
}

void Stack::printStack() {
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
}

// Queue class
Queue::Queue() {
    top = nullptr;
    count = 0;
}

Queue::~Queue() {
    delete[] top;
}

bool Queue::isEmpty() {
    return top == nullptr;
}

void Queue::enqueue(int data) {
    Node* n = new Node(data);
    if (isEmpty()) {
        top = n;  
    } else 
    {
        Node* temp = top;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();  
        }
        temp->setNext(n);  
    }
    count++;
}

void Queue::dequeue() {
    if (!isEmpty()) {
        top = top->getNext(); 
        count--;
    }
}

int Queue::size() {
    return count; 
}

void Queue::printQueue() {
    Node* temp = top;
    while (temp != nullptr) {
        cout << "Value: " << temp->getData() << endl;
        temp = temp->getNext();
    }
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();  
    }
}

int Queue::getFront()
{
    return top->getData();
}

int Queue::getEnd()
{
  Node * tem=top;
  while (tem->getNext())
  {
    tem=tem->getNext();
  }
  return tem->getData();
}
