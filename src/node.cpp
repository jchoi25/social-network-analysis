#include "node.h"

#include <iostream>

Node::Node(int id) {
    id_ = id;
    importance_ = 0;
    betweenness_ = 0;
}

void Node::set_importance(double importance) {
    importance_ = importance;
}

void Node::set_betweenness(double betweenness) {
    betweenness_ = betweenness;
}

void Node::set_importance_rank(unsigned importanceRank) {
    importance_rank_ = importanceRank;
}

void Node::set_betweenness_rank(unsigned betweennessRank) {
    betweenness_rank_ = betweennessRank;
}

void Node::increase_importance() {
    importance_++;
}

void Node::increase_betweenness() {
    betweenness_++;
}

int Node::get_id() const {
    return id_;
}

double Node::get_importance() const {
    return importance_;
}

double Node::get_betweenness() const {
    return betweenness_;
}

unsigned Node::get_importance_rank() const {
    return importance_rank_;
}

unsigned Node::get_betweenness_rank() const {
    return betweenness_rank_;
}