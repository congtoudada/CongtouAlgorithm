#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int>& father, int u)
    {
        return u == father[u] ? u : father[u] = find(father, father[u]);
    }

    bool isSame(vector<int>& father, int u, int v)
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


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> father(edges.size() + 1);
        for (int i = 0; i < father.size(); i++)
        {
            father[i] = i;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (isSame(father, u, v)) return edges[i];
            join(father, u, v);
        }
        return {};
    }
};

//int main()
//{
//    vector<vector<int>> edges = {{1, 2},{1, 3},{2, 3}};
//    Solution solution;
//    solution.findRedundantConnection(edges);
//}