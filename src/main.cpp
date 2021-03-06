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
    s += "Usage: ./vc <datatabase.db> <randomSeed> [option]\n";
    s += "Arguments: \n";
    s += "    <database.db>  The sqlite3 file containing all the information.\n";
    s += "    <randomSeed>   The seed for the RNG.\n";
    s += "Options: \n";
    s += "    --verbose      Prints a more detailed execution of the heuristic.\n";
    s += "    --onlycost     Prints only the cost of the best found solution.\n";
    s += "    --visual       Prints an svg representation of the graph and the solution.\n";

    return s;
}

int main(int argc, char** argv) {
    int mode = -1;

    if (argc < 3 || argc > 4) {
        std::cout << usage() << std::endl;
	return -1;
    } else if (argc == 4) {
        std::string option0 = "--verbose";
	std::string option1 = "--onlycost";
	std::string option2 = "--visual";

	if (!option0.compare(argv[3]))
	    mode = 0;
	else if (!option1.compare(argv[3]))
	    mode = 1;
	else if (!option2.compare(argv[3]))
	    mode = 2;
	else {
	    std::cout << usage() << std::endl;
	    return -1;
	}
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
    
    if (mode == -1)
        std::cout << H.printBestSolution() << std::endl;
    else if (mode == 0)
        std::cout << H.printStatus() << std::endl;
    else if (mode == 1)
        std::cout << H.printBestCost() << std::endl;
    else if (mode == 2)
        std::cout << H.printBestSolutionSVG() << std::endl;
}
