#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <vector>
#include <iostream>

class Node
{
    size_t num_;
    int direction_;
public:
    Node():num_(0),direction_(0){}
    Node(size_t num, int direction):num_(num),direction_(direction){}
    size_t vertix(){return num_;}
    int direction(){return direction_;}
};

using graph = std::unordered_map<size_t, std::vector<Node>>;


class Graph
{
    graph graph_;
public:
    Graph(){}
    Graph(size_t vertix, std::initializer_list<int> list ){
        std::cout << vertix << " ";
        for(auto v : list)
        {
            std::cout << v <<" " ;
        }
        std::cout << std::endl;
    }

};

#endif
