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

#ifndef DAO_H
#define DAO_H
#include "DAO.hpp"
#endif

#ifndef SOLUTION_H
#define SOLUTION_H
#include "Solution.hpp"
#endif

#ifndef HEURISTIC_H
#define HEURISTIC_H
#include "Heuristic.hpp"
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

    // Get the path of the sqlite file and the RNG seed.
    std::string pathDB = argv[1];
    int seed           = std::stoi(argv[2]);

    // Set the seed for the RNG.
    std::srand(seed);

    // Get the DAO.
    DAO dao = DAO(pathDB);
    dao.openDB();

    // Get all the vertices and edges.
    std::vector<Vertex> vertices           = dao.getVertices();
    std::vector<std::pair<int, int>> edges = dao.getEdges();

    // Close the conection to the DB.
    dao.closeDB();
    
    // Build the graph.
    Graph G = Graph();
    G.addVertices(vertices);
    G.buildAdjMatrix();
    G.addEdges(edges);

    //std::cout << G.toString() << std::endl;

    // Create an initial solution.
    int numVertices          = G.getNumVertices();
    Solution initialSolution = Solution(numVertices);
    initialSolution.shuffle();

    // Define the heuristic parameters.
    double initialTemperature = 1000;
    double coolingFactor      = 0.8;
    double L                  = 2000;
    double epsilon            = 0.0001;
    double beta               = 10;
    
    Heuristic H = Heuristic(G,
			    initialSolution,
			    initialTemperature,
			    coolingFactor,
			    L,
			    epsilon,
			    beta);

    H.thresholdAcceptance();

    //std::cout << H.printStatus() << std::endl;
    std::cout << G.printSolution(H.getBestSolution()) << std::endl;
}
