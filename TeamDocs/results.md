# Algorithm Overview
## DFS
Our DFS implementation currently outputs the DFS traversal through the graph into a txt file. We begin at the first node given in the input dataset file, and do a depth first search from there. Moreover, we implemented an iterator to iterate through the items of the DFS traversal more efficiently and to track each item is in its traversal. [Sample_output](output/sample_traversal.txt)

## Betweenness Centrality
Betweenness Centrality was used to find the centrality of each node. High centrality nodes can be regarded as users that many people visit to connect to other users who are not in their direct social network. The output is a list of nodes and their centralities(betweenness score) in a txt file. We used the optimized Brandes algorithm based of BFS to achieve a more efficient time and space complexity. [Sample_output](output/sample_betweenness.txt)

## PageRank
PageRank was the main algorithms we needed to implement to answer our leading question. It is used to find the most “influential” node, which has the highest importance. The more edges a node has, the more important/probable we define the node to be. The output is a list of nodes with their importance scores in a txt file, in descending order. [Sample_output](output/sample_pagerank.txt). 

# Discussion/Reflection
