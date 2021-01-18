#ifndef VERTEX_H
#define VERTEX_H
#include "Vertex.hpp"
#endif

/**
 * Vertex constructor.
 *
 * @param _ID   The vertex's ID.
 * @param _xPos The vertex's x-axis position.
 * @param _yPos The vertex's y-axis position.
 * @param _name The vertex's name.
 */
Vertex::Vertex(int _ID, int _xPos, int _yPos, std::string _name) {
    this->ID   = _ID;
    this->xPos = _xPos;
    this->yPos = _yPos;
    this->name = _name;
}

/**
 * Returns vertex's ID.
 * @return vertex's ID.
 */
int Vertex::getID() {
    return this->ID;
}

/**
 * Returns vertex's x-axis position.
 * @return vertex's x-axis position.
 */
int Vertex::getX() {
    return this->xPos;
}

/**
 * Returns vertex's y-axis position.
 * @return vertex's y-axis position.
 */
int Vertex::getY() {
    return this->yPos;
}

/**
 * Returns vertex's name.
 * @return vertex's name.
 */
std::string Vertex::getName() {
    return this->name;
}
