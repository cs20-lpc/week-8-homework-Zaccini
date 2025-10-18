//UNFINISED: Rotate function and adapting each function to use top instaed of head and last. 
//I just wrote every function using head and last like a normal linked lsit, but based on the hpp file it
//seems like that wasn't the intended purpose

template <typename T>
LinkedListStack<T>::LinkedListStack(){
    this->length = 0;
    head = nullptr;
    last = nullptr;
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
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    head = nullptr;
    last = nullptr;
    this->length = 0;

    Node* current = copyObj.head;
    while (current != nullptr) {
        Node* newNode = new Node(current->value);
        if (head == nullptr) {
            head = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
        ++this->length;
        current = current->next;
    }   
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

    return last->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (isEmpty()) {
        throw string("pop: error, stack is empty, avoiding underflow");
    }
    if (head == last){
        delete head;
        head =nullptr;
        last = nullptr;
    } else {
        Node* current = head;
        while (current->next != last){
            current = current->next
        }
        delete last;
        last = current;
        last->next = nullptr;
    }
    --this->length;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    if (isFull()) {
        throw string("push: error, stack is full, avoiding overflow");
    }
    Node* newNode = new Node(elem);
    if (head == nullptr) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    ++this->length;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {

    // TO DO: Implement rotate
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
