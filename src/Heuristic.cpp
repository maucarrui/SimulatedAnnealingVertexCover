#include "Heuristic.hpp"
#include <iostream>

/**
 * Simmulated Annealing Heuristic constructor.
 *
 * @param G                  The graph.
 * @param initialSolution    The initial solution.
 * @param initialTemperature The initial temperature.
 * @param coolingFactor      The cooling factor.
 * @param L                  The size of the batch.
 * @param epsilon            The lowest the temperature can go.
 */
Heuristic::Heuristic(const Graph &G,
                     Solution initialSolution,
		     double initialTemperature,
		     double coolingFactor,
		     double L,
		     double epsilon,
		     double beta):
    G(G) {
    this->temperature   = initialTemperature;
    this->coolingFactor = coolingFactor;
    this->L             = L;
    this->epsilon       = epsilon;
    this->beta          = beta;

    int initialCost = calculateCost(initialSolution);
  
    this->initialSolution = initialSolution;
    this->currentSolution = initialSolution;
    this->bestSolution    = initialSolution;

    this->initialSolution.setCost(initialCost);
    this->currentSolution.setCost(initialCost);
    this->bestSolution.setCost(initialCost);

    this->status = "";
}

/**
 * Sweeps a given solution and returns the local minimum found.
 * Sweeping a solution consists of hill descending its search space
 * by checking all the neighbors of the solution and checking if 
 * one of those has a lower cost than the given one, repeating 
 * this process until the solution is a minimum.
 *
 * @param s The solution to sweep.
 * @return  A local minimum solution.
 */
Solution Heuristic::sweepSolution(Solution s) {
    std::vector<bool> cover;
    Solution neighbor;
    double neighborCost, currentCost;
    bool foundBetter;
    int coverSize, size;

    Solution current = s;

    do {
	cover       = current.getCover();
        foundBetter = false;
	size        = cover.size();
        coverSize   = current.size();
	currentCost = calculateCost(current);

        for (int i = 0; i < size; i++) {
	    cover = current.getCover();
	    cover[i] = !cover[i];

	    if (cover[i])
	        coverSize++;
	    else
	        coverSize--;

	    neighbor     = Solution(cover, coverSize);
	    neighborCost = calculateCost(neighbor);
	    
	    if (neighborCost < currentCost) {
	        current     = neighbor;
		foundBetter = true;

		current.setCost(neighborCost);
		break;
	    }
	}

    } while (foundBetter);

    return current;
}

/**
 * Returns a string representation of the current
 * status of the heuristic.
 * @return A string representation of the heuristic.
 */
std::string Heuristic::getStatus() {
    std::string temp;
    temp  = "-----------\n";
    temp += "T: " + std::to_string(temperature) + "\n";
    temp += "Cost: " + std::to_string(currentSolution.getCost()) + "\n";
    temp += G.toStringSolution(currentSolution) + "\n";
    return temp;
}

/**
 * Calculates the cost of the solution.
 * @param s The solution.
 * @return The cost of the solution.
 */
double Heuristic::calculateCost(Solution s) {
    double coveredVertices = (double) s.size();
    double coveredEdges    = (double) G.numCoveredEdges(s);
    double missingEdges    = (double) G.getNumEdges() - coveredEdges;

    return (coveredVertices / coveredEdges) + (missingEdges * beta);
}

/**
 * Given a temperature, it calculates a batch of solutions.
 * Keeping the best solution in the batch while also updating
 * the minimal solution that has been found. In the 
 * end, it returns the average number of solutions that were 
 * accepted in the batch.
 *
 * @param  The temperature.
 * @return The average number of solutions that were accepted in the batch.
 */
double Heuristic::calculateBatch(double T) {
    double r = 0, neighborCost = 0;
    int c = 0, d = 0, maxTries = L * 3;

    Solution neighbor;
    double currentCost, minCost;

    while ( (c < L) && (d < maxTries) ) {
        neighbor     = currentSolution.generateNeighbor();
	neighborCost = calculateCost(neighbor);
	currentCost  = currentSolution.getCost();

	if (neighborCost <= currentCost + T) {
	    currentSolution = neighbor;
	    currentSolution.setCost(neighborCost);
	    
	    minCost = bestSolution.getCost();

	    if (neighborCost < minCost) {
                bestSolution = currentSolution;
		bestSolution.setCost(neighborCost);
	    }
	    
	    c++;
	    r += neighborCost;
	} else {
	    d++;
	}
    }

    return (r / L);
}

/**
 * Cools the temperatura while producing a batch 
 * of solutions to the point where the temperature
 * is lower or equal to the given epsilon. This 
 * updates the current solution the heuristic has 
 * produced while also keeping in track the best
 * solution ever produced.
 */
void Heuristic::thresholdAcceptance() {
    double p = 0.0, q = 0.0;
    
    while (temperature > epsilon) {
        q = std::numeric_limits<double>::infinity();
	
	while (p <= q && q >= epsilon) { 
	    q = p;
	    p = calculateBatch(temperature);
	}

	status += getStatus();

	temperature *= coolingFactor;
    }

    bestSolution = sweepSolution(bestSolution);
}

/**
 * Returns the current solution of the batch.
 * @return The current solution of the batch.
 */
Solution Heuristic::getCurrentSolution() {
    return this->currentSolution;
}

/**
 * Returns the best solution that has been produced.
 * @return The best solution that has been produced.
 */
Solution Heuristic::getBestSolution() {
    return this->bestSolution;
}

/**
 * Returns a string representation of the status
 * of the heuristic.
 * 
 * @return A string representation of the status
 *     of the heuristic.
 */
std::string Heuristic::printStatus() {
    std::string temp;
    temp += status;
    temp += "\n ---------- \n";
    temp += printBestSolution();
    return temp;
}

/**
 * Returns a string representation of the best solution.
 * @return A string representation of the best solution.
 */
std::string Heuristic::printBestSolution() {
    std::string temp;
    temp += "===== BEST SOLUTION =====\n";
    temp += "Best cost: " + std::to_string(bestSolution.getCost()) + "\n";
    temp += G.toStringSolution(bestSolution);
    return temp;
}

/**
 * Returns a string representation of the best solution's cost.
 * @return A string representation of the best solution's cost.
 */
std::string Heuristic::printBestCost() {
    return std::to_string(bestSolution.getCost());
}

/**
 * Returns a svg representation of the best solution.
 */
std::string Heuristic::printBestSolutionSVG() {
    return G.printSolution(bestSolution);
}
