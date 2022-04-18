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

void Graph::traversal(std::string name) {
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
    unsigned from, to;
    if (ifs.is_open()) {
        while (getline(ifs, edge)) {
            // if line is not a comment
            if (edge[0] != '#') {
                std::istringstream iss;
                iss.str(edge);
                iss >> from;
                iss >> to;
                if (from < num_nodes_ && to < num_nodes_) {
                    edges_[from].push_back(&nodes_[to]);
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

std::string Graph::output_edges() const {
    std::string output;
    return output;
}