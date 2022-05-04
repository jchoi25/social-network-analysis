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
    Betweenness(const std::vector<Node>& nodes, const Adjlist& adjs_);
    std::map<Node*, double> calculate_betweenness();
    void shortest_path_calculation(Node* node);
    std::map<Node*, double> get_betweennesses();
    double get_betweenness(Node*);
    void brandes(Node* node);

  private:
    std::map<Node*, double> betweennesses_;
    std::map<Node*, std::vector<Node*>> predecessors_;
    std::map<Node*, double> sigma_;
    std::stack<Node*> node_stack_;
    Adjlist adjs_;
    std::vector<Node> nodes_;
};