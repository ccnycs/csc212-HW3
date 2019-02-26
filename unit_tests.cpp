#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>

#include <gtest/gtest.h>
#include "node.h"
#include "dnode.h"


class NodeTest : public testing::Test{
  
  public:
    virtual void SetUp()
    {
      init();
    }

    virtual void TearDown()
    {
    }
    
  protected:
    std::vector<nodespace::node*> nodes;
    std::vector<int> values;
    nodespace::node *head;

    void init() 
    {
      int num_nodes = rand() % 20 + 1;
      int val = rand() % 30;
      nodes.push_back(new nodespace::node(val));
      values.push_back(val);
      for (int i = 1; i < num_nodes; i++)
      { 
        val = rand() % 30;
        nodes.push_back( new nodespace::node( val, nodes[i-1]  ) );
        values.push_back(val);
      }
      head = nodes[(size_t)(nodes.size() - 1)];
    }
  
};


TEST_F ( NodeTest, CheckIndexing )
{
  
  for ( int i = 0; i < nodes.size(); i++ )
    ASSERT_EQ( values[nodes.size()-1-i], (*head)[i]->data() );
}

TEST_F (NodeTest, CheckIndexSet)
{
  nodespace::node::value_type ran;
  for ( int i = 0; i < nodes.size(); i++ )
  {
    ran = (nodespace::node::value_type)(rand() % 60 + 30);
    head[i] = ran;
    ASSERT_EQ(ran, head[i].data() );
  }
}


// ------
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
