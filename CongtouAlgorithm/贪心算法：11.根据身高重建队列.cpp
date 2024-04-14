#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b)
        {
                if (a[0] == b[0]) return a[1] < b[1];
                return a[0] > b[0];
        });
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            que.insert(que.begin() + people[i][1], people[i]);
        }
        return que;
    }
};

//int main()
//{
//    Solution solution;
//    vector<vector<int>> people = {
//        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
//    };
//    solution.reconstructQueue(people);
//}