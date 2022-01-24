#include<iostream>
#include <map>
using namespace std;


int fibonacci(int n, map<int, int> values)
{
  if (n==0 || n==1)
    return n;
  std::map<int,int>::iterator iter = values.find(n);
  if (iter == values.end())
  {
    return values[n] = fibonacci(n-1, values) + fibonacci(n-2, values);
  }
  else
  {
    return iter->second;
  }
}


int main()
{
    map<int,int> answers;
    fibonacci(10, answers);
    map<int,int>::iterator it;
    for(it = answers.begin(); it!=answers.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<" ";
    }
    return 0;
}