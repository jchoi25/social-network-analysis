# CS 225 Final Project: Proposal

Are You Friends With Me?

## Leading Question/Goal

The goal of this project is to analyze a social media network. It will show who has the most connections with everyone (“central node” of network graph), using BFS and DFS. This is to find who may be considered to be the most influential in the chosen social media. Next goal we aim to achieve is by using Page Rank algorithm and Betweenness Centrality. These algorithms will be used to find the most influential user, who will have the most “connections/friends” in the whole network. Given a specific user, we will also find the most influential friend in the user’s network. More detailed description of how our dataset and algorithms will be utilized and used is in the dataset and algorithms sections below.


## Dataset

http://snap.stanford.edu/data/ego-Facebook.html 

The dataset we will be using is from the Stanford Large Network Data Collection. This dataset consists of anonymized friends lists (cicles) from Facebook, including profiles and ego networks. The Facebook dataset has 4,030 nodes (profiles) and 88,234 edges which show the connections or “friends” each profile has. The files we will be using are: nodeId.edges, nodeId.circles, and nodeId.feat. nodeId.edges contains the edges in the network data for the node 'nodeId'. Edges are undirected for facebook (an edge means user a and user b are “friends”). nodeId.circles has the set of circles for the central node. Each line contains one circle, consisting of a series of node ids. The first entry in each line is the name of the circle. nodeId.feat lists the profiles for each of the nodes that appears in the edge file. All data files listed will be downloaded and stored in git repository. The data we will be using is already a set of graphs, so we won’t need to process the data more than it already is.

For our backup dataset, we have chosen Twitter social circles, which have the same files and contents as our main dataset of Facebook, but from Twitter. 



## Algorithms

**DFS**	
DFS Traversal will be used to visualize the graph at the end. It will go through all nodes to visualize each connected node. Since we will go through the entire graph, both the time and space complexity for this algorithm is O(n).

**Betweenness Centrality**
We will be using the Between Centrality algorithm to find the centrality of each node. The centrality will be an indicator of how many shortest paths go through that node. High centrality nodes can be regarded as users that many people visit to connect to other users who are not in their direct social network. The output will be a list of nodes and their centralities in a .txt file. By using the optimized Brandes algorithm based of BFS, we can achieve a time complexity of O(V * E) and a space complexity of O(V + E) where V is the number of vertices and E is the number of edges.

**PageRank**
PageRank will be used to find the most “influential” node. Given a graph, this will be outputting a graph with each node storing the popularity, or importance value of the node. More specifically, this will tell us what nodes are the "hub nodes" which have more connections than what other nodes have. The time complexity of this algorithm will be O(k * E) (k is the number of iterations; since the input graph is undirected, it will need to be converted into a directed graph) with the space complexity of O(n).


## Timeline
	
Due 04/07: Data processing and full structure/layout of program settings
Due 04/14: BFS and DFS algorithms written and verified with tests

-  04/15 Mid-Project Check-in  -

Due 04/21: Betweenness Centrality algorithm written and verified with tests
Due 04/28: Page Rank Algorithm written and verified with tests
         (If time allows, graphs visualized more than prints)
Due 05/05: Final written report and presentation video and slides (+ README file)
