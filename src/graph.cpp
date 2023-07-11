#include "graph.h"

void Graph::print()
{
    using namespace std;
    for(auto [key, values] : graph_)
    {
        cout << key << " -> ";
        for(auto value : values){
            cout << value <<" ";
        }
        cout << endl;
    }
}

std::vector<int> Graph::dfs_recursion(size_t startVertix)
{
    std::vector<int> visited(vertixes(),false);
    std::vector<int> result;
    dfs_recursion_(startVertix, visited, result);
    return result;
}

std::vector<int> Graph::dfs_iterations(size_t startVertix)
{
    std::vector<int> visited(vertixes(),false);
    std::vector<int> result;
    std::stack<int> stack;

    stack.push(startVertix);

    while(!stack.empty()){
        int node = stack.top();
        stack.pop();

        if(!visited[node]){
            result.push_back(node);
            visited[node] = true;
            for(auto neighbor  : graph_[node]){
                stack.push(neighbor);
            }

        }
    }

    return result;
}

void Graph::dfs_recursion_(size_t startVertix, std::vector<int> &visitedVertixs, std::vector<int> &result)
{
    /*
    result.push_back(startVertix);
    visitedVertixs[startVertix] = true;

    for(int vertix :graph_[startVertix])
    {
        if(visitedVertixs[vertix])
            continue;
        dfs_(vertix,visitedVertixs,result);
    }*/

    if(visitedVertixs[startVertix])
        return;

    result.push_back(startVertix);
    visitedVertixs[startVertix] = true;

    for(int vertix :graph_[startVertix])
    {
        dfs_recursion_(vertix,visitedVertixs,result);
    }
}

void Graph::addNode(size_t vertix, std::initializer_list<int> list ){
    if(list.size() > 0)
        graph_[vertix] = list;
}

size_t Graph::vertixes()
{
    return graph_.size();
}
