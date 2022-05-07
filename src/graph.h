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
    /**
     * Default Graph constructor
     * */
    Graph();

    /**
     * Graph constructor given nodes and edges
     *
     * @param edges AdjList of edges
     * @param nodes vector of Nodes
     * */
    Graph(AdjList edges, std::vector<Node> nodes);

    /**
     * Graph constructor given filename and number of nodes
     *
     * @param filename name of file to analyze as a string
     * @param nodes number of nodes to analyze
     * */
    Graph(std::string filename, size_t num_nodes);

    /**
     * Getter function for the adjacency list
     *
     * @returns AdjList of the edges of the parsed graph
     **/
    AdjList get_edges() const;

    /**
     * Function to help verify if parsing is done correctly
     *
     * @returns string that contains the starting nodes and the nodes that it is connected to
     */
    std::string verify_parse() const;

    /**
     * DFS traversal method
     */
    void traverse(std::string name);

    /**
     * Function to execute the betweeness centrality algorithm
     *
     * @param name name of the file created after betweenness centrality analysis
     *
     * @returns map from each node pointer to its corresponding betweenness centrality score
     **/
    std::map<Node*, double> betweenness_centrality(std::string name);

    /**
     * Function to execute the page rank algorithm
     *
     * @param name name of the file created after page rank analysis
     **/
    void page_rank(std::string name);

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

    /**
     * Helper function to compare betweenness centrality scores when sorting
     *
     * @param node1 first node to compare
     * @param node2 second node to compare
     *
     * @returns if node1 is greater than node2
     **/
    static bool compare_betweenness(const Node node1, const Node node2);

    /**
     * Helper function to compare page rank scores when sorting
     *
     * @param node1 first node to compare
     * @param node2 second node to compare
     *
     * @returns if node1 is greater than node2
     **/
    static bool compare_probabilities(const Node node1, const Node node2);
};