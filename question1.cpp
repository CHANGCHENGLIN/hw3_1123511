//Oliver Lin 林章正
//11235111
//2024.12.12

#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header to use the sort function

using namespace std;

// Function to create an adjacency list for an undirected graph
vector<vector<int>> buildGraph(int nodeCount, const vector<pair<int, int>>& connections) {
    vector<vector<int>> graph(nodeCount); // Initialize the adjacency list

    // Fill the adjacency list with edges
    for (const auto& connection : connections) {
        int node1 = connection.first;
        int node2 = connection.second;

        graph[node1].push_back(node2); // Add node2 to node1's adjacency list
        graph[node2].push_back(node1); // Add node1 to node2's adjacency list
    }

    // Sort the adjacency list for each node
    for (auto& neighbors : graph) {
        sort(neighbors.begin(), neighbors.end());
    }

    return graph;
}

// Function to print the adjacency list
void displayGraph(const vector<vector<int>>& graph) {
    for (size_t i = 0; i < graph.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodeCount, edgeCount;

    // Input: Number of nodes and edges
    cout << "Enter the number of nodes and the number of edges: ";
    cin >> nodeCount >> edgeCount;

    vector<pair<int, int>> connections(edgeCount); // Store edges as pairs of nodes

    // Input: Edges
    cout << "Enter " << edgeCount << " edges in the format 'node1 node2':\n";
    for (auto& connection : connections) {
        cin >> connection.first >> connection.second;
    }

    // Create and print the adjacency list
    vector<vector<int>> graph = buildGraph(nodeCount, connections);

    cout << "Adjacency List:" << endl;
    displayGraph(graph);

    return 0;
}
