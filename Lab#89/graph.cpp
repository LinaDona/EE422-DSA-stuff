#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX_VERTICES 100

// Graph class
class Graph {
private:
    int vertices;
    bool isDirected;
    bool isWeighted;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int adjacencyList[MAX_VERTICES][2 * MAX_VERTICES];

public:
    // Constructor
    Graph(int V, bool directed, bool weighted) {
        vertices = V;
        isDirected = directed;
        isWeighted = weighted;
        initializeGraph();
    }

    // Initialize the graph
    void initializeGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjacencyMatrix[i][j] = 0;
            }
            adjacencyList[i][0] = 0;
        }
    }

    // Insert a new vertex
    void insertVertex() {
        if (vertices == MAX_VERTICES) {
            cout << "Graph overflow!" << endl;
            return;
        }

        vertices++;
        adjacencyList[vertices - 1][0] = 0;
    }

    // Insert a new edge
    void insertEdge(int u, int v, int weight = 0) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertex!" << endl;
            return;
        }

        adjacencyMatrix[u][v] = isWeighted ? weight : 1;
        adjacencyList[u][++adjacencyList[u][0]] = v;

        if (!isDirected) {
            adjacencyMatrix[v][u] = isWeighted ? weight : 1;
            adjacencyList[v][++adjacencyList[v][0]] = u;
        }
    }

    // Breadth-First Search (BFS)
    void BFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};

        cout << "BFS traversal: ";

        visited[startVertex] = true;
        cout << startVertex << " ";

        queue<int> q;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            for (int i = 1; i <= adjacencyList[currentVertex][0]; i++) {
                int adjacentVertex = adjacencyList[currentVertex][i];

                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    cout << adjacentVertex << " ";
                    q.push(adjacentVertex);
                }
            }
        }

        cout << endl;
    }

    // Depth-First Search (DFS) Recursive
    void DFSRecursiveUtil(int startVertex, bool visited[]) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 1; i <= adjacencyList[startVertex][0]; i++) {
            int adjacentVertex = adjacencyList[startVertex][i];
            if (!visited[adjacentVertex]) {
                DFSRecursiveUtil(adjacentVertex, visited);
            }
        }
    }

    void DFSRecursive(int startVertex) {
        cout << "DFS (Recursive) traversal: ";

        bool visited[MAX_VERTICES] = {false};
        DFSRecursiveUtil(startVertex, visited);

        cout << endl;
    }

    // Depth-First Search (DFS) Iterative
    void DFSIterative(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        cout << "DFS (Iterative) traversal: ";

        stack<int> stack;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                cout << currentVertex << " ";

                for (int i = 1; i <= adjacencyList[currentVertex][0]; i++) {
                    int adjacentVertex = adjacencyList[currentVertex][i];
                    if (!visited[adjacentVertex]) {
                        stack.push(adjacentVertex);
                    }
                }
            }
        }

        cout << endl;
    }

    // Dijkstra's Algorithm
    void dijkstra(int source) {
        bool visited[MAX_VERTICES] = {false};
        int distance[MAX_VERTICES];
        int parent[MAX_VERTICES];

        for (int i = 0; i < vertices; i++) {
            distance[i] = INT_MAX;
            parent[i] = -1;
        }

        distance[source] = 0;

        for (int i = 0; i < vertices - 1; i++) {
            int minDist = INT_MAX;
            int minVertex = -1;

            for (int j = 0; j < vertices; j++) {
                if (!visited[j] && distance[j] < minDist) {
                    minDist = distance[j];
                    minVertex = j;
                }
            }

            visited[minVertex] = true;

            for (int j = 0; j < vertices; j++) {
                if (!visited[j] && adjacencyMatrix[minVertex][j] != 0 &&
                    distance[minVertex] != INT_MAX &&
                    distance[minVertex] + adjacencyMatrix[minVertex][j] < distance[j]) {
                    distance[j] = distance[minVertex] + adjacencyMatrix[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }

        cout << "Shortest paths from vertex " << source << " (Dijkstra's Algorithm):" << endl;
        for (int i = 0; i < vertices; i++) {
            if (i != source) {
                cout << "Path: ";
                printPath(parent, i);
                cout << " Distance: " << distance[i] << endl;
            }
        }
    }

    // Print path using parent array
    void printPath(int parent[], int vertex) {
        if (parent[vertex] == -1) {
            cout << vertex;
            return;
        }

        printPath(parent, parent[vertex]);
        cout << " -> " << vertex;
    }

    // Floyd-Warshall Algorithm
    void floydWarshall() {
        int distance[MAX_VERTICES][MAX_VERTICES];

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                distance[i][j] = adjacencyMatrix[i][j];
            }
        }

        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                        distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }

        cout << "Shortest paths between all pairs of vertices (Floyd-Warshall Algorithm):" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (i != j && distance[i][j] != INT_MAX) {
                    cout << "Path from " << i << " to " << j << ": ";
                    cout << i << " ";
                    printPathFloydWarshall(distance, i, j);
                    cout << " Distance: " << distance[i][j] << endl;
                }
            }
        }
    }

    // Print path for Floyd-Warshall Algorithm
    void printPathFloydWarshall(int distance[][MAX_VERTICES], int source, int destination) {
        if (distance[source][destination] == adjacencyMatrix[source][destination]) {
            cout << destination;
            return;
        }

        int intermediate = distance[source][destination];
        printPathFloydWarshall(distance, source, intermediate);
        cout << " -> " << intermediate;
        printPathFloydWarshall(distance, intermediate, destination);
    }

    // Minimum Spanning Tree (MST) using Kruskal's algorithm
    void kruskalMST() {
        int parent[MAX_VERTICES];
        int minWeight = 0;

        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
        }

        int edgeCount = 0;
        int edgeIndex[MAX_VERTICES * MAX_VERTICES][3];

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjacencyMatrix[i][j] != 0) {
                    edgeIndex[edgeCount][0] = i;
                    edgeIndex[edgeCount][1] = j;
                    edgeIndex[edgeCount][2] = adjacencyMatrix[i][j];
                    edgeCount++;
                }
            }
        }

        sortEdges(edgeIndex, edgeCount);

        cout << "Minimum Spanning Tree (MST) using Kruskal's algorithm:" << endl;
        for (int i = 0; i < edgeCount; i++) {
            int u = edgeIndex[i][0];
            int v = edgeIndex[i][1];
            int weight = edgeIndex[i][2];

            int setU = findSet(parent, u);
            int setV = findSet(parent, v);

            if (setU != setV) {
                cout << u << " - " << v << " Weight: " << weight << endl;
                minWeight += weight;
                unionSets(parent, setU, setV);
            }
        }

        cout << "MST Weight: " << minWeight << endl;
    }

    // Sort edges based on weight (ascending order)
    void sortEdges(int edgeIndex[][3], int edgeCount) {
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edgeIndex[j][2] > edgeIndex[j + 1][2]) {
                    swap(edgeIndex[j][0], edgeIndex[j + 1][0]);
                    swap(edgeIndex[j][1], edgeIndex[j + 1][1]);
                    swap(edgeIndex[j][2], edgeIndex[j + 1][2]);
                }
            }
        }
    }

    // Find the set of a vertex (used in Kruskal's algorithm)
    int findSet(int parent[], int vertex) {
        if (parent[vertex] != vertex) {
            parent[vertex] = findSet(parent, parent[vertex]);
        }
        return parent[vertex];
    }

    // Union of two sets (used in Kruskal's algorithm)
    void unionSets(int parent[], int setU, int setV) {
        parent[setV] = setU;
    }
};

