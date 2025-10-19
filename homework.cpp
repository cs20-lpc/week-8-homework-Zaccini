#include <iostream>
#include "StackFactory.hpp"

int main()
{
    Stack<int> * mystack = StackFactory<int>::GetStack();
    mystack->push(1);
    mystack->push(2);
    mystack->push(3);
    mystack->push(4);
    mystack->push(5);
    mystack->pop();
    mystack->pop();
    mystack->pop();
    mystack->push(6);
    mystack->push(7);
    cout << mystack->getLength() << endl;
    Stack<int> * copiedStack = StackFactory<int>::GetStack();
    copiedStack = copy(mystack);
    cout << copiedStack->getLength() << endl;;
    cout << copiedStack->print() << endl;
    cout << mystack->print() << endl;


    Stack<int> * shouldCreateArraystack = StackFactory<int>::GetStack(5);
    shouldCreateArraystack->push(1);
    shouldCreateArraystack->push(2);
    shouldCreateArraystack->push(3);
    shouldCreateArraystack->push(4);
    shouldCreateArraystack->push(5);
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->push(6);
    shouldCreateArraystack->push(7);
    cout << " " << shouldCreateArraystack->getLength();


}