#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "betweenness.h"
#include "dfs.h"
#include "node.h"
#include "pagerank.h"

typedef std::vector<std::vector<Node*>> AdjList;

class Graph {
  public:
    Graph();

    Graph(AdjList edges, std::vector<Node> nodes);

    Graph(std::string filename, size_t num_nodes);

    /**
     * DFS traversal method
     */
    void traversal(std::string name);

    /**
     * Method that will return a string of the adjacency list.
     */
    std::string output_edges() const;

    AdjList get_edges() const;

  private:
    unsigned num_nodes_;
    AdjList edges_;
    std::vector<Node> nodes_;
    void create_nodes();
    void parse_nodes(std::string filename);
};