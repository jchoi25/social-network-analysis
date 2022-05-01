#include "shortestpath.h"

Shortestpath::Shortestpath(Nodeslist nodes, Adjlist adjs) {
    nodes_ = nodes;
    adjs_ = adjs;
}

std::vector<Node*> Shortestpath::findshortestpath(Node* s, Node* t) {
    std::queue<unsigned> q;
    std::vector<bool> visited(nodes_.size());
    std::vector<unsigned> backtrace(nodes_.size());
    unsigned idx = s->get_id();
    q.push(idx);
    visited[idx] = true;
    while (!q.empty()) {
        unsigned temp = q.front();
        q.pop();
        if (temp == t->get_id()) {
            break;
        }
        for (Node* node : adjs_[temp]) {
            unsigned id = node->get_id();
            if (!visited[id]) {
                q.push(id);
                visited[id] = true;
                backtrace[id] = temp;
            }
        }
    }
    unsigned id = t->get_id();
    std::vector<Node*> shortestpath;
    while (id != s->get_id()) {
        shortestpath.push_back(nodes_[id]);
        id = backtrace[id];
    }
    shortestpath.push_back(s);
    std::reverse(shortestpath.begin(), shortestpath.end());

    return shortestpath;
}