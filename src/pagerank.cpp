#include "pagerank.h"

pagerank::pagerank(Adjlist adjs) {
    adjs_ = adjs;
    num_nodes = adjs_.size();
    probabilities.resize(num_nodes);
}

void pagerank::updateprobabilities() {
    unsigned defaultvalue = 1 / num_nodes;
    for (unsigned i = 0; i < adjs_.size(); ++i) {
        unsigned total = 0;
        for (Node* temp : adjs_[i]) {
            unsigned idx = temp->get_id();
            unsigned factor = adjs_[idx].size();
            total += defaultvalue / factor;
        }
        probabilities[i] = total;
    }
}

std::vector<unsigned> pagerank::get_probabilities() {
    return probabilities;
}
