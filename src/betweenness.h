#pragma once

#include <map>
#include <queue>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class Betweenness {
  public:
    Betweenness(const Adjlist adjs_);
    void calculateBetweenness();

  private:
    std::vector<unsigned> betweennesses_;
    Adjlist adjs_;
};