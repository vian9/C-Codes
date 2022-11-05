#include <iostream>
#include <unordered_map>
using namespace std;

struct Contributor
{
    string name;
    unordered_map<string, int> skills;
};

struct Project
{
    string name;
    int score, best_before, days;
    unordered_map<string, int> skills_required;
};

int main()
{
    int n, p;
    cin >> n >> p;

    struct Contributor contributors[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        int s;
        cin >> name >> s;
        contributors[i].name = name;

        string skill;
        int lvl;
        for (int x = 0; x < s; x++)
        {
            cin >> skill >> lvl;
            contributors[i].skills[skill] = lvl;
        }
    }

    struct Project projects[p];
    for (int i = 0; i < p; i++)
    {
        int s;
        string skill;
        int lvl;
        cin >> projects[i].name >> projects[i].score >> projects[i].best_before >> projects[i].days >> s;
        for (int x = 0; x < s; x++)
        {
            cin >> skill >> lvl;
            projects[i].skills_required[skill] = lvl;
        }
    }

    return 0;
}