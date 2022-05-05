# CS 225 Final Project Repo for SIG

## Project Description
The goal of this project is to analyze a social media network, given a node-edge dataset. Specifically, we wanted to find a profile (node) with the most connections (edges) with other profiles in a given network graph...

[Project Proposal](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2) | 
[Project Presentation Video](https://github-dev.cs.illinois.edu/cs225-sp22/slee677-juyoung7-soohar2) | 
[results.md](TeamDocs/results.md)

## Deliverables 
- [Code](src)
- [Data](dataset)
- [Tests](tests)
- [Results](output)

## Running Instructions 

### Prerequisites
- Ensure that you are in the root directory.

### Main
```bash
make
```
```bash
make main
./main [input_dataset_path] [number_of_nodes] [output_file_name]
```

#### Run Facebook Network Analysis
<code>./main dataset/facebook_combined.txt 4039 [output_file_name]</code>
<br>
Output file will be located in [output](output) directory with the name inputted.

### Test Suite
```bash
make tests
```
#### Available Arguments for Tests
- `parse` tests with all sample datasets
- `dfs` tests with all sample datasets
- `betweenness`
- `pagerank`

#### Running Tests with Argument Example

<code>make tests [parse]</code>

<details>
    <summary>Sample Datasets used for Tests</summary>
    <code>Simple one connected component undirected graph '[one-connected.txt](dataset/sample-data/one-connected.txt)' (7 Nodes, 14 Edges)</code>
    <code>Simple two connected component undirected graph '[two-connected.txt](dataset/sample-data/two-connected.txt)' (8 Nodes, 14 Edges)</code>
    <code>One connected component undirected graph with many nodes '[one-connected-many-nodes.txt](dataset/sample-data/one-connected-many-nodes.txt)' (50 Nodes, 98 Edges)</code>
    <code>Simple undirected graph with one node disconnected '[one-node-disconnected.txt](dataset/sample-data/one-node-disconnected.txt)' (7 Nodes, 13 Edges)</code>
    <code>Simple Disconnected Components undirected graph '[many-disconnected.txt](dataset/sample-data/many-disconnected.txt)' (9 Nodes, 2 Edges)</code>
    <code>All nodes disconnected undirected graph '[disconnected-many-nodes.txt](dataset/sample-data/disconnected-many-nodes.txt)' (100 Nodes, 0 Edges)</code>
</details>

