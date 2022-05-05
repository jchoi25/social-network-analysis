#define CATCH_CONFIG_MAIN

#include "../src/betweenness.h"
#include "../src/dfs.h"
#include "../src/graph.h"
#include "../src/node.h"
#include "../src/pagerank.h"
#include "catch.hpp"

using namespace std;

// helper function for testing DFS traversal
string read_file(string filename) {
    ifstream data("output/" + filename);
    string line, output;

    if (data.is_open()) {
        while (getline(data, line)) {
            output += line + "\n";
        }
    }
    return output;
}

/* Parse Graph Tests */

TEST_CASE("Parse Simple Connected Graph", "[parse]") {
    Graph g("dataset/sample-data/one-connected.txt", 7);
    string parsed = g.verify_parse();
    REQUIRE(parsed ==
            "From node 0: 0 -> 1 -> 2 -> 4\n"
            "From node 1: 1 -> 0 -> 3 -> 6\n"
            "From node 2: 2 -> 0 -> 5\n"
            "From node 3: 3 -> 1\n"
            "From node 4: 4 -> 0 -> 5\n"
            "From node 5: 5 -> 2 -> 4\n"
            "From node 6: 6 -> 1\n");
}

TEST_CASE("Parse Two Connected Graph", "[parse]") {
    Graph g("dataset/sample-data/two-connected.txt", 8);
    string parsed = g.verify_parse();
    REQUIRE(parsed ==
            "From node 0: 0 -> 1 -> 7\n"
            "From node 1: 1 -> 0 -> 2\n"
            "From node 2: 2 -> 1\n"
            "From node 3: 3 -> 4 -> 5\n"
            "From node 4: 4 -> 3 -> 5 -> 6\n"
            "From node 5: 5 -> 3 -> 4\n"
            "From node 6: 6 -> 4\n"
            "From node 7: 7 -> 0\n");
}

TEST_CASE("Parse Simple Disconnected Graph", "[parse]") {
    Graph g("dataset/sample-data/one-node-disconnected.txt", 7);
    string parsed = g.verify_parse();
    REQUIRE(parsed ==
            "From node 0: 0 -> 1 -> 6\n"
            "From node 1: 1 -> 0 -> 4\n"
            "From node 2: 2\n"
            "From node 3: 3 -> 4 -> 5\n"
            "From node 4: 4 -> 3 -> 5 -> 6\n"
            "From node 5: 5 -> 3 -> 4\n"
            "From node 6: 6 -> 0 -> 4\n");
}

/* DFS Traversal Tests */

