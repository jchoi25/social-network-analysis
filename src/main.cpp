#include <iostream>

#include "betweenness.h"
#include "dfs.h"
#include "graph.h"
#include "node.h"
#include "pagerank.h"

int main(int argc, char** argv) {
    std::string file = "dataset/sample-data/one-connected.txt";
    Graph g(file, 7);
    g.traversal("sample.txt");
    return 0;
}