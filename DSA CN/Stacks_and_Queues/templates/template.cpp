#include<iostream>
using namespace std;
#include "template.h"

int main() {
    Pair<int> p1;
    p1.setX(10);
    cout << p1.getX() << endl;
    p1.setY(13);
    cout << p1.getY() << endl;

    Pair<Pair<int, char>, double> p2;
    Pair<int, char> p3;
    p3.setX(10);
    cout << p3.getX() << endl;
    p3.setY('A');
    cout << p3.getY() << endl;
    p2.setY(12.10);
    p2.setX(p3);
    cout << p2.getY() << endl;
    cout << p2.getX().getX() << endl;
    cout << p2.getX().getY() << endl;



    return 0;
}