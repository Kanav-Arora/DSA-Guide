#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

void DFS(string beginWord, string word, unordered_map<string, int> mp, vector<vector<string>> &ans, vector<string> path)
{
    path.push_back(word);

    if (word == beginWord)
    {
        reverse(path.begin(), path.end());
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < word.length(); i++)
    {
        string temp = word;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            temp[i] = ch;
            if (mp.find(temp) != mp.end() && mp[temp] == (mp[word] - 1))
            {
                DFS(beginWord, temp, mp, ans, path);
            }
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    unordered_map<string, int> mp;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    mp[beginWord] = 1;
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int index = q.front().second;
        q.pop();

        if (word == endWord)
        {
            mp[endWord] = index;
            break;
        }

        for (int i = 0; i < word.length(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (st.find(word) != st.end())
                {
                    q.push({word, index + 1});
                    mp[word] = index + 1;
                    st.erase(word);
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> ans;
    vector<string> path;

    if (mp.find(endWord) != mp.end())
        DFS(beginWord, endWord, mp, ans, path);

    return ans;
}

int main()
{

    return 0;
}