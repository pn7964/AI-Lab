#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 3, 4},  // Node 1 is connected to nodes 0, 3, and 4
        {0, 5},     // Node 2 is connected to nodes 0 and 5
        {1},        // Node 3 is connected to node 1
        {1},        // Node 4 is connected to node 1
        {2}         // Node 5 is connected to node 2
    };

    cout << "DFS traversal: ";
    dfs(graph, 0); // Start DFS from node 0
    cout << endl;

    return 0;
}
