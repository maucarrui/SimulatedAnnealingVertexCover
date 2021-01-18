#include <iostream>
#include <string>

#ifndef VERTEX_H
#define VERTEX_H
#include "Vertex.hpp"
#endif

#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.hpp"
#endif

/**
 * Returns the usage of this program.
 * @return The usage of this program.
 */
std::string usage() {
    std::string s = "";
    s += "Usage: ./vc <datatabase.db> <randomSeed> \n";
    s += "Arguments: \n";
    s += "    <database.db>      The sqlite3 file containing all the information.\n";
    s += "    <randomSeed>       The seed for the RNG.\n";

    return s;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << usage() << std::endl;
	return -1;
    }

    Graph G = Graph();

    Vertex a = Vertex(0, 0, 0, "A");
    Vertex b = Vertex(1, 1, 1, "B");
    Vertex c = Vertex(2, 2, 0, "C");

    G.addVertex(a);
    G.addVertex(b);
    G.addVertex(c);

    G.buildAdjMatrix();

    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
}
