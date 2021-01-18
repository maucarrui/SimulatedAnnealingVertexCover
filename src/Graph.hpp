#include <map>
#include <vector>

class Graph {
    private:

	int numVertices;
        int numEdges;

        std::map<int, int> searchTable;
        std::map<int, Vertex> vertices;

        std::vector<std::vector<double>> adjacencyMatrix;

        void buildSearchTable();
    
    public:
        Graph();

        void addVertex(Vertex v);
        void addEdge(int uID, int vID);
        
        void buildAdjMatrix();

        int getNumVertices();
        int getNumEdges();

        bool existsEdge(int u, int v);

        std::string toString();
};
