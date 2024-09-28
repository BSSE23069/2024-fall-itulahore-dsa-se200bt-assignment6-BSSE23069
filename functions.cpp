using namespace std;
#include "functions.h"
Node::Node()
{
    data=0;
    next=nullptr;
}

// stack work
Stack::Stack(){
    top=nullptr;
head=nullptr;
}
 bool Stack:: isEmpty(){
    bool ch=false;
    if (head==nullptr)
    {
         ch=true;
         return ch;
    }
    else
    {ch=false;
     return ch;
 }
 }
    void Stack:: push(int data){

    }
    void Stack:: pop(){

    }
    int Stack:: size(){

    }
    int Stack::peek(){

    }
    void Stack::clear(){

    }
    void Stack::printStack(){

    }
    int * Stack::getStack(){

    }
    // queue work
  Queue::   Queue(){
top=nullptr;
head=nullptr;
  }
   Queue:: ~Queue(){

   }
    bool Queue:: isEmpty(){
   bool ch=false;
    if (head==nullptr)
    {
         ch=true;
         return ch;
    }
    else
    {ch=false;
     return ch;
 }
    }
    void Queue:: enqueue(int data){

    }
    void Queue:: dequeue(){

    }
    int Queue:: size(){

    }
    void Queue:: printQueue(){

    }
    int* Queue::getQueue(){

    }