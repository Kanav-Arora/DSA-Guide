#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> words(wordList.begin(), wordList.end());

    queue<vector<string>> q;
    vector<string> temp = {beginWord};
    q.push(temp);
    words.erase(beginWord);

    vector<vector<string>> ans;
    vector<string> filter;
    filter.push_back(beginWord);
    int level = 0;
    while (!q.empty())
    {

        vector<string> ls = q.front();
        string word = ls.back();
        q.pop();

        if (ls.size() > level)
        {
            level++;

            for (auto it : filter)
            {
                words.erase(it);
            }
            filter.clear();
        }

        if (word == endWord)
        {
            if (ans.size() == 0)
                ans.push_back(ls);
            else if (ans[0].size() == ls.size())
                ans.push_back(ls);
        }

        for (int i = 0; i < word.length(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (words.find(word) != words.end())
                {
                    filter.push_back(word);
                    ls.push_back(word);
                    q.push(ls);
                    ls.pop_back();
                }
            }
            word[i] = org;
        }
    }

    return ans;
}

int main()
{

    return 0;
}