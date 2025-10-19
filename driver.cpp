#include <iostream>
#include "StackFactory.hpp"
using namespace std;

int main() {
    Stack<int>* listStack = StackFactory<int>::GetStack();     // LinkedListStack
    Stack<int>* arrayStack = StackFactory<int>::GetStack(3);   // ArrayStack


    listStack->push(10);
    listStack->push(20);
    listStack->push(30);
    arrayStack->push(10);
    arrayStack->push(20);
    arrayStack->push(30);

    cout << "LinkedListStack top: " << listStack->peek() << endl;
    cout << "ArrayStack top: " << arrayStack->peek() << endl;

    listStack->rotate(Stack<int>::LEFT);
    arrayStack->rotate(Stack<int>::RIGHT);
    cout << "After rotate left, LinkedLiarrayStacstStack top: " << listStack->peek() << endl;
    cout << "After rotate right, ArrayStack top: " << arrayStack->peek() << endl;

    listStack->pop();
    arrayStack->pop();
    cout << "After pop, LinkedListStack top: " << listStack->peek() << endl;
    cout << "After pop, ArrayStack top: " << arrayStack->peek() << endl;

    listStack->clear();
    arrayStack->clear();

    try { listStack->pop(); } 
    catch (const string& msg) { cout << "Cleared linkedList: " << msg << endl; }

    try { listStack->pop(); } 
    catch (const string& msg) { cout << "Cleared ArrayStack: " << msg << endl; }

}