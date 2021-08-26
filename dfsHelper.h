#include <bits/stdc++.h>
#include "gameboard.h"
#include "piece.h"

#ifndef DFSHELPER_H
#define DFSHELPER_H

using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
//    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

bool canReachHelper(int pos1, int pos2) {
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,7);
    g.addEdge(1,6);
    g.addEdge(6,8);
    g.addEdge(8,10);
    g.addEdge(10,12);
    g.addEdge(12,13);
    g.addEdge(13,14);
    g.addEdge(14,19);
    g.addEdge(14,15);
    g.addEdge(15,16);
    g.addEdge(7,9);
    g.addEdge(9,11);
    g.addEdge(11,16);
    g.addEdge(12,17);
    g.addEdge(17,18);
    g.addEdge(18,19);
    g.addEdge(19,20);
    g.addEdge(20,21);
    g.addEdge(16,21);
    g.addEdge(17,22);
    g.addEdge(22,24);
    g.addEdge(24,26);
    g.addEdge(26,28);
    g.addEdge(21,23);
    g.addEdge(23,25);
    g.addEdge(25,27);
    g.addEdge(27,32);
    g.addEdge(28,29);
    g.addEdge(29,30);
    g.addEdge(30,31);
    g.addEdge(31,32);
    g.DFS(pos1);

}

#endif // DFSHELPER_H
