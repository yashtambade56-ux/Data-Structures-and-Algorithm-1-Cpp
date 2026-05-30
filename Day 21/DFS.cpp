#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10];
bool visited[10];

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

int main() {

    // adding edges
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(5);

    graph[4].push_back(5);

    cout << "DFS Traversal starting from node 0: ";
    DFS(0);
    cout << endl;

    return 0;

}