int main() {
    int numVertices, choice;
    bool directed, weighted;

    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    cout << "Is the graph directed? (0 for No, 1 for Yes): ";
    cin >> directed;

    cout << "Is the graph weighted? (0 for No, 1 for Yes): ";
    cin >> weighted;

    Graph graph(numVertices, directed, weighted);
    cout << "\n------------------------" << endl;
    cout << "1. Insert a new vertex" << endl;
    cout << "2. Insert a new edge" << endl;
    cout << "3. Breadth-First Search (BFS) traversal" << endl;
    cout << "4. Depth-First Search (DFS) traversal (Recursive)" << endl;
    cout << "5. Depth-First Search (DFS) traversal (Iterative)" << endl;
    cout << "6. Shortest path from a given source vertex with Dijkstra's algorithm" << endl;
    cout << "7. Shortest path between all pairs of vertices with Floyd-Warshall algorithm" << endl;
    cout << "8. Minimum Spanning Tree (MST) using Kruskal's algorithm" << endl;
    cout << "9. Exit" << endl;
    cout << "------------------------" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                graph.insertVertex();
                break;
            case 2: {
                int u, v, weight;
                cout << "Enter the source vertex: ";
                cin >> u;
                cout << "Enter the destination vertex: ";
                cin >> v;
                if (weighted) {
                    cout << "Enter the weight of the edge: ";
                    cin >> weight;
                }
                graph.insertEdge(u, v, weight);
                break;
            }
            case 3: {
                int startVertex;
                cout << "Enter the start vertex for BFS traversal: ";
                cin >> startVertex;
                graph.BFS(startVertex);
                break;
            }
            case 4: {
                int startVertex;
                cout << "Enter the start vertex for DFS (Recursive) traversal: ";
                cin >> startVertex;
                graph.DFSRecursive(startVertex);
                break;
            }
            case 5: {
                int startVertex;
                cout << "Enter the start vertex for DFS (Iterative) traversal: ";
                cin >> startVertex;
                graph.DFSIterative(startVertex);
                break;
            }
            case 6: {
                int sourceVertex;
                cout << "Enter the source vertex for Dijkstra's algorithm: ";
                cin >> sourceVertex;
                graph.dijkstra(sourceVertex);
                break;
            }
            case 7:
                graph.floydWarshall();
                break;
            case 8:
                graph.kruskalMST();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);

    return 0;
}