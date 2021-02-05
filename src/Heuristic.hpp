#include <string>

#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.hpp"
#endif

#ifndef SOLUTION_H
#define SOLUTION_H
#include "Solution.hpp"
#endif

class Heuristic {
    private:
        const Graph &G;

        double temperature;
        double coolingFactor;
        double L;
        double epsilon;
        double beta;

        Solution initialSolution;
        Solution currentSolution;
        Solution bestSolution;

        std::string status;
        std::string getStatus();

        double calculateCost(Solution s);

        double calculateBatch(double T);

        Solution sweepSolution(Solution s);

    public:
        Heuristic(const Graph &G,
                  Solution initialSolution,
                  double initialTemperature,
                  double coolingFactor,
		  double L,
                  double epsilon,
		  double beta);

        void thresholdAcceptance();
        
        Solution getCurrentSolution();
        Solution getBestSolution();

        std::string printBestSolution();
        std::string printStatus();
        std::string printBestCost();
        std::string printBestSolutionSVG();
};
