#include <climits>

template <typename T>

class StackUsingArray {
    T* data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArray() {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    //return the number of elements in stack
    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        /*
        if(nextIndex == 0) {
            return true;
        }
        else {
            return false;
        }
        */
       return nextIndex == 0;
    }

    //insert element
    void push(T element) {
        if(nextIndex == capacity) {
            T* newData = new T[2 * capacity];
            for(int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
     
    //delete element
    T pop() {
        if(isEmpty()) {
            cout << "Stack is empty !!" << endl;
            return 0; // Not INT_MIN
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if(isEmpty()) {
            cout << "Stack is empty !!" << endl;
            return 0; // Not INT_MIN
        }
        return data[nextIndex - 1];
    }
};