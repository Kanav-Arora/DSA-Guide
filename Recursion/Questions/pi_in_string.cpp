/*
    Replace PI with 3.14 in string

    for eg  pixxpixyz
            3.14xx3.14xyz
*/

#include<iostream>
using namespace std;


void replacePI(string &s, int i=0)
{
    if(i==s.length()-2)
    {
        return;
    }

    if(s[i]=='p' && s[i+1]=='i')
    {
        string prev = s.substr(0,i);
        string after = s.substr(i+2,s.length());
        s = prev + "3.14" + after;
    }
    i++;
    replacePI(s,i);
}

int main()
{
    string line;
    getline(cin,line);
    replacePI(line);
    cout<<line<<endl;
    return 0;
}