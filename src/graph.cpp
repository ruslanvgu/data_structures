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
    using namespace  std;
    vector<int> visited(vertixes(),false);
    vector<int> result;
    stack<int> stack;

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

std::vector<int> Graph::bfs(size_t startNode)
{
    using namespace std;
    vector<int> result;
    queue<int> q;
    vector<bool> visited(vertixes(),false);
    q.push(startNode);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(visited[node])
            continue;

        result.push_back(node);
        visited[node] = true;
        for(auto n : graph_[node]){
                q.push(n);
        }
    }
    return result;
}

std::vector<int> Graph::shortestPath(int src, int dest)
{
    using namespace std;

    vector<bool> visited(vertixes(), false); // Массив для отслеживания посещенных вершин
    queue<vector<int>> q; // Очередь для выполнения BFS
    visited[src] = true;
    q.push({src});

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();

        int lastNode = path[path.size() - 1];
        if (lastNode == dest) { // Если достигли целевой вершины
            return path;
        }

        for (int i : graph_[lastNode]) {
            if (!visited[i]) {
                vector<int> newPath(path.begin(), path.end());
                newPath.push_back(i);
                visited[i] = true;
                q.push(newPath);
            }
        }
    }



   return {}; // Если путь не найден

}

std::vector<std::vector<size_t>> Graph::ways(size_t startNode, size_t endNode)
{
    using namespace std;

    vector<vector<size_t>> result;
    vector<bool> visited(vertixes(),false);
    queue<vector<size_t>> q;
    visited[startNode] = true;
    q.push({startNode});
    while(!q.empty()){
        vector<size_t> path = q.front();
        q.pop();

        size_t lastNode = path[path.size()-1];
        if (lastNode == endNode) { // Если достигли целевой вершины
            result.push_back(path);

        }

        for(auto v : graph_[lastNode])
        {
            if (!visited[v]) {
            vector<size_t> newPath(path.begin(),path.end());
            newPath.push_back(v);
            visited[v] = true;
            q.push(newPath);
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

void Graph::addNodes(size_t vertix, std::initializer_list<int> list ){
    if(list.size() > 0)
        graph_[vertix] = list;
}

size_t Graph::vertixes()
{
    return graph_.size();
}
