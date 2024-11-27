#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<string> split(string s, string delimiter)
    {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    string simplifyPath(string path)
    {
        stack<string> st;
        vector<string> dirs = split(path, "/");
        for (auto each : dirs)
        {
            if (each == "" || each == ".")
                continue;
            else if (each == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(each);
        }
        string ans = "";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans == "" ? "/" : ans;
    }
};