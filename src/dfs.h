#pragma once

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "node.h"

typedef std::vector<std::vector<Node*>> Adjlist;

class DFS {
  public:
    DFS(Adjlist& edges, std::vector<Node>& nodes);
    class Iterator : std::iterator<std::forward_iterator_tag, Node> {
      public:
        Iterator(unsigned index, std::vector<Node*> order);
        Iterator operator++();
        bool operator!=(const Iterator& other);
        Node* operator*() const;

      private:
        unsigned index_;
        std::vector<Node*> traversal_order_;
    };

    Iterator begin();
    Iterator end();

  private:
    void makeorder(Adjlist& edges, std::vector<Node>& nodes);
    std::vector<Node*> traversal_order_;
};
