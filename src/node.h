#pragma once

class Node {
  public:
    Node(int id);

    void set_importance(double importance);
    void set_betweenness(double betweenness);
    void set_importance_rank(unsigned importanceRank);
    void set_betweenness_rank(unsigned betweennessRank);

    void increase_importance();
    void increase_betweenness();

    int get_id() const;

    double get_importance() const;
    double get_betweenness() const;

    unsigned get_importance_rank() const;
    unsigned get_betweenness_rank() const;

  private:
    int id_;
    double importance_;
    double betweenness_;

    unsigned importance_rank_;
    unsigned betweenness_rank_;
};
