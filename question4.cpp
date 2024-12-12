//Oliver Lin 林章正
//1123511
//2024.12.12

#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Library for defining integer limits

using namespace std;

// Calculates the total weight of the Minimum Spanning Tree (MST) using Prim's algorithm
int calculateMSTWeight(int totalVertices, const vector<vector<pair<int, int>>>& graph) {
    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    vector<int> minEdgeWeight(totalVertices, INT_MAX);  // Minimum edge weight to connect each vertex
    vector<bool> isInMST(totalVertices, false);  // Tracks if a vertex is included in the MST

    int totalMSTWeight = 0;  // Total weight of the MST

    // Start from vertex 0
    minEdgeWeight[0] = 0;
    minHeap.push({0, 0});  // Push the starting vertex (weight 0, vertex 0)

    while (!minHeap.empty()) {
        // Get the vertex with the minimum weight
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        // If the vertex is already included in MST, skip it
        if (isInMST[currentVertex]) continue;

        // Include this vertex in the MST and add its weight
        isInMST[currentVertex] = true;
        totalMSTWeight += minEdgeWeight[currentVertex];

        // Update the edge weights for adjacent vertices
        for (const auto& edge : graph[currentVertex]) {
            int adjacentVertex = edge.first;
            int edgeWeight = edge.second;

            // Update the edge weight if the vertex is not in MST and the weight is smaller
            if (!isInMST[adjacentVertex] && edgeWeight < minEdgeWeight[adjacentVertex]) {
                minEdgeWeight[adjacentVertex] = edgeWeight;
                minHeap.push({minEdgeWeight[adjacentVertex], adjacentVertex});
            }
        }
    }

    return totalMSTWeight;  // Return the total weight of the MST
}

int main() {
    int totalVertices, totalEdges;

    // Read the number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> totalVertices >> totalEdges;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> graph(totalVertices);

    // Read the edges and their weights
    cout << "Enter each edge as 'vertex1 vertex2 weight':\n";
    for (int i = 0; i < totalEdges; ++i) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;

        // Since the graph is undirected, add both directions
        graph[vertex1].emplace_back(vertex2, weight);
        graph[vertex2].emplace_back(vertex1, weight);
    }

    // Calculate the total weight of the MST
    int mstWeight = calculateMSTWeight(totalVertices, graph);

    // Output the total weight of the MST
    cout << "Total weight of the MST: " << mstWeight << endl;

    return 0;  // Indicate successful program execution
}
