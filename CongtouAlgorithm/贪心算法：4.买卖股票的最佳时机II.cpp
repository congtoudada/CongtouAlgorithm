#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int result = 0;
        int buy = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > buy)
            {
                result += prices[i] - buy;
                buy = prices[i];
            }
            else
            {
                buy = prices[i];
            }
        }
        return result;
    }
};
