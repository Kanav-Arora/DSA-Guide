#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;

        for (auto each : asteroids)
        {
            if (each > 0)
                st.push_back(each);
            else
            {
                while (!st.empty() && st.back() > 0 && abs(each) > st.back())
                    st.pop_back();
                if (!st.empty() && abs(each) == st.back())
                    st.pop_back();
                else if (st.empty() || st.back() < 0)
                    st.push_back(each);
            }
        }

        return st;
    }
};