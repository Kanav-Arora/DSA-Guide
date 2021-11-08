/*
    Remove Consecutive Duplicates from string

*/

#include<iostream>
using namespace std;


string remove_duplicate(string s)
{
    if(s.length()==0)
        return "";
    
    char ch = s[0];
    string ans = remove_duplicate(s.substr(1));
    if(ans[0]==ch)
        return ans;
    
    return ch+ans;

}

int main()
{
    string ln;
    getline(cin,ln);
    string val = remove_duplicate(ln);
    cout<<val<<endl;
    return 0;
}