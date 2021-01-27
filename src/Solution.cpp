#ifndef SOLUTION_H
#define SOLUTION_H
#include "Solution.hpp"
#endif

/**
 * Solution constructor when only given the number of vertices
 * in the graph.
 * @param numVertices The number of vertices in the graph.
 */
Solution::Solution(int numVertices) {
    this->_size = 0;

    for (int i = 0; i < numVertices; i++)
        cover.push_back(false);
}

/**
 * Solution constructor when given a cover and its size.
 * @param _cover The cover of the solution.
 * @param _size  The size of the cover.
 */
Solution::Solution(std::vector<bool> _cover, int _size) {
    this->_size = _size;
    this->cover = _cover;
}

/**
 * Generates a random solution.
 */
void Solution::shuffle() {
    int numVertices = cover.size();
    double r;

    for (int i = 0; i < numVertices; i++) {
        r = ( (double) rand() / (RAND_MAX) );
	if (r <= 0.5)
	    cover[i] = false;
	else
	    cover[i] = true;
    }
}

/**
 * Returns the size of the cover.
 * @return The size of the cover.
 */
int Solution::size() {
    return this->_size;
}

/**
 * Returns the cover of the solution.
 * @return The cover of the solution.
 */
std::vector<bool> Solution::getCover() {
    return this->cover;
}

/**
 * Generates a neighbor switching a 
 * a random vertex in the cover.
 * @return The generated neighbor.
 */
Solution Solution::generateNeighbor() {
    std::vector<bool> newCover = cover;

    int numVertices = cover.size();
    int r           = rand() % (numVertices + 1);
    int newSize     = _size;

    if (newCover[r])
        newSize--;
    else
        newSize++;

    newCover[r] = !newCover[r];

    return Solution(newCover, newSize);
}

/**
 * Sets the cost of the solution.
 * @param cost The new cost of the solution.
 */
void Solution::setCost(double cost) {
    this->cost = cost;
}

/**
 * Returns the cost of the solution.
 * @return The cost of the solution.
 */
double Solution::getCost() {
    return this->cost;
}
