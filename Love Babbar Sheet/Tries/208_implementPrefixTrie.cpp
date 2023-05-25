// Link : https://leetcode.com/problems/implement-trie-prefix-tree/
// Time Complexity : O(n)
// Approach-> Just map m krdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// For class implementation of Trie....harr root k 26 child for each letter
// Ab usse letter se connect krte jao
class Trie
{
public:
    char letter;
    Trie **child;
    Trie(char letter)
    {
        this->letter = letter;
        child = new Trie *[26];
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

void insertTrie(Trie *root, string word)
{
    if (word == "\0")
    {
        return;
    }

    char curr = word[0];
    int index = curr - 'a';
    Trie *child;
    if (root->child[index] != NULL)
    {
        child = root->child[index];
    }
    else
    {
        child = new Trie(curr);
        root->child[index] = child;
    }
    insertTrie(child, word.substr(1));
}

void insert(string word)
{
    if (word == "\0")
    {
        return;
    }
    Trie *root;
    insertTrie(root, word);
}

bool search(string word, Trie *root)
{
    if (word.size() == 0)
    {
        return true;
    }
    char curr = word[0];
    int index = curr - 'a';
    Trie *child;
    if (root->child[index] != NULL)
    {
        child = root->child[index];
        return search(word.substr(1), child);
    }
    else
    {
        return false;
    }
}

// For LeetCode bs map se krdo
class Trie
{
    unordered_map<string, int> dict, pre;

public:
    Trie()
    {
    }

    // Map m word and prefic dono insert krdo
    void insert(string word)
    {
        if (word == "\0")
        {
            return;
        }
        dict[word]++;
        string s;
        for (auto it : word)
        {
            s.push_back(it);
            if (pre[s] == 0)
                pre[s]++;
        }
    }

    // Search in map now
    bool search(string word)
    {
        if (dict.count(word) > 0)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if (pre.count(prefix) > 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{

    return 0;
}