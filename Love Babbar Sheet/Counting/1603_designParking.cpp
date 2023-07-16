// Link : https://leetcode.com/problems/design-parking-system/
// Time Complexity : O()
// Approach-> Just maintain 2 global arrays of count and limit and usme this se value update kro

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class ParkingSystem
{
    // Limit and count k vector
    vector<int> limit;
    vector<int> count;

public:
    ParkingSystem(int big, int medium, int small)
    {
        // values daal dia
        this->limit = {big, medium, small};
        this->count = {0, 0, 0};
    }

    bool addCar(int carType)
    {
        // count limit se chota h to add krte jao
        if (this->count[carType - 1] < this->limit[carType - 1])
        {
            this->count[carType - 1]++;
            return true;
        }

        // Else, return False
        return false;
    }
};

int main()
{

    return 0;
}