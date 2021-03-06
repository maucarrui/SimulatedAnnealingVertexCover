#include "gtest/gtest.h"
#include <string>

#ifndef VERTEX_H
#define VERTEX_H
#include "../../src/Vertex.hpp"
#endif

#ifndef GRAPH_H
#define GRAPH_H
#include "../../src/Graph.hpp"
#endif

class GraphTest : public ::testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};

TEST_F(GraphTest, constructor) {
    Graph G = Graph();

    EXPECT_EQ(0, G.getNumVertices());
    EXPECT_EQ(0, G.getNumEdges());
}

TEST_F(GraphTest, addVertex) {
    Graph G = Graph();

    EXPECT_EQ(0, G.getNumVertices());
    
    G.addVertex(Vertex(0, 0, 0, "test"));
    
    EXPECT_EQ(1, G.getNumVertices());

    for (int i = 0; i < 10; i++) {
        G.addVertex(Vertex(i, i, i, "test" + std::to_string(i)));
	
	EXPECT_EQ(i + 2, G.getNumVertices());
    }
}

TEST_F(GraphTest, addEdge) {
    Graph G = Graph();

    EXPECT_EQ(0, G.getNumEdges());
    
    G.addVertex(Vertex(0, 0, 0, "test"));

    for (int i = 0; i < 10; i++)
        G.addVertex(Vertex(i, i, i, "test" + std::to_string(i)));

    G.buildAdjMatrix();

    int numEdges = 0;
    for (int i = 0; i < 10; i ++) {
        for (int j = i + 1; j < 10; j++) {
	    G.addEdge(i, j);
	    numEdges++;
	    EXPECT_EQ(numEdges, G.getNumEdges());
	}
    }
}

TEST_F(GraphTest, buildAdjMatrix) {
    Graph G = Graph();

    EXPECT_EQ(0, G.getNumVertices());
    EXPECT_EQ(0, G.getNumEdges());
    
    G.addVertex(Vertex(0, 0, 0, "test1"));
    
    EXPECT_EQ(1, G.getNumVertices());

    for (int i = 0; i < 10; i++) {
        G.addVertex(Vertex(i, i, i, "test" + std::to_string(i)));
	
	EXPECT_EQ(i + 2, G.getNumVertices());
    }

    G.buildAdjMatrix();

    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
	    if ( (i % 2 == 0) && (j % 2 == 0) )
	        G.addEdge(i, j);
	    else if ( (i % 2 == 1) && (j % 2 == 1) )
	        G.addEdge(i, j);
	}
    }

    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
	    if ( (i % 2 == 0) && (j % 2 == 0) ) {
	        EXPECT_TRUE(G.existsEdge(i, j));
		EXPECT_TRUE(G.existsEdge(j, i));
	    }
	    else if ( (i % 2 == 1) && (j % 2 == 1) ) {
	        EXPECT_TRUE(G.existsEdge(i, j));
	        EXPECT_TRUE(G.existsEdge(j, i));
	    }
	    else {
	        EXPECT_FALSE(G.existsEdge(i, j));
	        EXPECT_FALSE(G.existsEdge(j, i));
	    }
	}
    }    
}

TEST_F(GraphTest, numCoveredEdges) {
    std::vector<bool> cover;

    Graph G = Graph();

    G.addVertex(Vertex(0, 0, 0, "A"));
    G.addVertex(Vertex(1, 0, 1, "B"));
    G.addVertex(Vertex(2, 1, 1, "C"));
    G.addVertex(Vertex(3, 1, 0, "D"));

    G.buildAdjMatrix();

    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(2, 3);

    Solution sx = Solution(G.getNumVertices());
    
    EXPECT_EQ(0, G.numCoveredEdges(sx));

    Solution sy = sx.generateNeighbor();

    EXPECT_EQ(2, G.numCoveredEdges(sy));

    for (int i = 0; i < 4; i++) {
        if (i == 0 || i == 1)
            cover.push_back(true);
        else
            cover.push_back(false);
    }

    Solution sz = Solution(cover, 2);

    EXPECT_EQ(3, G.numCoveredEdges(sz));

    Solution sw = Solution(G.getNumVertices());
    
    cover = sw.getCover();
    
    cover[1] = true;
    cover[3] = true;
    
    sw = Solution(cover, 2);

    EXPECT_EQ(4, G.numCoveredEdges(sw));
}

TEST_F(GraphTest, isFeasibleCover) {
    std::vector<bool> cover;

    Graph G = Graph();

    G.addVertex(Vertex(0, 0, 0, "A"));
    G.addVertex(Vertex(1, 0, 1, "B"));
    G.addVertex(Vertex(2, 1, 1, "C"));
    G.addVertex(Vertex(3, 1, 0, "D"));

    G.buildAdjMatrix();

    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(2, 3);

    Solution sx = Solution(G.getNumVertices());
    
    EXPECT_FALSE(G.isFeasibleCover(sx));

    Solution sy = sx.generateNeighbor();

    EXPECT_FALSE(G.isFeasibleCover(sy));

    for (int i = 0; i < 4; i++) {
        if (i == 0 || i == 1)
            cover.push_back(true);
        else
            cover.push_back(false);
    }

    Solution sz = Solution(cover, 2);

    EXPECT_FALSE(G.isFeasibleCover(sz));

    Solution sw = Solution(G.getNumVertices());
    
    cover = sw.getCover();
    
    cover[1] = true;
    cover[3] = true;
    
    sw = Solution(cover, 2);

    EXPECT_TRUE(G.isFeasibleCover(sw));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
