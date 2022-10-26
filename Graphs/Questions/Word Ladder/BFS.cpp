#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> words(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    words.erase(beginWord);

    while (!q.empty())
    {
        auto front = q.front();
        string word = front.first;
        int index = front.second;
        q.pop();

        if (word == endWord)
            return index;

        for (int i = 0; i < word.length(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (words.find(word) != words.end())
                {
                    words.erase(word);
                    q.push({word, index + 1});
                }
            }
            word[i] = org;
        }
    }

    return 0;
}

int main()
{
    string begin, end;
    vector<string> wordList;

    cin >> begin >> end;

    int n;
    cin >> n;

    while (n--)
    {
        string val;
        cin >> val;

        wordList.push_back(val);
    }

    cout << ladderLength(begin, end, wordList);
    return 0;
}