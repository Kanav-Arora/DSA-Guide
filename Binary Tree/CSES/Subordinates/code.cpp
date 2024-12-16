#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

struct Node
{
    int val;
    vector<Node *> children;
    Node(int data)
    {
        val = data;
    }
};

int caller(Node *root, map<int, int> &cnt)
{
    if (!root)
        return 0;
    int sum = 0;
    for (auto each : root->children)
    {
        sum += caller(each, cnt);
    }
    cnt[root->val] = sum;
    return sum + 1;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, Node *> mp;
    Node *root = new Node(1);
    mp[1] = root;
    for (int i = 1; i < n; i++)
    {
        Node *curr = new Node(i + 1);
        mp[i + 1] = curr;
    }
    for (int i = 1; i < n; i++)
    {
        int val;
        cin >> val;
        mp[val]->children.push_back(mp[i + 1]);
    }

    map<int, int> count;
    int _ = caller(root, count);

    for (auto each : count)
    {
        cout << each.second << " ";
    }
    return 0;
}