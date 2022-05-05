#include "pagerank.h"

Pagerank::Pagerank(Adjlist adjs) {
    adjs_ = adjs;
    num_nodes = adjs_.size();
    probabilities.resize(num_nodes);
    update_probabilities();
}

void Pagerank::update_probabilities() {
    double defaultvalue = 1.00 / num_nodes;

    for (unsigned i = 0; i < adjs_.size(); ++i) {
        double total = 0;
        for (Node* temp : adjs_[i]) {
            unsigned idx = temp->get_id();
            if (adjs_[idx].size() != 0) {
                double factor = adjs_[idx].size();
                total += defaultvalue / factor;
            }
        }
        probabilities[i] = total;
    }
}

std::vector<double> Pagerank::get_probabilities() {
    return probabilities;
}

std::vector<unsigned> Pagerank::get_highest_rank() {
    double highest = 0;
    for (unsigned i = 0; i < probabilities.size(); ++i) {
        if (probabilities[i] > probabilities[highest]) {
            highest = i;
        }
    }

    std::vector<unsigned> highests;
    for (unsigned i = 0; i < probabilities.size(); ++i) {
        if (probabilities[i] == probabilities[highest]) {
            highests.push_back(i);
        }
    }

    return highests;
}

std::vector<unsigned> Pagerank::get_lowest_rank() {
    double lowest = 0;
    for (unsigned i = 0; i < probabilities.size(); ++i) {
        if (probabilities[i] < probabilities[lowest]) {
            lowest = i;
        }
    }
    std::vector<unsigned> lowests;
    for (unsigned i = 0; i < probabilities.size(); ++i) {
        if (probabilities[i] == probabilities[lowest]) {
            lowests.push_back(i);
        }
    }

    return lowests;
}