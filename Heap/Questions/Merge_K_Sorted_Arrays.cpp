#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Node{
    public:
        int data;
        int row;
        int col;
};

class compare
{
    public:

        bool operator()(Node a, Node b)
        {
            return a.data>b.data;
        }

};

vector<int> MergeArrays(vector<vector<int>> arrays, int k)
{
    priority_queue<Node, vector<Node>, compare> min_Heap;


    // Step 1: insert first element of all arrays

    for(int i=0; i<k; i++)
    {
        Node n;
        n.data = arrays[i][0];
        n.row = i;
        n.col = 0; 

        min_Heap.push(n);
    }
    
    // Step 2: while min_heap size>1 

    vector<int> ans;

    while(min_Heap.size()>0)
    {
        Node temp = min_Heap.top();
        ans.push_back(temp.data);
        min_Heap.pop();

        int row = temp.row;
        int col = temp.col;


        if(col+1<arrays[row].size())
        {
            Node n;
            n.data = arrays[row][col+1];
            n.row = row;
            n.col = col+1;
            min_Heap.push(n);
        }
    }   

    return ans;
}

int main()
{
    
    return 0;
}