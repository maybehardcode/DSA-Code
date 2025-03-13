#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
public:
    // Adjacency list representation of the graph
    std::unordered_map<int, std::vector<int>> adjList;
    
    // Function to add an edge to the graph (assuming an undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Helper function for recursive DFS
    void DFSUtil(int vertex, std::unordered_map<int, bool>& visited) {
        // Mark the current vertex as visited and process it
        visited[vertex] = true;
        std::cout << "Visited: " << vertex << std::endl;

        // Recursively visit each adjacent vertex that hasn't been visited
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Public function to start DFS from a given vertex
    void DFS(int start) {
        std::unordered_map<int, bool> visited; // Keeps track of visited vertices
        DFSUtil(start, visited); // Call the recursive helper function
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);

    std::cout << "DFS starting from vertex 0:" << std::endl;
    graph.DFS(0);

    return 0;
}
