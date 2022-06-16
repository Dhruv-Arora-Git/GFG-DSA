// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

// https://discuss.geeksforgeeks.org/comment/e167b6148ef2fa76bb1f1d7d1a82dcb3

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1. using DFS
bool DFS(int src, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;

    for (int &u : adj[src])
    {
        if (visited[u] == false)
        {
            if (DFS(u, src, adj, visited))
                return true;
        }
        else if (u != parent)
            return true;
    }

    return false;
}

bool checkDFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
        {
            if (DFS(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}

// 2. using BFS
bool BFS(vector<int> adj[], vector<bool> &visited, int src)
{
    // node, parent
    queue<pair<int, int>> q;

    q.push({src, -1});
    visited[src] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (int &u : adj[node])
        {
            if (visited[u] == false)
            {
                visited[u] = true;
                q.push({u, node});
            }
            else if (u != parent)
            {
                return true;
            }
        }
    }

    return false;
}

bool checkBFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
        {
            if (BFS(adj, visited, i))
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{

    return checkDFS(adj, V);

    // return checkBFS(adj, V);
}
int main()
{
    int V, E;
    cin >> V >> E;
    /*
    Sample Input:
        5 5
        0 4
        1 2
        1 4
        2 3
        3 4

    Sample Output:
        Cycle Detected
    */
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = isCycle(V, adj);
    if (ans)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle Detected\n";
    return 0;
}
