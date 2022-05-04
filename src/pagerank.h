#pragma once
#include <iostream>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class pagerank {
  public:
    pagerank(Adjlist adjs);
    void updateprobabilities();
    std::vector<double> get_probabilities();
    std::vector<unsigned> get_highest_rank();  // function for test
    std::vector<unsigned> get_lowest_rank();   // function for test

  private:
    Adjlist adjs_;
    unsigned num_nodes;
    std::vector<double> probabilities;
};