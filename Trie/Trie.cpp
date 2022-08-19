#include <iostream>
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
    TrieNode *root;

public:
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

        if (root->children[word[0] - 'A'] != NULL) // char already exists
        {
            insertUtil(root->children[word[0] - 'A'], word.substr(1, word.length() - 1));
        }
        else
        {
            TrieNode *n = new TrieNode(word[0]);
            root->children[word[0] - 'A'] = n;
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

        int index = word[0] - 'A';

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

    TrieNode *removeUtil(TrieNode *root, string word, int depth = 0)
    {
        if (root == NULL)
            return NULL;

        if (depth == word.size())
        {
            if (root->isTerminal)
                root->isTerminal = false;

            if (isEmpty(root))
            {
                delete root;
                root = NULL;
            }

            return root;
        }

        root->children[word[depth] - 'A'] = removeUtil(root->children[word[depth] - 'A'], word, depth + 1);

        if (isEmpty(root) && root->isEndOfWord == false)
        {
            delete (root);
            root = NULL;
        }

        return root;
    }

    void removeKey(string word)
    {
        root = removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insert("KANAV");
    ;
    cout << t->search("KANAV") << endl;
    cout << t->search("KANA") << endl;
    cout << t->search("KANAVA") << endl;

    return 0;
}