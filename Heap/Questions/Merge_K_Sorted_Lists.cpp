#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val)
        {
            this->val = val;
            next = NULL;
        }
};


class compare
{
    public:
        bool operator()(Node* a, Node* b)
        {
            return a->val>b->val;
        }
};

Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        if(lists.empty())
            return NULL;
        
        int k = lists.size();
        
        for(int i=0; i<k; i++)
        {
            if(lists[i]!=NULL)
                minHeap.push(lists[i]);
        }
        
        if(minHeap.empty())
            return NULL;
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while(!minHeap.empty())
        {
            if(head==NULL)
            {
                head = tail = minHeap.top();
                minHeap.pop();
                
                
                if(head->next)
                {
                    minHeap.push(head->next);
                }
            }
            
            else
            {
                tail->next = minHeap.top();
                minHeap.pop();
                tail = tail->next;
                
                if(tail->next)
                    minHeap.push(tail->next);
            }
        }
        
        return head;
        
    }


int main()
{
    
    return 0;
}