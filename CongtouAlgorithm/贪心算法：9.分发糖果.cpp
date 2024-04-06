#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //题解思路
        if (ratings.size() == 1) return 1;
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < candy.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = candy.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < candy.size(); i++)
        {
            sum += candy[i];
        }
        return sum;

        //本人思路：时间复杂度高，只击败了5%
        //if (ratings.size() == 1) return 1;
        //vector<int> result(ratings.size(), 1);
        //for (int i = 0; i < ratings.size() - 1; i++)
        //{
        //    //下一个元素比当前元素大
        //    if (ratings[i + 1] > ratings[i])
        //    {
        //        result[i + 1] += result[i];
        //    }
        //    //下一个元素比当前元素小
        //    else
        //    {
        //        //向前传播+1
        //        for (int j = i; j >= 0 && ratings[j + 1] < ratings[j]; j--)
        //        {
        //            if (result[j] > result[j + 1]) break;
        //            result[j] += 1;
        //        }
        //    }
        //}

        //int sum = 0;
        //for (int i = 0; i < result.size(); i++)
        //{
        //    sum += result[i];
        //}
        //return sum;
    }
};