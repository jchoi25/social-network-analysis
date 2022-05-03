#include "pagerank.h"

pagerank::pagerank(Adjlist adjs) {
    adjs_ = adjs;
    num_nodes = adjs_.size();
    probabilities.resize(num_nodes);
    updateprobabilities();
}

void pagerank::updateprobabilities() {
    double defaultvalue = 1.00 / num_nodes;

    for (unsigned i = 0; i < adjs_.size(); ++i) {
        double total = 0;
        for (Node* temp : adjs_[i]) {
            unsigned idx = temp->get_id();
            double factor = adjs_[idx].size();
            total += defaultvalue / factor;
        }
        probabilities[i] = total;
    }
}

std::vector<double> pagerank::get_probabilities() {
    return probabilities;
}

std::vector<unsigned> pagerank::get_highest_rank() {
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

std::vector<unsigned> pagerank::get_lowest_rank() {
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