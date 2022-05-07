#pragma once
#include <iostream>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class Pagerank {
  public:
    /**
     * Constructor given adjacent lists
     *
     * @param adjs is the vector including adjacent lists of each node. Index of this vector is matched with the ID of the Node.
     *
     **/
    Pagerank(Adjlist adjs);

    /**
     * Function to update the probabilities of each node
     **/
    void update_probabilities();

    /**
     * Function to get probabilities
     *
     * @return the vector including all probabilities of nodes
     **/
    std::vector<double> get_probabilities();

    /**
     * Function to get the node with highest rank
     *
     * @return the vector of nodes that are on the highest rank
     **/
    std::vector<unsigned> get_highest_rank();

    /**
     * Function to get the node with lowest rank
     *
     * @return the vector of nodes that are on teh lowest rank
     **/
    std::vector<unsigned> get_lowest_rank();

  private:
    Adjlist adjs_;
    unsigned num_nodes;
    std::vector<double> probabilities;
};