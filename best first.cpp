#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int value;
    int heuristic; // Heuristic value for Best-First Search
    Node(int v, int h) : value(v), heuristic(h) {}
};

// Comparator for priority queue based on heuristic value
struct CompareHeuristic {
    bool operator()(const Node& n1, const Node& n2) const {
        return n1.heuristic > n2.heuristic; // For Best-First Search, prioritize nodes with lower heuristic values
    }
};

// Best-First Search algorithm
void best_first_search(vector<vector<int>>& graph, int start, int goal) {
    vector<bool> visited(graph.size(), false);
    priority_queue<Node, vector<Node>, CompareHeuristic> pq;
    pq.push(Node(start, 0)); // Start node with heuristic value 0

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.value == goal) {
            cout << "Goal found: " << current.value << endl;
            return;
        }

        if (!visited[current.value]) {
            cout << "Visiting node: " << current.value << endl;
            visited[current.value] = true;

            // Enqueue neighbors with their heuristic values
            for (int neighbor : graph[current.value]) {
                if (!visited[neighbor]) {
                    // Calculate heuristic value for neighbor
                    // For simplicity, assume heuristic value is equal to the distance to the goal
                    int heuristic = abs(neighbor - goal);
                    pq.push(Node(neighbor, heuristic));
                }
            }
        }
    }

    cout << "Goal not found" << endl;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 3},     // Node 0 is connected to nodes 1 and 3
        {0, 2, 4},  // Node 1 is connected to nodes 0, 2, and 4
        {1, 5},     // Node 2 is connected to nodes 1 and 5
        {0},        // Node 3 is connected to node 0
        {1},        // Node 4 is connected to node 1
        {2}         // Node 5 is connected to node 2
    };

    cout << "Starting Best-First Search..." << endl;
    best_first_search(graph, 0, 5); // Start BFS from node 0 and search for node 5
    return 0;
}