TEST_CASE("DFS Traversal - Connected Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/one-connected.txt", 7);
    g.traverse("test");
    REQUIRE(read_file("sample-output/one-connected.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}

TEST_CASE("DFS Traversal - Simple Connected Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/two-connected.txt", 8);
    g.traverse("test");
    REQUIRE(read_file("sample-output/two-connected.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/one-connected-many-nodes.txt", 50);
    g.traverse("test");
    REQUIRE(read_file("sample-output/one-connected-many-nodes.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}

TEST_CASE("DFS Traversal - Simple Disonnected Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/one-node-disconnected.txt", 7);
    g.traverse("test");
    REQUIRE(read_file("sample-output/one-node-disconnected.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Disconnected Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/many-disconnected.txt", 9);
    g.traverse("test");
    REQUIRE(read_file("sample-output/many-disconnected.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}

TEST_CASE("DFS Traversal - All Disonnected Undirected Graph", "[dfs]") {
    Graph g("dataset/sample-data/disconnected-many-nodes.txt", 100);
    g.traverse("test");
    REQUIRE(read_file("sample-output/disconnected-many-nodes.txt") == read_file("test_traversal.txt"));
    remove("output/test_traversal.txt");
}


/* Betweenness Centrality Test */

TEST_CASE("Betweenness Centrality - Undirected One Component", "[b]") {
    Graph g("dataset/sample-data/one-connected.txt", 7);
    vector<double> expected({19.0, 18.0, 4.0, 0.0, 4.0, 1.0, 0.0});
    auto output = g.betweenness_centrality("test");
    for (auto num : output) {
        REQUIRE(expected[num.first->get_id()] == num.second);
    }
    remove("output/test_betweenness.txt");
}

/* PageRank Test */

TEST_CASE("Page Rank - Connected Graph", "[pagerank]") {
    Graph g("dataset/sample-data/one-connected.txt", 7);
    Pagerank pg = Pagerank(g.get_edges());
    vector<double> expected{0.190476, 0.333333, 0.119048, 0.047619, 0.119048, 0.142857, 0.047619};
    vector<double> probabilities = pg.get_probabilities();
    for (size_t i = 0; i < expected.size(); i++) {
        REQUIRE(expected[i] == Approx(probabilities[i]));
    }
}

// TEST_CASE("Pagerank - Multiple Nodes Connected Graph", "[pagerank]") {
//     Node node0(0);
//     Node node1(1);
//     Node node2(2);
//     Node node3(3);
//     std::vector<Node*> adj0;
//     std::vector<Node*> adj1;
//     std::vector<Node*> adj2;
//     std::vector<Node*> adj3;
//     adj0.push_back(&node1);
//     adj0.push_back(&node2);
//     adj0.push_back(&node3);
//     adj1.push_back(&node0);
//     adj2.push_back(&node0);
//     adj2.push_back(&node1);
//     adj3.push_back(&node0);
//     std::vector<std::vector<Node*>> adjs;
//     std::vector<Node*> nodes;
//     adjs.push_back(adj0);
//     adjs.push_back(adj1);
//     adjs.push_back(adj2);
//     adjs.push_back(adj3);
//     pagerank pr(adjs);
//     std::vector<unsigned> highests{0};
//     std::vector<unsigned> lowests{1, 3};

//     REQUIRE(pr.get_highest_rank() == highests);
//     REQUIRE(pr.get_lowest_rank() == lowests);
// }

// TEST_CASE("pagerank - Multiple Nodes Disconnected Graph", "[pagerank]") {
//     Node node0(0);
//     Node node1(1);
//     Node node2(2);
//     Node node3(3);
//     Node node4(4);
//     Node node5(5);
//     std::vector<Node*> adj0;
//     std::vector<Node*> adj1;
//     std::vector<Node*> adj2;
//     std::vector<Node*> adj3;
//     std::vector<Node*> adj4;
//     std::vector<Node*> adj5;
//     adj0.push_back(&node1);
//     adj0.push_back(&node2);
//     adj1.push_back(&node0);
//     adj2.push_back(&node0);
//     adj3.push_back(&node4);
//     adj3.push_back(&node5);
//     adj4.push_back(&node3);
//     adj5.push_back(&node3);
//     std::vector<std::vector<Node*>> adjs;
//     std::vector<Node*> nodes;
//     adjs.push_back(adj0);
//     adjs.push_back(adj1);
//     adjs.push_back(adj2);
//     adjs.push_back(adj3);
//     adjs.push_back(adj4);
//     adjs.push_back(adj5);
//     pagerank pr(adjs);
//     std::vector<unsigned> highests{0, 3};
//     std::vector<unsigned> lowests{1, 2, 4, 5};

//     REQUIRE(pr.get_highest_rank() == highests);
//     REQUIRE(pr.get_lowest_rank() == lowests);
// }

// TEST_CASE("pagerank - All Nodes Disconnected Graph", "[pagerank]") {
//     Node node0(0);
//     Node node1(1);
//     Node node2(2);
//     Node node3(3);
//     Node node4(4);
//     Node node5(5);
//     std::vector<Node*> adj0;
//     std::vector<Node*> adj1;
//     std::vector<Node*> adj2;
//     std::vector<Node*> adj3;
//     std::vector<Node*> adj4;
//     std::vector<Node*> adj5;
//     std::vector<std::vector<Node*>> adjs;
//     std::vector<Node*> nodes;
//     adjs.push_back(adj0);
//     adjs.push_back(adj1);
//     adjs.push_back(adj2);
//     adjs.push_back(adj3);
//     adjs.push_back(adj4);
//     adjs.push_back(adj5);
//     pagerank pr(adjs);
//     std::vector<unsigned> highests{0, 1, 2, 3, 4, 5};
//     std::vector<unsigned> lowests{0, 1, 2, 3, 4, 5};

//     REQUIRE(pr.get_highest_rank() == highests);
//     REQUIRE(pr.get_lowest_rank() == lowests);
// }

/* Finding Shortest Path using BFS Tests */
