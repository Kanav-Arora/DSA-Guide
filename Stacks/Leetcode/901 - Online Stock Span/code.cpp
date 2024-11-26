#include <iostream>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int counter;

    StockSpanner()
    {
        counter = 0;
    }

    int next(int price)
    {
        counter++;
        while (!st.empty() && st.top().second <= price)
            st.pop();
        if (st.empty())
        {
            st.push({counter, price});
            return counter;
        }
        int ans = counter - st.top().first;
        st.push({counter, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */