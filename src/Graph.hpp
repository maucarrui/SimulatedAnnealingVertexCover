#include <map>
#include <vector>

#ifndef VERTEX_H
#define VERTEX_H
#include "Vertex.hpp"
#endif

#ifndef SOLUTION_H
#define SOLUTION_H
#include "Solution.hpp"
#endif

class Graph {
    private:

	int numVertices;
        int numEdges;

        std::map<int, int> searchTable;
        std::map<int, Vertex> vertices;

        std::vector<std::vector<double>> adjacencyMatrix;

        void buildSearchTable();

        int getIndexOf(int ID) const;
    
    public:
        Graph();

        void addVertex(Vertex v);
        void addEdge(int uID, int vID);

        void addVertices(std::vector<Vertex> vs);
        void addEdges(std::vector<std::pair<int, int>> es);
        
        void buildAdjMatrix();

        int getNumVertices();
        int getNumEdges() const;

        bool existsEdge(int u, int v);

        int numCoveredEdges(Solution s) const;

        bool isFeasibleCover(Solution s);

        std::string toString();

        std::string toStringSolution(Solution s) const;
        std::string printSolution(Solution s);
};
