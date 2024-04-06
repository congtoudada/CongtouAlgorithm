#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& father, int u)
    {
        return u == father[u] ? u : father[u] = find(father, father[u]);
    }

    bool isSame(vector<int>& father, int u , int v)
    {
        u = find(father, u);
        v = find(father, v);
        return u == v;
    }

    void join(vector<int>& father, int u, int v)
    {
        u = find(father, u);
        v = find(father, v);
        if (u == v) return;
        father[v] = u;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> father(n);
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            join(father, edges[i][0], edges[i][1]);
        }
        return isSame(father, source, destination);
    }
};