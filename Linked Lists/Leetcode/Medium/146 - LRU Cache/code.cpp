#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, val;
        Node *next, *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            next = NULL, prev = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> mp;

    Node *deleteFromList(Node *ele)
    {
        Node *prevNode = ele->prev, *nextNode = ele->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        ele->next = NULL;
        ele->prev = NULL;
        return ele;
    }

    void insertAfterHead(Node *ele)
    {
        Node *nextNode = head->next;
        head->next = ele;
        nextNode->prev = ele;
        ele->next = nextNode;
        ele->prev = head;
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.count(key) == 0)
            return -1;
        Node *ele = mp[key];
        ele = deleteFromList(ele);
        insertAfterHead(ele);
        return ele->val;
    }

    void put(int key, int value)
    {
        if (mp.count(key) == 0)
        {
            if (mp.size() == cap)
            {
                Node *lruEle = tail->prev;
                Node *deletedEle = deleteFromList(lruEle);
                mp.erase(deletedEle->key);
            }
            Node *newEle = new Node(key, value);
            insertAfterHead(newEle);
            mp[key] = newEle;
        }
        else
        {
            Node *ele = mp[key];
            ele = deleteFromList(ele);
            ele->val = value;
            insertAfterHead(ele);
        }
    }
};