vector<string> ans;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (s[j] == ' ')
            {
                string sbt = s.substr(i, j - i);
                ans.push_back(sbt);
                i = j;
            }
        }
    }
    string final;
    for (int i = ans.size(); i >= 0; i--)
    {
        final += ans[i];
        final += ' ';
    }
    return final;