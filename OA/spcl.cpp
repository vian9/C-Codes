#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

std::vector<int> sieveOfEratosthenes(int n)
{
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int findFirstPrimeSum(const std::vector<int> &nums)
{
    int maxNum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxNum = max(maxNum, nums[i]);
    }

    std::vector<int> primes = sieveOfEratosthenes(maxNum * 2);

    std::unordered_set<int> numSet(nums.begin(), nums.end());

    for (int num : nums)
    {
        for (int prime : primes)
        {
            int complement = prime - num;
            if (complement > 0 && numSet.find(complement) != numSet.end())
            {
                return num;
            }
        }
    }

    return -1; // No such prime found
}

int main()
{
    std::vector<int> nums = {2, 3, 5, 8, 11, 13};
    int result = findFirstPrimeSum(nums);

    if (result != -1)
    {
        std::cout << "First prime number that can be represented as the sum of two numbers: " << result << "\n";
    }
    else
    {
        std::cout << "No such prime sum found.\n";
    }

    return 0;
}