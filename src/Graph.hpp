#include <map>
#include <vector>

class Graph {
    private:

        class Vertex {
	    public:
	        Vertex(int ID, int xPos, int yPos, std::string name);

                int getID();
	        int getX();
	        int getY();
	        std::string getName();
	};

	int numVertices;
        int numEdges;

        std::map<int, int> searchTable;
        std::map<int, Vertex> vertices;

        std::vector<std::vector<double>> adjacencyMatrix;
    
    public:
        Graph();

        void addVertex(int ID, int xPos, int yPos, std::string name);
        void addEdge(int uID, int vID);
        
        void buildAdjMatrix();

        int getNumVertices();
        int getNumEdges();

        bool existsEdge(int u, int v);

        std::string toString();
};
