#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> graph[], int start, int n)
{
    vector<bool> visited(n, false);
    queue<int> q;

    // start node
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        // visiting adjacent nodes
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int n = 6; // number of nodes
    vector<int> graph[n];

    // adding edges
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(5);

    graph[4].push_back(5);

    cout << "BFS Traversal starting from node 0: ";
    bfs(graph, 0, n);
    cout << endl;

    return 0;
}