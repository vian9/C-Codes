#// Link : 
// Time Complexity : O()
// Approach-> 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int recurse(int a) {
    //PMI
    // Base condition
    if (a <= 1) {
        return 1;
    }
    //PMI 
    return  a * recurse(a - 1);
}

int main() {
    int a = 4;
    printf("%d", recurse(a));
    printf("\n");
    printf("%d", a);
    // // var declare
    // int a = 10;
    // int c = 11;
    // // b pointer --- a ka addr
    // int* b = &a;
    // printf("%u", b);
    // printf("\n");
    // printf("%u", b + 1);
    // printf("\n");
    // // dereference - gives val at addr
    // printf("%d", *b);
    // printf("\n");
    // // addr of b
    // printf("%u", &b);
    // //
    // b = &c;
    // printf("\n");
    // printf("%u", b);
    // printf("\n");
    // printf("%u", &a);
    // printf("\n");
    // printf("%u", &c);
    // printf("\n");
    // printf("%u", *(b)+1);
    // printf("\n");
    // printf("%u", *(b + 1));
    // // pointer for b
    // int** d = &b;
    // printf("\n");
    // printf("%u", d);
    return 0;
}