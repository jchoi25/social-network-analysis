#define CATCH_CONFIG_MAIN

#include "../src/betweenness.h"
//#include "../src/bfs.h"
#include "../src/dfs.h"
#include "../src/graph.h"
#include "../src/node.h"
#include "../src/pagerank.h"
#include "catch.hpp"

using namespace std;

std::string fizzbuzz(int const number) {
    if (number != 0) {
        auto m3 = number % 3;
        auto m5 = number % 5;
        if (!m5 && !m3) {
            return "fizzbuzz";
        } else if (!m5) {
            return "buzz";
        } else if (!m3) {
            return "fizz";
        }
    }
    return std::to_string(number);
}

TEST_CASE("Test positives", "[classic]") {
    SECTION("Test all up to 10") {
        REQUIRE(fizzbuzz(1) == "1");
        REQUIRE(fizzbuzz(2) == "2");
        REQUIRE(fizzbuzz(3) == "fizz");
        REQUIRE(fizzbuzz(4) == "4");
        REQUIRE(fizzbuzz(5) == "buzz");
        REQUIRE(fizzbuzz(6) == "fizz");
        REQUIRE(fizzbuzz(7) == "7");
        REQUIRE(fizzbuzz(8) == "8");
        REQUIRE(fizzbuzz(9) == "fizz");
        REQUIRE(fizzbuzz(10) == "buzz");
    }
}

string readFile(string filename)
{
    ifstream data("output/" + filename);
    string line, output;

    if (data.is_open()) {
        while (getline(data, line))
        {
          output += line + "\n";
        }
    } 
  return output;
}

TEST_CASE("DFS Traversal - Connected Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/one-connected.txt", 7);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/one-connected.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

TEST_CASE("DFS Traversal - Simple Connected Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/two-connected.txt", 8);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/two-connected.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/one-connected-many-nodes.txt", 50);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/one-connected-many-nodes.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

TEST_CASE("DFS Traversal - Simple Disonnected Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/one-node-disconnected.txt", 7);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/one-node-disconnected.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

TEST_CASE("DFS Traversal - Multiple Components Disconnected Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/many-disconnected.txt", 9);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/many-disconnected.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

TEST_CASE("DFS Traversal - All Disonnected Undirected Graph", "[dfs]") {
  Graph g("dataset/sample-data/disconnected-many-nodes.txt", 100);
  g.traversal("test-traversal.txt");
  REQUIRE(readFile("sample-output/disconnected-many-nodes.txt") == readFile("test-traversal.txt"));
  remove("output/test-traversal.txt");
}

