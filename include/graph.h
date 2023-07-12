#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
/*class Node
{
    size_t num_;
    int direction_;
public:
    Node():num_(0),direction_(0){}
    Node(size_t num, int direction):num_(num),direction_(direction){}
    size_t vertix(){return num_;}
    int direction(){return direction_;}
};*/



class Graph
{
    using graph = std::unordered_map<size_t, std::vector<int>>;
    graph graph_;
    void dfs_recursion_(size_t startNode, std::vector<int> &visitedVertixs, std::vector<int> &result);
public:
    Graph():graph_(){}
    void addNodes(size_t vertix, std::initializer_list<int> list );
    size_t vertixes();
    void print();
    std::vector<int> dfs_recursion(size_t startNode);
    std::vector<int> dfs_iterations(size_t startNode);
    std::vector<int> bfs(size_t startNode);
    std::vector<std::vector<size_t>> ways(size_t startNode, size_t endNode);
    std::vector<int> shortestPath(int src, int dest);

};

#endif
