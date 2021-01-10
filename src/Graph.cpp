#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.hpp"
#endif

Graph::Vertex::Vertex(int _ID, int _xPos, int _yPos, std::string _name) {
    this->ID   = _ID;
    this->xPos = _xPos;
    this->yPos = _yPos;
    this->name = _name;
}

int Graph::Vertex::getID() {
    return this->ID;
}

int Graph::Vertex::getX() {
    return this->xPos;
}

int Graph::Vertex::getY() {
    return this->yPos;
}

int Graph::Vertex::getname() {
    return this->name;
}

Graph::Graph() {
    this->numVertices = 0;
    this->numEdges    = 0;
}

void Graph::addVertex(int ID, int xPos, int yPos, std::string name) {
    Vertex v = Vertex(ID, xPos, yPos, name);
    vertices.emplace(ID, v);
    numVertices++;
}

void Graph::addEdge(int u, int v) {
    int numRows    = adjacencyMatrix.size();
    int numColumns = adjacencyMatrix[0].size();

    // TO DO: Return exception.
    if ((numRows == 0) || numColumns == 0)
        return;

    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1;

    numEdges++;
}

void Graph::buildAdjMatrix() {
    std::map<int, Vertex>::iterator it;
    int ID;
    int index;

    adjacencyMatrix.resize(numVertices, std::vector<double>(numVertices));

    index = 0;
    for (it = adjacencyMatrix.begin; it != adjacencyMatrix; it++) {
        ID = it->first;
	searchTable(index, ID);
	index++;
    }
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
