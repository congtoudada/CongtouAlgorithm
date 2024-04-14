#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                five++;
            if (bills[i] == 10)
            {
                if (five < 1)
                    return false;
                ten++;
                five--;
            }
            if (bills[i] == 20)
            {
                int need = 15;
                if (ten > 0)
                {
                    ten--;
                    need -= 10;
                }
                while(five > 0 && need > 0)
                {
                    five--;
                    need -= 5;
                }
                if (need > 0) return false;
            }
        }
        return true;
    }
};