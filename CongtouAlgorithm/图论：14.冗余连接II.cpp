#include <vector>
using namespace std;

class Solution {
public:
    static const int N = 1010; //如题：二维数组大小的在3到1000范围内
    int father[N];
    int n; //边的数量
    //并查集初始化
    void init()
    {
	    for (int i = 1; i <=n; i++)
	    {
            father[i] = i;
	    }
    }
    // 并查集寻根的过程
    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u这条边加入并查集
    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // 判断u和v是否同根
    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 对应情况三：存在环，在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>>& edges)
    {
        init(); //初始化并查集
        for (int i = 0; i < n; i++) //遍历所有的边
        {
            //构成有向环了，就是要删除的边
	        if (same(edges[i][0], edges[i][1]))
	        {
                return edges[i];
	        }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    // 对应情况一、二：找到入度为2的地方，删除一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge)
    {
        init(); //初始化并查集
        for (int i = 0; i < n; i++)
        {
            if (i == deleteEdge) continue;
            if (same(edges[i][0], edges[i][1])) //构成有向环，一定不是树
                return false;
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int inDegree[N] = {0}; //记录节点入度
        n = edges.size(); //边的数量
        for (int i = 0; i < n; i++)
        {
            inDegree[edges[i][1]]++; //统计入度
        }
        vector<int> vec; //记录入度为2的边（如果有就是2条）
        // 倒序寻找，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--)
        {
	        if (inDegree[edges[i][1]] == 2)
	        {
                vec.push_back(i);
	        }
        }
        // 处理情况1和2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if (vec.size() > 0)
        {
	        if (isTreeAfterRemoveEdge(edges, vec[0]))
	        {
                return edges[vec[0]];
	        }
            else
            {
                return edges[vec[1]];
            }
        }
        // 处理情况3
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);
    }
};