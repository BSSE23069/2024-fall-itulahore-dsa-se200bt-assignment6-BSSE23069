#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Test if stack is initially empty", "[isEmpty]") {
    Stack myStack;

    // Check if the stack is empty on initialization
    REQUIRE(myStack.isEmpty() == true);
}

TEST_CASE("Push function test", "[push]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Ensure the stack is not empty
    REQUIRE(myStack.isEmpty() == false);

    // Check the top data
    REQUIRE(myStack.peek() == 30);  // Top should be 30
}

TEST_CASE("Pop function test", "[pop]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Pop the top element
    myStack.pop();
    REQUIRE(myStack.peek() == 20);  // Top should now be 20
    REQUIRE(myStack.size() == 2);   // Size should be 2

    // Pop the next element
    myStack.pop();
    REQUIRE(myStack.peek() == 10);  // Top should now be 10
    REQUIRE(myStack.size() == 1);   // Size should be 1

    // Pop the last element
    myStack.pop();
    REQUIRE(myStack.isEmpty() == true);  // Stack should now be empty
}

TEST_CASE("Peek function test", "[peek]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);

    // Peek at the top element
    REQUIRE(myStack.peek() == 10);

    // Push another element
    myStack.push(20);
    REQUIRE(myStack.peek() == 20);  // Top should now be 20

    // Pop the top element
    myStack.pop();
    REQUIRE(myStack.peek() == 10);  // Top should now be 10
}

TEST_CASE("Size function test", "[size]") {
    Stack myStack;

    // Initially size should be 0
    REQUIRE(myStack.size() == 0);

    // Push elements onto the stack
    myStack.push(10);
    REQUIRE(myStack.size() == 1);

    myStack.push(20);
    REQUIRE(myStack.size() == 2);

    myStack.push(30);
    REQUIRE(myStack.size() == 3);

    // Pop an element
    myStack.pop();
    REQUIRE(myStack.size() == 2);

    // Clear the stack
    myStack.clear();
    REQUIRE(myStack.size() == 0);
}

TEST_CASE("Clear function test", "[clear]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Clear the stack
    myStack.clear();

    // Ensure the stack is empty
    REQUIRE(myStack.isEmpty() == true);
    REQUIRE(myStack.size() == 0);
}

TEST_CASE("Pop from empty stack test", "[pop]") {
    Stack myStack;

    // Attempt to pop from an empty stack
    myStack.pop(); // Should handle underflow gracefully

    // Ensure the stack is still empty
    REQUIRE(myStack.isEmpty() == true);
    cout << "Pop Function Done" << endl;
}

TEST_CASE("Peek from empty stack test", "[peek]") {
    Stack myStack;

    // Attempt to peek at an empty stack
    int topValue = myStack.peek();

    // Since peek returns -1 when the stack is empty
    REQUIRE(topValue == -1);
}


// Test Case 1: Empty Queue Check
TEST_CASE("Test Case 1: Empty Queue Check", "[queue]") {
    Queue q;
    REQUIRE(q.isEmpty() == true);
}

// Test Case 2: Enqueue into Empty Queue and Check First and Last Element
TEST_CASE("Test Case 2: Enqueue into Empty Queue and Check First and Last Element", "[queue]") {
    Queue q;
    q.enqueue(10);
    REQUIRE(q.size() == 1);
    REQUIRE(q.getFront() == 10); // Check front element
    REQUIRE(q.getEnd() == 10);   // Check end element
}

// Test Case 3: Enqueue Multiple Elements and Check First and Last Element
TEST_CASE("Test Case 3: Enqueue Multiple Elements and Check First and Last Element", "[queue]") {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    REQUIRE(q.size() == 4);
    REQUIRE(q.getFront() == 10); // Check front element
    REQUIRE(q.getEnd() == 40);   // Check end element
}

// Test Case 4: Dequeue Single Element and Check First and Last Element
TEST_CASE("Test Case 4: Dequeue Single Element and Check First and Last Element", "[queue]") {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    REQUIRE(q.size() == 3);
    REQUIRE(q.getFront() == 20); // Check updated front element
    REQUIRE(q.getEnd() == 40);   // Check end element remains the same
}

// Test Case 5: Dequeue Multiple Elements and Check First and Last Element
TEST_CASE("Test Case 5: Dequeue Multiple Elements and Check First and Last Element", "[queue]") {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    REQUIRE(q.size() == 2);
    REQUIRE(q.getFront() == 30); // Front should now be 30
    REQUIRE(q.getEnd() == 40);   // End should still be 40
}

// Test Case 6: Dequeue from Empty Queue
TEST_CASE("Test Case 6: Dequeue from Empty Queue", "[queue]") {
    Queue q;
    q.enqueue(10);
    q.dequeue();
    REQUIRE(q.isEmpty() == true);
    q.dequeue(); // This should handle gracefully
}

// Test Case 7: Enqueue and Dequeue and Check First and Last Element
TEST_CASE("Test Case 7: Enqueue and Dequeue and Check First and Last Element", "[queue]") {
    Queue q;
    q.enqueue(50);
    q.enqueue(60);
    REQUIRE(q.size() == 2);
    REQUIRE(q.getFront() == 50); // Front should be 50
    REQUIRE(q.getEnd() == 60);   // End should be 60
    q.dequeue();
    REQUIRE(q.size() == 1);
    REQUIRE(q.getFront() == 60); // Front should now be 60
    REQUIRE(q.getEnd() == 60);   // End should also be 60
}

// Test Case 9: Edge Case - Single Element Queue
TEST_CASE("Test Case 9: Edge Case - Single Element Queue", "[queue]") {
    Queue q2;
    q2.enqueue(70);
    REQUIRE(q2.size() == 1);
    REQUIRE(q2.getFront() == 70);
    REQUIRE(q2.getEnd() == 70);
    q2.dequeue();
    REQUIRE(q2.isEmpty() == true);
}