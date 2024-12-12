//Oliver Lin 林章正
//1123511
//2024.12.12

#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // Library for handling strings and processing input with spaces

using namespace std;

// Performs BFS traversal on the graph and returns the traversal order
vector<int> performBFS(const vector<vector<int>>& adjacencyList) {
    int totalNodes = adjacencyList.size();  // Total number of nodes in the graph
    vector<bool> visited(totalNodes, false);  // Tracks whether a node has been visited
    vector<int> traversalOrder;  // Stores the order in which nodes are visited during BFS

    // Queue for managing nodes to be visited next
    queue<int> nodeQueue;

    // Start BFS from the first node (node 0)
    visited[0] = true;  // Mark the starting node as visited
    nodeQueue.push(0);  // Add the starting node to the queue

    while (!nodeQueue.empty()) {
        // Retrieve and remove the front node from the queue
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Append the current node to the traversal order
        traversalOrder.push_back(currentNode);

        // Iterate through all neighbors of the current node
        for (int neighbor : adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // Mark the neighbor as visited
                nodeQueue.push(neighbor);  // Add the neighbor to the queue for future processing
            }
        }
    }

    return traversalOrder;  // Return the order of nodes visited during BFS
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

    // Perform BFS on the graph and retrieve the traversal order
    vector<int> bfsResult = performBFS(adjacencyList);

    // Output the BFS traversal order, with spaces between node numbers
    for (size_t i = 0; i < bfsResult.size(); ++i) {
        cout << bfsResult[i];
        if (i < bfsResult.size() - 1) cout << " ";  // Add a space between numbers, except after the last one
    }
    cout << endl;  // End the output with a newline

    return 0;  // Indicate successful program execution
}
