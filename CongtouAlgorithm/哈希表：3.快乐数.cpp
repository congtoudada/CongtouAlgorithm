#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> result;
        while(n != 1)
        {
            n = cal(n);
            if (result.find(n) != result.end()) return false; //找到环则退出
            result.insert(n);
        }
        return true;
    }

    int cal(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int mod = n % 10;
            sum += mod * mod;
            n /= 10;
        }
        return sum;
    }
};

//int main()
//{
//    Solution solution;
//    std::cout << solution.cal(19) << std::endl;
//    std::cout << solution.cal(82) << std::endl;
//    return 0;
//}