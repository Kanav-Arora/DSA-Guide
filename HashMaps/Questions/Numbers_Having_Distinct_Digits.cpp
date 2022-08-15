#include<iostream>
#include<set>
using namespace std;

void printUnique(int n)
{
    for (int i=1 ; i<=n ; i++)
    {
        int num = i;
        bool visited[10] = {false};
        while (num)
        {
            if (visited[num % 10])
                break;
 
            visited[num%10] = true;
 
            num = num/10;
        }
        if (num == 0)
            cout << i << " ";
    }
}

void printUnique2(int n){
  for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        set<int> uniDigits(s.begin(), s.end());
        if (s.size() == uniDigits.size()) {
            cout << i << " ";
        }
    }
}

int main()
{
    
    return 0;
}