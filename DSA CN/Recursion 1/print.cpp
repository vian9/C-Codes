#include <iostream>
using namespace std;

void print(int n){
    if(n < 0){
        cout<<n;
        return;
    }
    if(n == 0){
        cout<<n<<" ";
        return;
    }

    //Will give segmentation error as the loop will run infinite as due to n-- the value going to recursion is always 3 so the loop never ends
    cout<<n<<endl;
    print(n--);
    cout<<n<<" ";
}

int main() {
    int num = 3;
    print(num);
}