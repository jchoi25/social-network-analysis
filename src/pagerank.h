#pragma once
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class pagerank {
  public:
    pagerank(Adjlist adjs);
    void updateprobabilities();
    std::vector<unsigned> get_probabilities();

  private:
    Adjlist adjs_;
    unsigned num_nodes;
    std::vector<unsigned> probabilities;
};