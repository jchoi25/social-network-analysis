#include "dfs.h"

DFS::DFS(Adjlist& edges, std::vector<Node>& nodes) {
    makeorder(edges, nodes);
}

void DFS::makeorder(Adjlist& edges, std::vector<Node>& nodes) {  // create order for iteration
    std::vector<bool> visited(nodes.size());                     // vector to check whether that vertex is visited or not.
    for (unsigned i = 0; i < nodes.size(); ++i) {
        if (!visited[i]) {
            std::stack<int> stack;  // stack for later visit
            stack.push(i);
            visited[i] = true;
            while (!stack.empty()) {
                int nextid = stack.top();
                stack.pop();
                traversal_order_.push_back(&nodes[nextid]);
                for (unsigned j = 0; j < edges[nextid].size(); ++j) {
                    int adjid = edges[nextid][j]->getId();  // get adjacent's Id from the vector
                    if (!visited[adjid]) {
                        visited[adjid] = true;
                        stack.push(adjid);
                    }
                }
            }
        }
    }
}

DFS::Iterator::Iterator(unsigned index, std::vector<Node*> traversal_order) : index_(index), traversal_order_(traversal_order) {
}

DFS::Iterator DFS::Iterator::operator++() {
    ++index_;
    return *this;
}

bool DFS::Iterator::operator!=(const Iterator& other) {
    return *(*this) != *other;
}

Node* DFS::Iterator::operator*() const {
    if (index_ >= traversal_order_.size()) {
        return nullptr;
    }
    return traversal_order_[index_];
}

DFS::Iterator DFS::begin() {
    return DFS::Iterator(0, traversal_order_);
}

DFS::Iterator DFS::end() {
    return DFS::Iterator(traversal_order_.size(), traversal_order_);
}