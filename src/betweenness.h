#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class Betweenness {
  public:
    Betweenness(const Adjlist adjs_);
    void calculateBetweenness();
    std::vector<double> getbetweennesses();
    double getbetweenness(Node*);

    std::vector<unsigned> get_highest_rank();
    std::vector<unsigned> get_lowest_rank();

  private:
    std::vector<double> betweennesses_;
    Adjlist adjs_;
};