#pragma once

class Node {

    public:
        Node(int id);

        void setImportance(double importance);
        void setBetweenness(double betweenness);
        void setImportanceRank(unsigned importanceRank);
        void setBetweennessRank(unsigned betweennessRank);

        /*
        void increaseImportance()
        void increaseBetweenness()
        */

        int getId() const;
        
        double getImportance() const;
        double getBetweenness() const;

        unsigned getImportanceRank() const;
        unsigned getBetweennessRank() const;

    private:
        int id_;
        double importance_;
        double betweenness_;

        unsigned importanceRank_;
        unsigned betweennessRank_;
};

