#pragma once

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class Betweenness {
  public:
    Betweenness(const std::vector<Node*> nodes, const Adjlist adjs_);
    void calculateBetweenness();
    void shortestPathCalculation(Node* node);
    std::map<Node*, double> getbetweennesses();
    double getbetweenness(Node*);
    void Brandes(Node* node);

  private:
    std::map<Node*, double> betweennesses_;
    std::map<Node*, std::vector<Node*>> predecessors_;
    std::map<Node*, double> sigma_;
    std::stack<Node*> node_stack_;
    Adjlist adjs_;
    std::vector<Node*> nodes_;
};