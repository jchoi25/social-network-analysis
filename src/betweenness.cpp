#include "betweenness.h"

Betweenness::Betweenness(const std::vector<Node*> nodes, const Adjlist adjs) {
    adjs_ = adjs;
    nodes_ = nodes;
    betweennesses_.clear();
    // calculateBetweenness();
}

void Betweenness::shortestPathCalculation(Node* node) {
    predecessors_.clear();
    sigma_.clear();
    std::map<unsigned, unsigned> dist;
    sigma_[node] = 1.0;
    std::queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* v = q.front();
        q.pop();
        node_stack_.push(v);
        unsigned distV = dist[v->get_id()];
        double sigmaV = sigma_[v];

        for (Node* w : adjs_[v->get_id()]) {
            if (!dist.count(w->get_id())) {
                q.push(w);
                dist[w->get_id()] = distV + 1;
            }

            if (dist[w->get_id()] == distV + 1) {
                sigma_[w] = sigma_[w] + sigmaV;
                predecessors_[w].push_back(v);
            }
        }
    }
}

void Betweenness::Brandes(Node* node) {
    std::map<Node*, double> delta;
    while (!node_stack_.empty()) {
        Node* w = node_stack_.top();
        node_stack_.pop();

        double coef = (1 + delta[w]) / sigma_[w];

        for (Node* v : predecessors_[w]) {
            delta[v] = delta[v] + sigma_[v] * coef;
        }
        if (w != node) {
            betweennesses_[w] = betweennesses_[w] + delta[w];
        }
    }
}

void Betweenness::calculateBetweenness() {
    for (Node* node : nodes_) {
        shortestPathCalculation(node);
        Brandes(node);
    }
}

std::map<Node*, double> Betweenness::getbetweennesses() {
    return betweennesses_;
}

double Betweenness::getbetweenness(Node* node) {
    return betweennesses_[node];
}
