#include <vector>
#include <random>

class Solution {
    private:
        std::vector<bool> cover;
        int _size;
        double cost;

    public:
        Solution();
        Solution(int numVertices);
        Solution(std::vector<bool> _cover, int _size);

        void shuffle();

        int size();

        std::vector<bool> getCover();
        
        Solution generateNeighbor();

        void   setCost(double cost);
        double getCost();
};
