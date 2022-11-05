#include<iostream>
using namespace std;
#include "stackTemplate.h"

int main() {
    StackUsingTemplate<int> s1;
    s1.push(12);
    // s1.push(14);
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
    s1.push(15);
    s1.push(25);
    return 0;
}