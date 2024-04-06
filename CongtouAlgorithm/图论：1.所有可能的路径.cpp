#include <vector>
using namespace std;

class Solution {
public:
    //1.确认递归函数，参数
    vector<vector<int>> result; //收集符合条件的路径
    vector<int> path; //0节点到终点的路径
    //x: 目前遍历的节点
    //graph: 存当前的图
    void dfs(vector<vector<int>>& graph, int x)
    {
        //2.确认终止条件
        if (x == graph.size() - 1) //找到符合条件的一条路径
        {
            result.push_back(path);
            return;
        }
        //3.处理目前搜索节点出发的路径
        //遍历节点n链接的所有节点
        for (int i = 0; i < graph[x].size(); i++)
        {
            //已遍历过的节点不会继续遍历（针对有环的题目）
            //if (find(path.begin(), path.end(), graph[x][i]) != path.end())
            //{
            //    continue;
            //}
            path.push_back(graph[x][i]); //遍历到的节点加入到路径中来
            dfs(graph, graph[x][i]); //进入下一层节点
            path.pop_back(); //回溯，撤销本节点
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0); //无论什么路径都是从0开始出发
        dfs(graph, 0);
        return result;
    }
};

//int main()
//{
//    //有环的话
//    vector<vector<int>> graph = {
//        {1, 2},
//        {2, 3},
//        {1, 3},
//        {}
//    };
//    Solution solution;
//    auto ret = solution.allPathsSourceTarget(graph);
//    return 0;
//}