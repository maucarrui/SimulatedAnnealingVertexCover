#include "gtest/gtest.h"
#include <string>

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
    
    G.addVertex(0, 0, 0, "test1");
    
    EXPECT_EQ(1, G.getNumVertices());

    for (int i = 0; i < 10; i++) {
        G.addVertex(i, i, i, "test" + std::to_string(i));
	
	EXPECT_EQ(i + 1, G.getNumVertices());
    }
}

TEST_F(GraphTest, addEdge) {
    Graph G = Graph();

    EXPECT_EQ(0, G.getNumEdges());
    
    G.addVertex(0, 0, 0, "test1");

    for (int i = 0; i < 10; i++)
        G.addVertex(i, i, i, "test" + std::to_string(i));

    G.buildAjdMatrix();

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
    
    G.addVertex(0, 0, 0, "test1");
    
    EXPECT_EQ(1, G.getNumVertices());

    for (int i = 0; i < 10; i++) {
        G.addVertex(i, i, i, "test" + std::to_string(i));
	
	EXPECT_EQ(i + 1, G.getNumVertices());
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
	        EXPECT_FALSE(G.existEdge(i, j));
	        EXPECT_FALSE(G.existEdge(j, i));
	    }
	}
    }    
}
