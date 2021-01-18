#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.hpp"
#endif

Graph::Graph() {
    this->numVertices = 0;
    this->numEdges    = 0;
}

void Graph::addVertex(Vertex v) {
    int ID = v.getID();
    vertices.emplace(ID, v);
    numVertices++;
}

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

void Graph::buildSearchTable() {
    index = 0;
    for (it = vertices.begin(); it != vertices.end(); it++) {
        ID = it->first;
	searchTable.emplace(index, ID);
	index++;
    }
}

void Graph::buildAdjMatrix() {
    std::map<int, Vertex>::iterator it;
    int ID;
    int index;

    // Resize adjacency matrix for it to be of size |V| x |V|.
    adjacencyMatrix.resize(numVertices, std::vector<double>(numVertices));

    // Build search table.
    buildSearchTable();
}

int Graph::getNumVertices() {
    return this->numVertices;
}

int Graph::getNumEdges() {
    return this->numEdges;
}

bool Graph::existsEdge(int u, int v) {
    return (adjacencyMatrix[u][v] == 1);
}

std::string Graph::toString() {
    return "";
}
