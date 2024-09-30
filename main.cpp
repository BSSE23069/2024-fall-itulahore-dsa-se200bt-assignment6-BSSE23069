#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    Stack s;
    Queue q;
    int c = 0;

    while (true) {
        cout << "Enter 1 for enqueue, 2 for dequeue, 3 to push to stack, 4 to pop from stack, 5 to print stack, 6 to print queue, 7 to exit: " << endl;
        cin >> c;

        if (c == 1) {
            int d;
            cout << "Enter digit to enqueue: " << endl;
            cin >> d;
            q.enqueue(d);
        }
        else if (c == 2) {
            q.dequeue();
        }
        else if (c == 3) {
            int d;
            cout << "Enter digit to push to stack: " << endl;
            cin >> d;
            s.push(d);
        }
        else if (c == 4) {
            s.pop();
        }
        else if (c == 5) {
            cout << "Stack contents: ";
            s.printStack();
        }
        else if (c == 6) {
            cout << "Queue contents: ";
            q.printQueue();
        }
        else if (c == 7) {
            cout << "Exiting program." << endl;
            break; // Exit the loop
        }
        else {
            cout << "Invalid option, please try again." << endl;
        }
    }
    return 0;
}
