#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> profit(gas.size());
        //计算出油箱数组
        for (int i = 0; i < profit.size(); i++)
        {
            profit[i] = gas[i] - cost[i];
        }
        
        int startIdx = 0;
        int sum = profit[0];
        int pre_sum = profit[0];
        for (int i = 1; i < profit.size(); i++)
        {
            sum += profit[i];
            //前序和小于0，代表缺油，需要从当前索引起步
            if (pre_sum < 0)
            {
                pre_sum = profit[i];
                startIdx = i;
            }
            //不处于缺油，就不需要改变起始加油位置
            else
            {
                pre_sum += profit[i];
            }
        }
        if (sum < 0) return -1;
        else return startIdx;
    }
};