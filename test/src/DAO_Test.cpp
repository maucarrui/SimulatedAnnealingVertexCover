#include "gtest/gtest.h"
#include <string>
#include <vector>

#ifndef DAO_H
#define DAO_H
#include "../../src/DAO.hpp"
#endif

#ifndef VERTEX_H
#define VERTEX_H
#include "../../src/Vertex.hpp"
#endif

class DAOTest : public ::testing::Test {
    protected:
        virtual void setUp() {
	}
        
        virtual void TearDown() {
	}
};

TEST_F(DAOTest, getVertexByID) {
    DAO dao = DAO("../sql/CANADA.db");
    dao.openDB();

    Vertex test1 = dao.getVertexByID(4);
    Vertex test2 = dao.getVertexByID(8);
    Vertex test3 = dao.getVertexByID(10);

    EXPECT_EQ(test1.getID(), 4);
    EXPECT_EQ(test1.getX(), 141);
    EXPECT_EQ(test1.getY(), 816);
    EXPECT_EQ(test1.getName(), "British Columbia");

    EXPECT_EQ(test2.getID(), 8);
    EXPECT_EQ(test2.getX(), 699);
    EXPECT_EQ(test2.getY(), 990);
    EXPECT_EQ(test2.getName(), "Ontario");

    EXPECT_EQ(test3.getID(), 10);
    EXPECT_EQ(test3.getX(), 1092);
    EXPECT_EQ(test3.getY(), 887);
    EXPECT_EQ(test3.getName(), "New Foundland and Labrador");

    dao.closeDB();
}

TEST_F(DAOTest, getVertices) {
    DAO dao = DAO("../sql/CANADA.db");
    dao.openDB();

    std::vector<Vertex> vertices = dao.getVertices();
    
    EXPECT_EQ(13, vertices.size());

    dao.closeDB();
}

TEST_F(DAOTest, getEdges) {
    DAO dao = DAO("../sql/CANADA.db");
    dao.openDB();

    std::vector<std::pair<int, int>> edges = dao.getEdges();
    
    EXPECT_EQ(15, edges.size());

    dao.closeDB();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
