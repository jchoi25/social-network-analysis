#include "betweenness.h"

Betweenness::Betweenness(const Adjlist adjs) {
    adjs_ = adjs;
    betweennesses_.clear();
    betweennesses_.resize(adjs_.size());
    calculateBetweenness();
}

void Betweenness::calculateBetweenness() {
    for (unsigned i = 0; i < adjs_.size(); ++i) {
        if (adjs_[i].empty()) {
            betweennesses_[i] = 0;
            continue;
        }
        std::queue<unsigned> q;
        std::vector<bool> visited(adjs_.size());
        std::vector<unsigned> backtrace(adjs_.size());
        for (unsigned n = 0; n < backtrace.size(); ++n) {
            backtrace[n] = -1;
        }
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
                if (b >= 0 && b < betweennesses_.size()) {
                    betweennesses_[b] += 1.0;
                }
            }
        }
    }

    double total = 0;
    for (unsigned c = 0; c < betweennesses_.size(); ++c) {
        total = total + betweennesses_[c];
    }

    if (total != 0) {
        for (unsigned j = 0; j < betweennesses_.size(); ++j) {
            double temp = betweennesses_[j];
            betweennesses_[j] = temp / total;
        }
    }
}

std::vector<double> Betweenness::getbetweennesses() {
    return betweennesses_;
}

double Betweenness::getbetweenness(Node* node) {
    unsigned idx = node->get_id();
    return betweennesses_[idx];
}
