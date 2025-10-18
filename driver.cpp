#include <iostream>
#include "StackFactory.hpp"
using namespace std;

int main() {
    cout << "=== Testing with int ===\n";
    Stack<int>* listStack = StackFactory<int>::GetStack();     // LinkedListStack
    Stack<int>* arrayStack = StackFactory<int>::GetStack(3);   // ArrayStack

    // Test push
    listStack->push(10);
    listStack->push(20);
    arrayStack->push(10);
    arrayStack->push(20);

    // Test peek
    cout << "LinkedListStack top: " << listStack->peek() << endl;
    cout << "ArrayStack top: " << arrayStack->peek() << endl;

    // Test pop
    listStack->pop();
    arrayStack->pop();
    cout << "After pop, LinkedListStack top: " << listStack->peek() << endl;
    cout << "After pop, ArrayStack top: " << arrayStack->peek() << endl;

    // Test empty behavior
    listStack->pop();
    arrayStack->pop();
    cout << "Empty? (list): " << listStack->isEmpty() << "  (array): " << arrayStack->isEmpty() << endl;

    // Test exception (optional)
    try { listStack->pop(); } 
    catch (const string& msg) { cout << "Caught: " << msg << endl; }

    delete listStack;
    delete arrayStack;
}