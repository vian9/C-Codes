// Link : https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1
// Time Complexity : O(n)
// Approach-> Array k index stack m push kro is the idea to access....ab usse index se check krte jao agar bada h to
// last jahan tk jaa skta h array ko update kro and pop krte jao

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<long long> nextLargerElement(vector<long long> &arr, int n)
{
    // 1 3 2 4....3 4 4 -1
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        // st.top() mein index daalo and usse move krwao
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            arr[st.top()] = arr[i];
            st.pop();
        }

        st.push(arr[i]);
    }
    while (!st.empty())
    {
        arr[st.top()] = -1;
        st.pop();
    }
    return arr;
}

int main()
{

    return 0;
}