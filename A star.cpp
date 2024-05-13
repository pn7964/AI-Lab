#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int value;
    int g_cost; // Cost from start node to current node
    int h_cost; // Heuristic cost (estimated cost from current node to goal node)
    Node(int v, int g, int h) : value(v), g_cost(g), h_cost(h) {}
};

// Comparator for priority queue based on f_cost = g_cost + h_cost
struct CompareFCost {
    bool operator()(const Node& n1, const Node& n2) const {
        return (n1.g_cost + n1.h_cost) > (n2.g_cost + n2.h_cost); // Prioritize nodes with lower f_cost
    }
};

// A* algorithm
void a_star(vector<vector<int>>& graph, int start, int goal) {
    vector<bool> visited(graph.size(), false);
    priority_queue<Node, vector<Node>, CompareFCost> pq;
    pq.push(Node(start, 0, abs(start - goal))); // Start node with g_cost = 0 and h_cost = absolute difference to goal

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

            // Enqueue neighbors with their g_cost and h_cost
            for (int neighbor : graph[current.value]) {
                if (!visited[neighbor]) {
                    int g_cost = current.g_cost + 1; // Assume edge cost of 1
                    int h_cost = abs(neighbor - goal);
                    pq.push(Node(neighbor, g_cost, h_cost));
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

    cout << "Starting A* Algorithm..." << endl;
    a_star(graph, 0, 5); // Start A* from node 0 and search for node 5
    return 0;
}
