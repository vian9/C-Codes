#include<iostream>
using namespace std;
#include "stackArrays.h"

int main() {
    StackUsingArray s1;
    s1.push(12);
    // s1.push(14);
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
    return 0;
}