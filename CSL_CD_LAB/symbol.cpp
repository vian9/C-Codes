#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <unordered_set>
// #include <pair>

using namespace std;

int main()
{
    string myText;

    ifstream MyReadFile("void.txt");

    unordered_set<string> datatypes;

    datatypes.insert("int");
    datatypes.insert("float");
    datatypes.insert("long int");
    datatypes.insert("string");
    datatypes.insert("double");

    regex regexp("([a-zA-Z0-9_]+)(\\s+)(([a-zA-Z_\\*]?[a-zA-Z0-9_]*(=[a-zA-Z0-9]+)?)[,;]?((\\s*)[a-zA-Z_\\*]?[a-zA-Z0-9_]*?(=[a-zA-Z0-9]+)?[,;])*)(\\(\\)*)?");

    unordered_map<string, pair<string, string>> symbol_table;

    while (getline(MyReadFile, myText))
    {
        smatch m;

        regex_search(myText, m, regexp);

        regex ws_re("(\\s*)[,.;](\\s*)");
        if (datatypes.find(m[1]) != datatypes.end())
        {
            string curr = m[3];
            sregex_token_iterator rend;
            sregex_token_iterator a(curr.begin(), curr.end(), ws_re, -1);
            while (a != rend)
            {
                // if(*a == "main") { a++; continue; }
                string type = "variable";
                // cout << "here " << m[m.size() - 1] << endl;
                if (m[m.size() - 1] != "")
                    type = "function";
                symbol_table[*a] = {m[1], type};
                a++;
            }
        }
    }

    cout << "Symbol Table: \n"
         << endl;
    int i = 1;
    for (auto it : symbol_table)
    {
        cout << i << ". "
             << "Variable_name: " << it.first << ", datatype: " << it.second.first << ", type: " << it.second.second << "\n\n";
        i++;
    }

    return 0;
}