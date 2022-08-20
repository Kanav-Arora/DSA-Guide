#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
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

        // Assumption is that word is in capital characters

        if (root->children[word[0] - 'a'] != NULL) // char already exists
        {
            insertUtil(root->children[word[0] - 'a'], word.substr(1, word.length() - 1));
        }
        else
        {
            TrieNode *n = new TrieNode(word[0]);
            root->children[word[0] - 'a'] = n;
            insertUtil(n, word.substr(1, word.length() - 1));
        }
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }
};

bool isEmpty(TrieNode* root)
{
    for(int i=0; i<26; i++)
    {
        if(root->children[i])
            return false;
    }
    return true;
}

void getSuggestions(TrieNode* root, vector<string> &ans, string s = "")
{
    if(isEmpty(root) && root->isTerminal)
    {
        ans.push_back(s+root->data);
        return;
    }
    
    if(root->isTerminal)
        ans.push_back(s+root->data);
    
    for(int i=0; i<26; i++)
    {
        if(root->children[i])
        {
            getSuggestions(root->children[i],ans, s+root->data);
        }
    }
}

// Coding Ninjas: https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    vector<vector<string>> ans;
    
    Trie* t = new Trie();
    for(int i=0; i<contactList.size(); i++)
        t->insert(contactList[i]);
    
    TrieNode* temp = t->root;
    string s = "";
    for(int i=0; i<queryStr.length(); i++)
    {
        char ch = queryStr[i];
        vector<string> srch;
        
        if(temp->children[ch-'a'])
        {
            getSuggestions(temp->children[ch-'a'], srch,s);
            
            ans.push_back(srch);
            s.push_back(ch);
            temp = temp->children[ch-'a'];
        }
        else
        {
            break;
        }
    }
    
    return ans;
}