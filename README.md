# CS 225 Final Project Repo for SIG

## Project Description
The goal of this project is to analyze a social media network, given a node-edge dataset. Specifically, we wanted to find a profile (node) with the most connections (edges) with other profiles in a given network graph...

[Project Proposal](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2) | 
[Project Presentation Video](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2) | 
[results.md](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2)

## Deliverables 
- [Code](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2/tree/main/src)
- [Data](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2/blob/main/dataset)
- [Tests](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2/tree/main/tests)

## Running Instructions 
### Test Suite
```bash
make tests
```
#### Available Arguments for Tests
- `parse` tests with all sample datasets
- `dfs` tests with all sample datasets
- `betweenness`
- `pagerank`

### Running Tests with Argument Example
```bash
make tests [parse]
```

#### Sample Datasets used for Tests
- Simple one connected component undirected graph '[one-connected.txt](dataset/sample-data/one-connected.txt)' (7 Nodes, 14 Edges)
- Simple two connected component undirected graph '[two-connected.txt](dataset/sample-data/two-connected.txt)' (8 Nodes, 14 Edges)
- One connected component undirected graph with many nodes '[one-connected-many-nodes.txt](dataset/sample-data/one-connected-many-nodes.txt)' (50 Nodes, 98 Edges)
- Simple undirected graph with one node disconnected '[one-node-disconnected.txt](dataset/sample-data/one-node-disconnected.txt)' (7 Nodes, 13 Edges)
- Simple Disconnected Components undirected graph '[many-disconnected.txt](dataset/sample-data/many-disconnected.txt)' (9 Nodes, 2 Edges)
- All nodes disconnected undirected graph '[disconnected-many-nodes.txt](dataset/sample-data/disconnected-many-nodes.txt)' (100 Nodes, 0 Edges)

