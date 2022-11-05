// Link : https://leetcode.com/problems/permutation-in-string/
// Time Complexity : O(n)
// Approach-> Sliding window approach.....agar s2 mein woh window milgya jo s1 k char k hai toh count-- krenge
// Aur agar window size matches toh count 0 pr true hoga.
// Sol : https://leetcode.com/problems/permutation-in-string/discuss/1762469/C%2B%2B-oror-SLIDING-WINDOW-OPTIMIZED-oror-Well-Explained
// The alphabets in a permutation that is to be searched will always be the same, and so will their count.
// The thing that counts in s2 is that each substring has the same number of characters as in s1. As a result,
// we make a hashmap that contains the count of each character in the string s1. After that,
// we slide a window over the string s2 and lower the number for characters that appear in the window.
// When all of the counters in the hashmap reach 0, we've found the permutation.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> mp; // Use hashmap to store the frequencies of all the characters present in string s1.
    for (auto it : s1)
    {
        mp[it]++;
    }
    int count = mp.size(); // Use the count variable to see if all of the characters in the map have the same frequency, indicating that an anagram has been found.
    int i = 0, j = 0;
    int k = s1.size(); // Window Size
    while (j < s2.size())
    {
        if (mp.find(s2[j]) != mp.end())
        { // If a character is found that already exists in the map, reduce its frequency by one.
            mp[s2[j]]--;
            if (mp[s2[j]] == 0)
            { // If the frequency of a specific character on the map is 0, it means that all occurrences of that character is found inside the current window size.
                count--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            { // Anagram found
                return true;
            }
            if (mp.find(s2[i]) != mp.end())
            { // Check if that character is present in the map while sliding the window, then increase its frequency by one, as we decreased its frequency when we first met it while crossing the window.
                mp[s2[i]]++;
                if (mp[s2[i]] == 1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return false;
}

// Wrong code
// bool checkInclusion(string s1, string s2)
// {
//     unordered_map<char, int> freq;
//     for (int i = 0; i < s2.length(); i++)
//     {
//         freq.insert({s2[i], i});
//     }
//     // char index freq
//     unordered_map<char, int> val;
//     for (int i = 0; i < s1.length(); i++)
//     {
//         if (freq.count(s1[i]) > 0)
//         {
//             if (val.count(s1[i]) > 0)
//             {
//                 freq[s1[i]] -= 1;
//             }
//             else
//             {
//                 for (auto &j : freq)
//                 {
//                     if (j.first == s1[i])
//                         val.insert({j.first, j.second});
//                 }
//             }
//         }
//         else
//         {
//             return false;
//         }
//     }
//     int last = val[s1[0]];
//     int sec = last - 1;
//     for (int i = 1; i < s1.length(); i++)
//     {
//         for (auto &j : val)
//         {
//             if (j.first == s[i] && abs(j.second - last) == 1)
//             {
//                 last = j.second;
//                 break;
//             }
//             val.erase(j.first);
//         }
//         if (abs(sec - last) != 1)
//             return false;
//         sec = last;
//     }

//     return true;
// }

int main()
{

    return 0;
}