#pragma once

#include <algorithm>
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
    void traverse(std::string name);

    /**
     * Function to help verify if parsing is done correctly
     *
     * @returns string that contains the starting nodes and the nodes that it is connected to
     */
    std::string verify_parse() const;

    /**
     * Getter function for the adjacency list
     *
     * @returns AdjList of the edges of the parsed graph
     **/
    AdjList get_edges() const;

    std::map<Node*, double> betweenness_centrality(std::string name);
    static bool compare_betweenness(const Node node1, const Node node2);

  private:
    unsigned num_nodes_;
    AdjList edges_;
    std::vector<Node> nodes_;
    /**
     * Function to initialize the graph
     * */
    void create_nodes();
    /**
     * Function to parse the nodes into the graph
     *
     * @param filename The name of the file to parse
     * */
    void parse_nodes(std::string filename);
};