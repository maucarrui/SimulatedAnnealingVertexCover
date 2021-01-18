#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.hpp"
#endif

/**
 * Graph constructor.
 */
Graph::Graph() {
    this->numVertices = 0;
    this->numEdges    = 0;
}

/**
 * Adds a vertex to the graph.
 * @param v The vertex v that will be added to the graph.
 */
void Graph::addVertex(Vertex v) {
    int ID = v.getID();
    vertices.emplace(ID, v);
    numVertices++;
}

/**
 * Adds an edge to the graph.
 * @param u The index of vertex u.
 * @param v The index of vertex v.
 */
void Graph::addEdge(int u, int v) {
    int numRows    = adjacencyMatrix.size();
    int numColumns = adjacencyMatrix[0].size();

    // TO DO: Return exception.
    if ((numRows == 0) || (numColumns == 0))
        return;

    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1;

    numEdges++;
}

/**
 * Builds the search table for the vertices.
 * Given the index of the vertex, the search 
 * table returns the vertex's ID.
 */
void Graph::buildSearchTable() {
    std::map<int, Vertex>::iterator it;
    int index = 0;
    int ID;

    for (it = vertices.begin(); it != vertices.end(); it++) {
        ID = it->first;
	searchTable.emplace(index, ID);
	index++;
    }
}

/**
 * Builds the adjacency matrix of the graph.
 * This method in only evoked when all the 
 * vertices are added to the graph.
 */
void Graph::buildAdjMatrix() {
    // Resize adjacency matrix for it to be of size |V| x |V|.
    adjacencyMatrix.resize(numVertices, std::vector<double>(numVertices));

    // Build search table.
    buildSearchTable();
}

/**
 * Returns the number of vertices in the graph.
 * @return The number of vertices in the graph.
 */
int Graph::getNumVertices() {
    return this->numVertices;
}

/**
 * Returns the number of edges in the graph.
 * @return The number of edges in the graph.
 */
int Graph::getNumEdges() {
    return this->numEdges;
}

/**
 * Returns whether or not an edge exists
 * between two vertices.
 * @param u The index of the vertex u.
 * @param v The index of the vertex v.
 * @return True if the edge exists, false otherwise.
 */
bool Graph::existsEdge(int u, int v) {
    return (adjacencyMatrix[u][v] == 1);
}

/**
 * Returns a string representation in svg 
 * of the graph.
 * @return A string representation of the graph.
 */
std::string Graph::toString() {
    return "";
}
