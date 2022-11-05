#include<climits>

class StackUsingArray {
    int* data;
    int nextIndex;
    int capacity = 2;

public:
    // StackUsingArray(int totalSize) {
    StackUsingArray() {
        data = new int[2];
        // capacity = totalSize;
        nextIndex = 0;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    //we have to keep a fixed size which we don't want
    // void push(int element) {
    //     if (nextIndex == capacity)
    //     {
    //         cout << "Stack is full" << endl;
    //         return;
    //     }

    //     data[nextIndex] = element;
    //     nextIndex++;
    // }

    void push(int element) {
        if (nextIndex == capacity)
        {
            int* newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            //data se related pointer ko delete krdia
            delete[] data;
            data = newData; // ab usse new data k address par point krwa dia
            capacity *= capacity;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop() {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            //return type is int so int_min return krwa rhe
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};