#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> que; //钥匙集合
        que.push(0);
        visited[0] = true;

        while(!que.empty())
        {
            vector<int> keys = rooms[que.front()];
            que.pop();
            for (int i = 0; i < keys.size(); i++)
            {
	            if (!visited[keys[i]])
	            {
                    visited[keys[i]] = true;
                    que.push(keys[i]);
	            }
            }
        }

        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i]) return false;
        }
        return true;
    }
};