//Oliver Lin 林章正 
//1123511 
//2024.12.12

#include <iostream>
#include <vector>
#include <stack>
#include <sstream> // Library for handling strings and processing input

using namespace std;

// Performs a Depth-First Search (DFS) traversal of the graph and records the traversal order
void performDFS(int currentNode, const vector<vector<int>>& adjacencyList, vector<bool>& visitedNodes, vector<int>& traversalOrder) {
    // Mark the current node as visited
    visitedNodes[currentNode] = true;

    // Add the current node to the traversal order
    traversalOrder.push_back(currentNode);

    // Recursively visit all unvisited neighbors of the current node
    for (int neighborNode : adjacencyList[currentNode]) {
        if (!visitedNodes[neighborNode]) {
            performDFS(neighborNode, adjacencyList, visitedNodes, traversalOrder);
        }
    }
}

int main() {
    vector<vector<int>> adjacencyList;  // Stores the adjacency list representation of the graph
    string inputLine;

    // Continuously read input lines until an empty line is encountered
    while (getline(cin, inputLine)) {
        if (inputLine.empty()) break;  // Stop reading input if the line is empty

        // Create a vector to hold the neighbors of the current node
        stringstream lineStream(inputLine);
        vector<int> neighbors;
        int neighborNode;

        // Parse the input line to extract neighbors for the current node
        while (lineStream >> neighborNode) {
            neighbors.push_back(neighborNode);
        }

        // Add the list of neighbors to the adjacency list
        adjacencyList.push_back(neighbors);
    }

    // Prepare visited array and traversal order container
    int totalNodes = adjacencyList.size();  // Number of nodes in the graph
    vector<bool> visitedNodes(totalNodes, false);  // Tracks whether each node has been visited
    vector<int> traversalOrder;  // Stores the DFS traversal order

    // Start DFS from the first node (node 0)
    performDFS(0, adjacencyList, visitedNodes, traversalOrder);

    // Output the DFS traversal order, separated by spaces
    for (size_t i = 0; i < traversalOrder.size(); ++i) {
        cout << traversalOrder[i];
        if (i < traversalOrder.size() - 1) cout << " ";  // Add a space between numbers, except after the last one
    }
    cout << endl;  // End the output with a newline

    return 0;  // Indicate successful program execution
}
