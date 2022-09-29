// hackerearth code monk question:
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

#include <iostream>
#include<vector>
#include<set>
using namespace std;

int updateParent(vector<int> &parent, int i)
{
	if(parent[i]==i)
		return i;
	
	return parent[i] = updateParent(parent, parent[i]);
}

int main() {
	int n;
	int invasion;
	cin>>n>>invasion;
	vector<int> parent(n+1);

	for(int i=0; i<=n; i++)
		parent[i] = i;

	for(int i =0; i<invasion; i++)
	{
		int first,sec;
		cin>>first>>sec;

		parent[sec] = first;
	}

	for(int i=0; i<parent.size(); i++)
		int val = updateParent(parent,i);

	set<int> s(parent.begin()+1, parent.end());

	cout<<s.size();
}