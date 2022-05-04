#include "graph.h"

Graph::Graph() : num_nodes_(0) {}

Graph::Graph(AdjList edges, std::vector<Node> nodes) {
    edges_ = edges;
    nodes_ = nodes;
    num_nodes_ = nodes_.size();
}

Graph::Graph(std::string filename, size_t num_nodes) {
    num_nodes_ = num_nodes;
    create_nodes();
    parse_nodes(filename);
}

void Graph::traverse(std::string name) {
    DFS dfs(edges_, nodes_);
    // Output to file
    std::ofstream ofs;
    ofs.open("output/" + name);
    for (auto it = dfs.begin(); it != dfs.end(); ++it) {
        ofs << (*it)->get_id() << std::endl;
    }
    ofs << "Graph of " << std::to_string(num_nodes_) << " nodes traversed" << std::endl;
    ofs.close();
}

void Graph::create_nodes() {
    nodes_.resize(num_nodes_, NULL);
    for (size_t i = 0; i < num_nodes_; i++) {
        nodes_[i] = Node(i);
    }
}

void Graph::parse_nodes(std::string filename) {
    // Checking if file is exists.
    std::ifstream ifs(filename);
    edges_.resize(num_nodes_);
    std::string edge;
    unsigned one, two;
    if (ifs.is_open()) {
        while (getline(ifs, edge)) {
            // if line is not a comment
            if (edge[0] != '#') {
                std::istringstream iss;
                iss.str(edge);
                iss >> one >> two;
                if (one < num_nodes_ && two < num_nodes_) {
                    edges_[one].push_back(&nodes_[two]);
                }
            }
        }
    } else {
        throw std::invalid_argument(filename + " does not exist");
    }
}

AdjList Graph::get_edges() const {
    return edges_;
}

std::string Graph::verify_parse() const {
    std::string out;
    for (unsigned i = 0; i < num_nodes_; ++i) {
        out += "From node " + std::to_string(i) + ": " + std::to_string(i);
        for (auto node : edges_[i]) {
            out += " -> " + std::to_string(node->get_id());
        }
        out += "\n";
    }
    return out;
}

std::map<Node*, double> Graph::betweenness_centrality(std::string name) {
    Betweenness b(nodes_, edges_);
    std::map<Node*, double> betweenness = b.calculate_betweenness();

    // sort
    std::vector<Node> sorted_nodes = nodes_;
    std::sort(sorted_nodes.begin(), sorted_nodes.end(), Graph::compare_betweenness);

    // save to file
    std::ofstream myfile;
    myfile.open("output/betweenness/" + name + ".txt");
    myfile << "Betweenness Score for " << std::to_string(num_nodes_) << " nodes:" << std::endl;

    for (unsigned i = 0; i < num_nodes_; i++) {
        nodes_[sorted_nodes[i].get_id()].set_betweenness_rank(i + 1);
        myfile << "Node " << std::to_string(sorted_nodes[i].get_id()) << " -> " << std::to_string(sorted_nodes[i].get_betweenness()) << std::endl;
    }
    myfile.close();
    return betweenness;
}

bool Graph::compare_betweenness(const Node node1, const Node node2) {
    return (node1.get_betweenness() > node2.get_betweenness());
}