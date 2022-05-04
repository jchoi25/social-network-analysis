#pragma once
#include <algorithm>
#include <queue>
#include <vector>

#include "node.h"

typedef std::vector<Node*> Nodeslist;
typedef std::vector<std::vector<Node*>> Adjlist;

class Shortestpath {
  public:
    Shortestpath(Nodeslist, Adjlist);
    std::vector<Node*> findshortestpath(Node*, Node*);

  private:
    Nodeslist nodes_;
    Adjlist adjs_;
};