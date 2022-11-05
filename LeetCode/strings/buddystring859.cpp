#include <iostream>
using namespace std;

bool buddyStrings(string s, string goal)
{
    // vector<int> check;
    //   for(int i=0; i<27; i++){
    //       check.push_back(0);
    //   }
    //   for(int i= 0; i<goal.length(); i++){
    //       int num = ((int)goal[i] - 97);
    //           int k = check[num] + 1;
    //           check[num] = k;
    //   }
    //   for(int i= 0; i<s.length(); i++){
    //       int num = ((int)s[i] - 97);
    //           int k = check[num] - 1;
    //           check[num] = k;
    //   }
    //   bool flag = true;
    //   for(int i= 0; i<check.size(); i++){
    //           if(check[i] != 0){
    //               flag = false;
    //               break;
    //           }
    //   }

    bool flag = true;
    int m = s.length();
    int n = goal.length();
    if (m != n)
    {
        flag = false;
        return flag;
    }
    int count = 0;
    int k[2], j = 0;
    k[0] = 0;
    k[1] = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != goal[i])
        {
            if (j < 2)
            {
                k[j] = i;
                count++;
                j++;
                cout << i << endl;
            }
            else
            {
                flag = false;
                return false;
            }
        }
    }

    if (count > 2)
    {
        return false;
    }

    if (count == 0 && s[1] == s[0])
    {
        flag = true;
        return flag;
    }
    else if (count == 0 && s[1] != s[0])
    {
        flag = false;
        return false;
    }

    if (s[k[0]] == goal[k[1]] && s[k[1]] == goal[k[0]])
    {
        cout << "a" << endl;
        flag = true;
    }
    else
    {
        flag = false;
    }

    return flag;
}

int main()
{

    return 0;
}