#include <iostream>
using namespace std;

bool isOneBitCharacter(vector<int> &bits)
{
    bool flag = true;
    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] == 0)
        {
            flag = true;
            continue;
        }
        else if (bits[i] == 1 && i != (bits.size() - 1))
        {
            if (bits[i + 1] == 1 && (i + 1) == (bits.size() - 1))
            {
                flag = false;
                break;
            }
            else if (bits[i + 1] == 0 && ((i + 1) == (bits.size() - 1)))
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
                i += 1;
                continue;
            }
        }
    }
    return flag;
}

int main()
{

    return 0;
}