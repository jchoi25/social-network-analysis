#include "betweenness.h"

Betweenness::Betweenness(const Adjlist adjs) {
    adjs_ = adjs;
    betweennesses_.clear();
    betweennesses_.resize(adjs_.size());
    calculateBetweenness();
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
    for (unsigned c = 0; c < betweennesses_.size(); ++c) {
        total = total + betweennesses_[c];
    }

    for (unsigned j = 0; j < betweennesses_.size(); ++j) {
        unsigned temp = betweennesses_[j];
        betweennesses_[j] = temp / total;
    }
}

std::vector<unsigned> Betweenness::getbetweennesses() {
    return betweennesses_;
}

unsigned Betweenness::getbetweenness(Node* node) {
    unsigned idx = node->get_id();
    return betweennesses_[idx];
}
