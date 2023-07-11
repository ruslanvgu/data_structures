#include "graph.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Graph graph;
    graph.addNode(1,{2,3,5});
    graph.addNode(2,{1,3,4});
    graph.addNode(3,{1,2,3,4,5});
    graph.addNode(4,{2,3});
    graph.addNode(5,{1,3});
    graph.print();
    cout << "dfs" <<endl;
    vector<int> vs = graph.dfs_iterations(5);
    for(auto  i : vs)
    {
        cout << i <<" ";
    }
    cout << endl;

    return 0;
}
