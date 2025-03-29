#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function BFS traversal 
vector<int> bfsTraversal(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size(); 

    vector<int> result;  
    queue<int> bfsQueue;  
    vector<bool> visited(numNodes, false);  

    visited[start] = true;  
    bfsQueue.push(start);  


    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();  
        bfsQueue.pop();  
        result.push_back(current);  

        // Check all neighbors of the current node
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {  
                visited[neighbor] = true;  
                bfsQueue.push(neighbor);  
            }
        }
    }

    return result;  
}

int main() {
    // Graph representation as an adjacency list
    vector<vector<int>> graph = {
        {1, 2, 3},  // Node 0 is connected to 1, 2, 3
        {0},        // Node 1 is connected to 0
        {0, 4},     // Node 2 is connected to 0, 4
        {0},        // Node 3 is connected to 0
        {2}         // Node 4 is connected to 2
    };

    int start = 0;  
    vector<int> traversalOrder = bfsTraversal(graph, start);

    // Print the BFS traversal order
    for (int node : traversalOrder) {
        cout << node << " ";
    }

    return 0;
}
