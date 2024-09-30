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
    Node(int d);
    void setNext(Node * val );
    Node* getNext();
    void setData(int val);
    int getData();
};
class  Stack{
     Node* top;
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
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int data);
    void dequeue();
    int size();
    void printQueue();
    void clear();
  int   getFront();
int getEnd();


};



#endif