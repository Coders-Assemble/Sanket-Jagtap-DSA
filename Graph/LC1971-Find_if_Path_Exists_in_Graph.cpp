#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool check(unordered_map<int, vector<int>> &mpp, int S, int D, vector<int> &visited)
    {
        if (S == D)
            return true;

        if (visited[S] == true)
            return false;

        visited[S] = true;

        for (auto node : mpp[S])
        {
            if (check(mpp, node, D, visited))
            {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
            return true;

        unordered_map<int, vector<int>> mpp;

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int> visited(n, false);

        return check(mpp, source, destination, visited);
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
            return true;

        unordered_map<int, vector<int>> graph;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;
        stack<int> stk;
        stk.push(source);

        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();

            if (node == destination)
                return true;

            if (visited.count(node))
                continue;
            visited.insert(node);

            for (int neighbor : graph[node])
            {
                if (!visited.count(neighbor))
                {
                    stk.push(neighbor);
                }
            }
        }
        return false;
    }
};