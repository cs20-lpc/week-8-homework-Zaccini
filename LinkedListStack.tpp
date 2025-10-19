//UNFINISED: Rotate function and adapting each function to use top instaed of head and last. 
//I just wrote every function using head and last like a normal linked lsit, but based on the hpp file it
//seems like that wasn't the intended purpose

template <typename T>
LinkedListStack<T>::LinkedListStack(){
    this->length = 0;
    top = nullptr;
}


template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    Node<T>* current = top;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    clear();  // remove existing data

    if (copyObj.top == nullptr) {
        top = nullptr;
        this->length = 0;
        return;
    }

    Stack<T>* temp = new LinkedListStack<T>();
    Node<T>* curr = copyObj.top;

    while (curr != nullptr) {
        temp->push(curr->data);
        curr = curr->next;
    }

    while (!temp->isEmpty()) {
        this->push(temp->peek());
        temp->pop();
    }

    delete temp;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
        if (isEmpty()) {
        throw string("peek: error, stack is empty, cannot access the top");
    }
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (isEmpty()) {
        throw string("pop: error, stack is empty, avoiding underflow");
    }
    if (top->next == nullptr){
        delete top;
        top = nullptr;    
    } else {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T>* newNode = new Node<T>(elem);
    if (this->length > 0){
        newNode->next = top;
    }
    top = newNode;
    ++this->length;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) return;

    if (dir == Stack<T>::LEFT) {
        Node<T>* prev = nullptr;
        Node<T>* curr = top;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        curr->next = top;
        top = curr;
    } else if (dir == Stack<T>::RIGHT) {
        Node<T>* oldTop = top;
        top = top->next;
        oldTop->next = nullptr;

        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = oldTop;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}