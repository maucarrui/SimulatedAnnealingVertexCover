#include <sqlite3.h>
#include <string>
#include <vector>

#ifndef VERTEX_H
#define VERTEX_H
#include "Vertex.hpp"
#endif

class DAO {
    private:
        sqlite3* DB;
        std::string location;
    
    public:
        DAO();
        DAO(std::string location);

        int openDB();
        void closeDB();
        
        Vertex getVertexByID(int ID);
        
        std::vector<Vertex> getVertices();
        std::vector<std::pair<int, int>> getEdges();
};
