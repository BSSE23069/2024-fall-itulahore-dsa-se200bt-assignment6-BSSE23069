#ifndef FUNCTIONS_H
#define FUNCTIONS_H
using namespace std;
class Node
{
private:
    int data;
    Node* next;
public:
    Node();
};
class  Stack{
     Node* top;
     Node* head;
  int count;
public:
    Stack();
    ~Stack(){
        delete[] top;
    }
    bool isEmpty();
    void push(int data);
    void pop();
    int size();
    int peek();
    void clear();
    void printStack();
    int * getStack();

};
class Queue{
  Node* top;
  int count;
  Node* head;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int data);
    void dequeue();
    int size();
    void printQueue();
    int *getQueue();


};



#endif