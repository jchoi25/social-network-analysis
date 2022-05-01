#include "betweenness.h"

Betweenness::Betweenness(const Adjlist adjs) {
    adjs_ = adjs;
    betweennesses_.resize(adjs_.size());
    betweennesses_.clear();
}

void Betweenness::calculateBetweenness() {
    for (unsigned i = 0; i < adjs_.size(); ++i) {
        std::queue<unsigned> q;
        std::vector<bool> visited(adjs_.size());
        std::vector<unsigned> backtrace(adjs_.size());
        backtrace[i] = i;
        for (bool v : visited) {
            v = false;
        }
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            unsigned temp = q.front();
            q.pop();
            for (Node* adj : adjs_[temp]) {
                unsigned id = adj->get_id();
                if (!visited[id]) {
                    q.push(id);
                    visited[id] = true;
                    backtrace[id] = temp;
                }
            }
        }
        for (unsigned b : backtrace) {
            if (b != i) {
                betweennesses_[b] += 1;
            }
        }
    }

    unsigned total = 0;
    for (unsigned b2 : betweennesses_) {
        total += b2;
    }

    for (unsigned finalb : betweennesses_) {
        finalb = finalb / total;
    }
}