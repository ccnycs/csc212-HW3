#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <random>
#include <experimental/random>

#include <gtest/gtest.h>
#include "node.h"
#include "llist.h"

class NodeTest : public testing::Test{
  void SetUp(){srand(NULL);}
};

TEST_F (NodeTest, CheckAssignment){ 
  nodespace::node A(std::experimental::randint(10, 20), NULL);
  nodespace::node::value_type expected = std::experimental::randint(30, 50);
  A = expected;
  ASSERT_EQ(expected, A.data());
}

class LListTest : public testing::Test{

};

// ------
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
