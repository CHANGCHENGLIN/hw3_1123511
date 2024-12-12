//Oliver 林章正
//1123511
//2024.12.12

Example Test Inputs and Outputs:

Graph Representation Using Adjacency List:
Input:
4 nodes, 5 edges
Edges: (0, 1), (0, 2), (1, 2), (1, 3), (2, 3)
Output:
0: 1 2
1: 0 2 3
2: 0 1 3
3: 1 2

BFS Traversal:
Input:
6
1 2
0 3 4
0 5
1
1
2
Output: 0 1 2 3 4 5

DFS Traversal:
Input:
6
1 2
0 3
0 4
1
2 5
4
Output: 0 1 3 2 4 5

Prim’s MST Algorithm:
Input:
5 vertices, 6 edges
Edges: (0, 1, 2), (0, 3, 6), (1, 3, 8), (1, 2, 3), (1, 4, 5), (2, 4, 7)
Output:
Total weight of the MST: 16
