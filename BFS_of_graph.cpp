// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

// https://discuss.geeksforgeeks.org/comment/11c1afed4273abb670740e381ecc65fc

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;

    vector<bool> visited(V, false);
    queue<int> traverse;

    visited[0] = true;
    traverse.push(0);

    while (!traverse.empty())
    {
        int u = traverse.front();
        traverse.pop();
        ans.push_back(u);

        for (int &v : adj[u])
        {
            if (visited[v] == false)
            {
                traverse.push(v);
                visited[v] = true;
            }
        }
    }

    return ans;
}

int main()
{
    // Test Case
    /*
        5 4
        0 1
        0 2
        0 3
        2 4
    */
    // output: 0 1 2 3 4

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    // directed graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = bfsOfGraph(V, adj);

    for (int &x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}