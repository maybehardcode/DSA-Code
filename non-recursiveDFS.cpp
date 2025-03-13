#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Graph {
public:
    // Define the adjacency list for the graph
    std::unordered_map<int, std::vector<int>> adjList;
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph, add both directions
    }

    // Non-recursive DFS function
    void DFS(int start) {
        std::unordered_map<int, bool> visited; // Track visited nodes
        std::stack<int> stack; // Stack to store the nodes for DFS

        stack.push(start); // Start the DFS from the given start vertex

        while (!stack.empty()) {
            int current = stack.top(); // Check the top of the stack
            stack.pop(); // Remove it from the stack after visiting
            
            // If current hasn't been visited, mark it as visited and process it
            if (!visited[current]) {
                std::cout << "Visited: " << current << std::endl;
                visited[current] = true;
            }

            // Push all unvisited neighbors of current onto the stack
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
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
    graph.DFS(5);

    return 0;
}
