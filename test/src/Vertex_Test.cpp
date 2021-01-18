#include "gtest/gtest.h"
#include <string>

#ifndef VERTEX_H
#define VERTEX_H
#include "../../src/Vertex.hpp"
#endif

class VertexTest : public ::testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};

TEST_F(VertexTest, getID) {
    for (int i = 0; i < 20; i++) {
        Vertex v = Vertex(i, 0, 0, "test");
	EXPECT_EQ(i, v.getID());
    }
}

TEST_F(VertexTest, getX) {
    for (int i = 0; i < 20; i++) {
        Vertex v = Vertex(0, i, 0, "test");
	EXPECT_EQ(i, v.getX());
    }
}

TEST_F(VertexTest, getY) {
    for (int i = 0; i < 20; i++) {
        Vertex v = Vertex(0, 0, i, "test");
	EXPECT_EQ(i, v.getY());
    }
}

TEST_F(VertexTest, getName) {
    for (int i = 0; i < 20; i++) {
        Vertex v = Vertex(0, 0, 0, "test" + std::to_string(i));
	EXPECT_EQ("test" + std::to_string(i), v.getName());
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
