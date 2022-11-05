#include<iostream>
using namespace std;
template<typename T>

class StackUsingLL {
    T* data;
    int nextIndex;
    int capacity;

public:
    // StackUsingArray(int totalSize) {
    StackUsingLL() {
        data = new T[2];
        // capacity = totalSize;
        capacity = 2;
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

    void push(T element) {
        if (nextIndex == capacity)
        {
            T* newData = new T[2 * capacity];
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

    T pop() {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            //return type is int so int_min return krwa rhe
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};