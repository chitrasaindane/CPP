#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;  
    result.push_back(node);  

    // Visit all neighbors of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {  
            dfs(neighbor, graph, visited, result); 
        }
    }
}

// Function to start DFS from a given starting node
vector<int> dfsTraversal(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); 
    vector<int> result;  

    dfs(start, graph, visited, result);  

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
    vector<int> traversalOrder = dfsTraversal(graph, start);

    for (int node : traversalOrder) {
        cout << node << " ";
    }

    return 0;
}
