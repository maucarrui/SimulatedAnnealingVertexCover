#include "DAO.hpp"

/**
 * Default constructor.
 */
DAO::DAO() {}

/**
 * Constructor for a DAO (Database Access Object).
 * @param location The sqlite3 file location.
 */
DAO::DAO(std::string location) {
    this->location = location;
}

/**
 * Opens a connection to the database.
 */
int DAO::openDB() {
    const char* c_location = location.c_str();
    int exit = sqlite3_open(c_location, &DB);
    
    if (exit) {
        // std::cerr << "Error at opening DB: " << sqlite3_errmsg(DB) << std::endl;
	return -1;
    } else {
        // std::cout << "Opened database successfully" << std::endl;
        return 0;
    }
}

/**
 * Closes the connection with the database.
 */
void DAO::closeDB() {
    sqlite3_close(DB);
    // std::cout << "Closed database connection successfully." << std::endl;
}

/**
 * Returns a vertex given its ID.
 * @param ID The vertex's ID.
 * @return The found vertex.
 */
Vertex DAO::getVertexByID(int ID) {
    // Vertex's attributes.
    double xPos;
    double yPos;
    std::string name;

    // SQL query;
    std::string query;
    query  = "SELECT * FROM vertices WHERE id = ";
    query += std::to_string(ID);

    const char* c_query = query.c_str();

    // Execute the query.
    sqlite3_stmt * stmt;
    sqlite3_prepare(DB, c_query, -1, &stmt, NULL);

    sqlite3_step(stmt);
    
    xPos = sqlite3_column_double(stmt, 1);
    yPos = sqlite3_column_double(stmt, 2);
    name = std::string( (char *) sqlite3_column_text(stmt, 3) );

    return Vertex(ID, xPos, yPos, name);
}

/**
 * Returns all the current vertices in the database.
 * @return A vector containing all the vertices which are in the DB.
 */
std::vector<Vertex> DAO::getVertices() {
    // Vector of vertices.
    std::vector<Vertex> vertices;
  
    // Worker's attributes.
    int ID;
    double xPos;
    double yPos;
    std::string name;

    // SQL query;
    std::string query;
    query = "SELECT * FROM vertices";

    const char* c_query = query.c_str();

    // Execute the query.
    sqlite3_stmt * stmt;
    sqlite3_prepare(DB, c_query, -1, &stmt, NULL);

    sqlite3_step(stmt);

    while (sqlite3_column_int(stmt, 0)) {
        ID   = sqlite3_column_int(stmt, 0);
	xPos = sqlite3_column_double(stmt, 1);
	yPos = sqlite3_column_double(stmt, 2);
        name = std::string( (char *) sqlite3_column_text(stmt, 3) );
	
	Vertex v = Vertex(ID, xPos, yPos, name);
	vertices.push_back(v);

	sqlite3_step(stmt);
    }

    return vertices;
}

/**
 * Returns all the current edges in the database.
 * @return A vector containing all the edges which are in the DB.
 */
std::vector<std::pair<int, int>> DAO::getEdges() {
    // Vector of edges.
    std::vector<std::pair<int, int>> edges;

    // Edge attributes.
    int id_origin;
    int id_target;

    // SQL query;
    std::string query;
    query = "SELECT * FROM aristas";

    const char* c_query = query.c_str();

    // Execute query.
    sqlite3_stmt * stmt;
    sqlite3_prepare(DB, c_query, -1, &stmt, NULL);

    sqlite3_step(stmt);

    while (sqlite3_column_int(stmt, 0)) {
        id_origin = sqlite3_column_int(stmt, 0);
	id_target = sqlite3_column_int(stmt, 1);
	
	edges.push_back(std::make_pair(id_origin, id_target));

	sqlite3_step(stmt);
    }

    return edges;
}
