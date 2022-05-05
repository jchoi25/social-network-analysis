#include <exception>
#include <iostream>

#include "betweenness.h"
#include "dfs.h"
#include "graph.h"
#include "node.h"
#include "pagerank.h"

int main(int argc, char** argv) {
    try {
        std::string filename = argv[1];
        std::stringstream num_nodes(argv[2]);
        int n = 0;
        num_nodes >> n;
        std::string name = argv[3];
        Graph graph(filename, n);
        graph.traverse(name);
        graph.page_rank(name);
        graph.betweenness_centrality(name);
    } catch (std::exception& e) {
        std::cout << "Encountered error: " << e.what() << std::endl;
        std::cout << "Please enter: 1.File path  2.Number of Nodes  3.Name of output (without extension)" << std::endl;
    }
    return 0;
}