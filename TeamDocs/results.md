# Project Overview
THis project was built to analyze a social network, specifically to see how influential each user/profile is in this Facebook network.

## Algorithm Overview
### Data Parsing + DFS
Data is given each node listed with other nodes it's connected to in an increasing order (starting with 0, ending with 4039). Our DFS implementation currently outputs the DFS traversal through the graph into a txt file. We begin at the first node given in the input dataset file, and do a depth first search from there. Moreover, we implemented an iterator inside to iterate through the items of the DFS traversal more efficiently and to track each item is in its traversal. [Sample_output](../output/sample_traversal.txt)

### Betweenness Centrality
Betweenness Centrality was used to find the centrality of each node. High centrality nodes can be regarded as users that many people visit to connect to other users who are not in their direct social network. Since betweenness centrality measures the number of times a node lies on the shortest path between other nodes, we can say a node with high betweenness has a large influence on the network. The output is a list of nodes and their centralities(betweenness score) in a txt file. We used the optimized Brandes algorithm based of BFS to achieve a more efficient time and space complexity to be O(V * E) and O(V + E). In our result, Node #1684 has the highest betweenness score in this Facebook network with the betweenness score of aroung 537,944. [Sample_output](../output/sample_betweenness.txt)

### PageRank
PageRank was the main algorithms we needed to implement to answer our leading question. It is used to find the most “influential” node, which has the highest importance. The more direct edges (connections) a node has, the more important/probable we define the node to be. Node #107 had the highest importance score of 0.03872. The output file is a list of nodes with their importance scores in a txt file, in descending order. [Sample_output](../output/sample_pagerank.txt). 

## Discussion/Reflection
Node 1684 having one of the top scores for both importance and betweenness, we conclude that the user with id #1684 was the most influential in this given network. Given more time, if we were to further analyze the network, we could implement shortestpath algorithm to find the shortest path from node A to node B, to find the most efficient way for user A to be friends with user B, to whom they'll need to reach to connect to get to user B, both in their network and out of their current network. This dataset we chose had undirected edges (since being "friends" in Facebook is already a two-way connection), making our graph undirected. 
