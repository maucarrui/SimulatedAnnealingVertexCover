#include "gtest/gtest.h"
#include <vector>

#ifndef SOLUTION_H
#define SOLUTION_H
#include "../../src/Solution.hpp"
#endif

class SolutionTest : public ::testing::Test {
    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
};

TEST_F(SolutionTest, constructor1) {
    std::vector<bool> cover;

    Solution s = Solution(5);
    
    EXPECT_EQ(0, s.size());

    cover = s.getCover();

    EXPECT_EQ(5, cover.size());

    for (int i = 0; i < 5; i++)
        EXPECT_FALSE(cover[i]);
}

TEST_F(SolutionTest, constructor2) {
    std::vector<bool> cover;
    
    for (int i = 0; i < 5; i++)
        cover.push_back(true);

    Solution s = Solution(cover, 5);
    
    EXPECT_EQ(5, s.size());
    
    cover = s.getCover();

    EXPECT_EQ(5, cover.size());
    
    for (int i = 0; i < 5; i++)
        EXPECT_TRUE(cover[i]);
}

TEST_F(SolutionTest, size) {
    std::vector<bool> cover;

    for (int i = 0; i < 3; i++)
        cover.push_back(true);
    
    for (int i = 0; i < 2; i++)
        cover.push_back(false);

    Solution s = Solution(cover, 3);

    EXPECT_EQ(3, s.size());

    cover = s.getCover();
    
    EXPECT_EQ(5, cover.size());
}

TEST_F(SolutionTest, getCover) {
    std::vector<bool> cover;

    Solution s = Solution(5);

    cover = s.getCover();

    for (int i = 0; i < 5; i++)
        EXPECT_FALSE(cover[i]);

    cover[0] = true;
    cover[2] = true;
    cover[4] = true;

    s = Solution(cover, 3);

    cover = s.getCover();

    EXPECT_EQ(3, s.size());
    EXPECT_EQ(5, cover.size());

    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 2 || i == 4)
            EXPECT_TRUE(cover[i]);
	else
	    EXPECT_FALSE(cover[i]);
    }
}

TEST_F(SolutionTest, generateNeighbor) {
    Solution sx = Solution(5);
    Solution sy = sx.generateNeighbor();

    bool cond = ((sx.size() == sy.size() - 1) || (sx.size() == sy.size() + 1));

    EXPECT_TRUE(cond);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
