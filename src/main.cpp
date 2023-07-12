#include "graph.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Graph graph;
    graph.addNodes(1,{2,3});
    graph.addNodes(2,{1,4});
    graph.addNodes(3,{1,4});
    graph.addNodes(4,{2,3,5,6});
    graph.addNodes(5,{4,7});
    graph.addNodes(6,{4,7});
    graph.addNodes(7,{5,6});
    graph.print();

    cout << "dfs" <<endl;
    vector<vector<size_t>> vs = graph.ways(1,6);
    for(auto  i : vs)
    {
        for(auto j : i)
            cout << j <<" ";
        cout << endl;
    }

    return 0;
}
