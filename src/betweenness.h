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
    /**
     *Constructor for Betweenness given nodes and adjacent lists
     *
     * @param nodes  is the vector of Nodes
     * @param adjs_ is the vector of adjacent lists of each node. Index of this vector is matched with the ID of the Node.
     *
     **/
    Betweenness(const std::vector<Node>& nodes, const Adjlist& adjs_);

    /**
     * Function to calculate the betweenness using the Brandes Algorithm
     *
     * @return the map including the betweenness scores on each node
     **/
    std::map<Node*, double> calculate_betweenness();

    /**
     * Function to calculate the shortest path using BFS
     *
     * @param node is the start node
     **/
    void shortest_path_calculation(Node* node);

    /**
     * Function to get betweenness scores again after the caculation
     *
     * @return the map including the betweenness scores on each node
     **/
    std::map<Node*, double> get_betweennesses();

    /**
     * Function to get betweenness score of certain node
     *
     * @param node is the node to get the betweennness score
     *
     * @return the betweenness score in double type
     **/
    double get_betweenness(Node* node);

    /**
     * Function to perform Brandes' algorithm
     *
     * @param node is the node to calculate betweenness score
     **/
    void brandes(Node* node);

  private:
    std::map<Node*, double> betweennesses_;
    std::map<Node*, std::vector<Node*>> predecessors_;
    std::map<Node*, double> sigma_;
    std::stack<Node*> node_stack_;
    Adjlist adjs_;
    std::vector<Node> nodes_;
};