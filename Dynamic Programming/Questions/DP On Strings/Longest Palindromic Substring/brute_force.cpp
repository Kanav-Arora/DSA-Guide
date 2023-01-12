#include <iostream>
#include <vector>
using namespace std;

// O(N^3)

class Solution
{
private:
    bool isPalindrome(string s) // O(N)
    {
        string temp = s;
        reverse(s.begin(), s.end());
        return temp == s;
    }

public:
    string longestPalindrome(string s)
    {
        string pali = "";
        for (int i = 0; i < s.length(); i++) // O(N^2)
        {
            string temp = "";

            for (int j = i; j < s.length(); j++)
            {
                temp += s[j];
                if (isPalindrome(temp) && temp.length() > pali.length())
                    pali = temp;
            }
        }

        return pali;
    }
};

int main()
{

    return 0;
}