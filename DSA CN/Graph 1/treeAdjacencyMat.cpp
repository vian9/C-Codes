#include<bits/stdc++.h>
using namespace std;

// DFS hai yeh....isme jo phle aate jaarha lete jaarhe
void print(int** edges, int n, int sv, bool* visited) {
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv) continue;

        // Ab sv k jitne bhi adjacent h will call
        if (edges[sv][i] == 1) {
            if (visited[i]) continue;

            print(edges, n, i, visited);
        }
    }

}

// BFS - level order tree k jaisa h....same level pr ek sth print hokr aayega....similar to trees...
// queue loand print kro
void printBFS(int** edges, int n, int sv, bool* visited) {
    //Queue use krenge jisme dalte jao and nikalte jao
    queue<int> pendingVertices;
    //Starting vertex ko push kro
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        // Front ko bahar nikalo
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;

        // Ab connected vertex ko loop se call
        for (int i = 0; i < n; i++)
        {
            if (edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }

    }
}

//BFS For disconnected graph.....just jitna ho ske print kro and jo bach jaye visited vector se dekhlo and call
void printBFSDisconnected(int** edges, int n) {
    // to check if visited
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // Check in the visited array
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

// Is connected k liye bas ek baar printBFS call krdo....phir agar visited mein kuch bachgya to disconnected h otherwise connected
bool isConnected(int** edges, int n) {
    // to check if visited
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    printBFS(edges, n, 0, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            return false;
        }
    }
    delete[] visited;
    return true;
}

//BFS Traversal - to get Path
void BFS(vector<vector<int> >& graph, vector<bool>& visited, int v, int sv, int ev, vector<int>& path)
{
    if (sv == ev)
    {
        path.push_back(sv); return;
    }


    queue<int> pn;
    unordered_map<int, int> m;
    pn.push(sv);
    visited[sv] = 1;


    while (!pn.empty())
    {
        int s = pn.front();
        pn.pop();

        //Agar end pr aagye toh
        if (graph[s][ev])
        {
            path.push_back(ev);
            // map se s ko push krte gya
            while (s != sv)
            {
                path.push_back(s);
                // map k location change krte gye
                s = m[s];

            }
            path.push_back(sv);
            return;

        }

        // path to follow until u get ev
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && graph[s][i])
            {
                m[i] = s, pn.push(i), visited[i] = 1;
            }
        }
    }

}
//Get Path DFS - DFS is recursive phle usse phir uske child ko call.....BFS is iterative using queue
bool getpathDFS(int** graph, int v, bool* visited, int s, int e, vector<int>& res)
{
    if (s == e)
    {
        res.push_back(s);
        return true;
    }

    visited[s] = true;

    bool ans = false;

    for (int i = 0;i < v;i++)
    {
        if (!visited[i] && graph[s][i] == 1)
            // Call krdia
            ans = getpathDFS(graph, v, visited, i, e, res);
        if (ans == true)
        {
            res.push_back(s);
            return true;
        }

    }

    return ans;
}

// Get Path BFS returing Path in vector
vector<int>* getPathBFS(int** edges, int n, int sv, int ev, bool* visited) {
    if (sv = ev) {
        vector<int>* ans;
        ans->push_back(sv);
        return ans;
    }

    queue<int> pendingNodes;
    unordered_map<int, int> verticesConnect;
    pendingNodes.push(sv);
    visited[sv] = true;

    while (!pendingNodes.empty())
    {
        int front = pendingNodes.front();
        pendingNodes.pop();

        //Agar end vertex se connect hogya toh
        if (edges[front][ev]) {
            vector<int>* path;
            path->push_back(ev);
            // Ab peeche se traverse krke array mein dalte jao and map se traverse
            while (front != sv)
            {
                path->push_back(front);
                front = verticesConnect[front];
            }
            path->push_back(sv);
            return path;
        }

        // Front vertex k liye traverse kiye 
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[front][i] == 1) {
                verticesConnect[front] = i;
                visited[i] = true;
                pendingNodes.push(i);
            }
        }

    }
    return NULL;
}


int main() {
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int* [n];
    // Adjacency Matrix lelia of n*n as saare vertex k edges store krna h
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    //To check is vertex is visted or not
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    //Input
    //  7
    //  8
    //  0 1
    //  0 2
    //  1 3
    //  1 4
    //  3 5
    //  4 5
    //  5 6
    //  2 6
    print(edges, n, 0, visited);
    cout << endl;
    printBFS(edges, n, 0, visited);
    cout << endl;
    printBFSDisconnected(edges, n);
    vector<int>* path = getPathBFS(edges, n, 0, 4, visited);
    vector<int> ::iterator it = path->begin();
    while (it != path->end())
    {
        cout << *it << endl;
        it++;
    }

    delete[] visited;
    delete[] edges;
    return 0;
}