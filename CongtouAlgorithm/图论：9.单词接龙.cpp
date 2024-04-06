#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //endWord不在字典则直接返回
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        //将vector转换为unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //记录word是否被访问过
        unordered_map<string, int> visitedMap;

        queue<string> que;
        que.push(beginWord);
        visitedMap.insert({ beginWord, 1 });
        while(!que.empty())
        {
            string word = que.front();
            que.pop();
            int path = visitedMap[word];
            for (int i = 0; i < word.size(); i++)
            {
                string newWord = word;
	            for (int j = 0; j < 26; j++)
	            {
                    newWord[i] = 'a' + j;
                    //广搜，无向图最短路径只要找到就返回。最外面已经判断过endWord不在wordList中的情况了
                    if (endWord == newWord) return path + 1;
                    //如果没有访问过且在wordList中
                    if (visitedMap.find(newWord) == visitedMap.end() && wordSet.find(newWord) != wordSet.end())
                    {
                        que.push(newWord);
                        visitedMap.insert({ newWord, path + 1 });
                    }
	            }
            }
        }
        return 0;
    }
};