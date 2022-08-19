#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childcount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        childcount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        if (root->children[word[0] - 'a'] != NULL) // char already exists
        {
            insertUtil(root->children[word[0] - 'a'], word.substr(1, word.length() - 1));
        }
        else
        {
            TrieNode *n = new TrieNode(word[0]);
            root->children[word[0] - 'a'] = n;
            root->childcount++;
            insertUtil(n, word.substr(1, word.length() - 1));
        }
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        if (root->children[index])
        {
            return searchUtil(root->children[index], word.substr(1, word.length() - 1));
        }
        else
        {
            return false;
        }
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int countNull(TrieNode* root)
{
    int count = 0;
    for(int i=0; i<26; i++)
    {
        if(root->children[i]!=NULL)
            count++;
    }
    
    return count;
}
    
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie();
    
    for(int i=0; i<arr.size(); i++)
        t->insert(arr[i]);
    
    int i = 0;
    int index = arr[0][i] - 'a';
    string ans = "";
    TrieNode* temp = t->root;
    
    while(temp->childcount==1)
    {
        if(temp->isTerminal)
            break;
        
        ans.push_back(temp->children[index]->data);
        temp = temp->children[index];
        i++;
        index = arr[0][i] - 'a';
    }
    return ans;
}

int main()
{
    
    return 0;
}