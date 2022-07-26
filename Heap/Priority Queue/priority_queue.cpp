#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> max_heap;       // by default max_heap
    max_heap.push(4);
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(6);
    max_heap.push(9);

    cout<<max_heap.top()<<endl;         // output root of max heap


    // min heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(4);
    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(6);
    min_heap.push(9);

    cout<<min_heap.top()<<endl;         // output root of max heap

    return 0;
}