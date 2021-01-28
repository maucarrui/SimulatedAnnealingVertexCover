#include "Graph.hpp"
#include <iostream>

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
 *
 */
int Graph::getIndexOf(int ID) const {
    std::map<int, int>::const_iterator it;
    it = searchTable.find(ID);

    return it->second;
}

/**
 * Adds a set of vertices to the graph.
 * @param vs The set of vertices that will be added to the graph.
 */
void Graph::addVertices(std::vector<Vertex> vs) {
    std::vector<Vertex>::iterator it;

    for (it = vs.begin(); it != vs.end(); it++)
        addVertex(*it);
}

/**
 * Adds a set of edges to the graph.
 * @param vs The set of edges that will be added to the graph.
 */
void Graph::addEdges(std::vector<std::pair<int, int>> es) {
    std::vector<std::pair<int, int>>::iterator it;
    std::map<int, int>::iterator jt;
    int u, v;

    for (it = es.begin(); it != es.end(); it++) {
        u = getIndexOf(it->first);
	v = getIndexOf(it->second);
	addEdge(u, v);
    }
}

/**
 * Builds the search table for the vertices.
 * Given the ID of the vertex, the search 
 * table returns the vertex's index.
 */
void Graph::buildSearchTable() {
    std::map<int, Vertex>::iterator it;
    int index = 0;
    int ID;

    for (it = vertices.begin(); it != vertices.end(); it++) {
        ID = it->first;
	searchTable.emplace(ID, index);
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
int Graph::getNumEdges() const {
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
 * Returns the number of edges that are covered 
 * by a vertex cover.
 * @param s The vertex cover.
 * @return  The number of edged that are covered.
 */
int Graph::numCoveredEdges(Solution s) const {
    std::vector<bool> cover = s.getCover();
    int edges = 0;
    int i, j;

    for (i = 0; i < numVertices; i++)
        for (j = 0; j < numVertices; j++)
            if ( (cover[i] || cover[j]) && adjacencyMatrix[i][j] )
                edges++;

    return edges / 2;
}

/**
 * Returns whether or not the solution
 * covers all of the edges of the graph.
 * @param s The vertex cover.
 * @return  True if the cover is feasible,
 *    false otherwise.
 */
bool Graph::isFeasibleCover(Solution s) {
    int e = numCoveredEdges(s);
    return (e == numEdges);
}

/**
 * Returns a string representation of the solution.
 * @return A string representation of the solution.
 */
std::string Graph::toStringSolution(Solution s) const {
    std::map<int, Vertex>::const_iterator it;
    std::string str;
    Vertex v;
    int vIndex, coveredVertices, covered;

    std::vector<bool> cover = s.getCover();

    str             = "Cover: {";
    coveredVertices = s.size();
    covered         = 0;

    for (it = vertices.begin(); it != vertices.end(); it++) {
        v      = it->second;
	vIndex = getIndexOf(v.getID());

        if (cover[vIndex]) {
	    str += v.getName();
	    covered++;
	    
	    if (coveredVertices == covered)
	        str += "}\n";
	    else
	        str += ", ";
	}
    }

    str += "Covered Edges: ";
    str += std::to_string(numCoveredEdges(s));
    str += "/";
    str += std::to_string(numEdges);
    str += "\n";

    return str;
}

/**
 * Returns a string representation in svg 
 * of the given solution.
 * @return A string representation of the solution.
 */
std::string Graph::printSolution(Solution s) {
    std::string svg;
    std::map<int, Vertex>::iterator it, jt;
    Vertex v, u;
    int vID, uID;

    std::vector<bool> cover = s.getCover();

    svg  = "<svg width='";
    svg += std::to_string(1000);
    svg += "' height='";
    svg += std::to_string(1000);
    svg += "' fill='white'>\n";

    // Edges
    for (it = vertices.begin(); it != vertices.end(); it++) {
        v   = it->second;
	vID = getIndexOf(v.getID());

        for (jt = vertices.begin(); jt != vertices.end(); jt++) {
	    u   = jt->second;
	    uID = getIndexOf(u.getID());

	    if (existsEdge(vID, uID)) {
	        svg += "    ";
	        svg += "<line x1='";
		svg += std::to_string(v.getX());
		svg += "' y1='";
		svg += std::to_string(v.getY());
		svg += "' x2='";
		svg += std::to_string(u.getX());
		svg += "' y2='";
		svg += std::to_string(u.getY());
		
		if (cover[uID] || cover[vID])
		    svg += "' stroke='blue'";
		else
		    svg += "' stroke='black'";

		svg += " stroke-width='2' /> \n";
	    }
	}
    }

    // Vertices
    for (it = vertices.begin(); it != vertices.end(); it++) {
        v   = it->second;
	vID = getIndexOf(v.getID());

	svg += "    "; //Indentation.
	svg += "<circle cx='";
	svg += std::to_string(v.getX());
	svg += "' cy='";
	svg += std::to_string(v.getY());
	
	if (cover[vID])
	    svg += "' fill='blue'";
	else
	    svg += "' fill='white'";

	svg += " r='5' stroke='black' stroke-width='3'/> \n";
    }

    svg += "</svg>";
    return svg;
}

/**
 * Returns a string representation in svg 
 * of the graph.
 * @return A string representation of the graph.
 */
std::string Graph::toString() {
    std::string svg;
    std::map<int, Vertex>::iterator it, jt;
    Vertex v, u;
    int vID, uID;

    svg  = "<svg width='";
    svg += std::to_string(1000);
    svg += "' height='";
    svg += std::to_string(1000);
    svg += "' fill='white'>\n";

    // Edges
    for (it = vertices.begin(); it != vertices.end(); it++) {
        v   = it->second;
	vID = getIndexOf(v.getID());

        for (jt = vertices.begin(); jt != vertices.end(); jt++) {
	    u   = jt->second;
	    uID = getIndexOf(u.getID());

	    if (existsEdge(vID, uID)) {
	        svg += "    ";
	        svg += "<line x1='";
		svg += std::to_string(v.getX());
		svg += "' y1='";
		svg += std::to_string(v.getY());
		svg += "' x2='";
		svg += std::to_string(u.getX());
		svg += "' y2='";
		svg += std::to_string(u.getY());
		svg += "' stroke='black' stroke-width='2' /> \n";
	    }
	}
    }

    // Vertices
    for (it = vertices.begin(); it != vertices.end(); it++) {
        v = it->second;

	svg += "    "; //Indentation.
	svg += "<circle cx='";
	svg += std::to_string(v.getX());
	svg += "' cy='";
	svg += std::to_string(v.getY());
	svg += "' r='5' stroke='black' stroke-width='3'/> \n";
    }

    svg += "</svg>";
    return svg;
}
