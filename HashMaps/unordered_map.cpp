#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> map;

    // insertion
    pair<string,int> p = make_pair("kanav",4);
    map.insert(p);

    pair<string,int> p2("arora",4);
    map.insert(p2);

    map["name"] = 1;

    // updation of existing entry
    map["name"] = 2;


    // Search

    cout<<map["name"]<<endl;
    cout<<map.at("kanav")<<endl;
    // cout<<map.at("unknown_key")<<endl;   key not found error
    cout<<map["unknown_key"]<<endl;    // create a key with 0 val    executing line 27 after 28 will not give error as this pair is in the map with val 0

    // size
    cout<<map.size()<<endl;

    // to check presence
    cout<<map.count("non_existing")<<endl;      // 0 for non exisiting
    cout<<map.count("name")<<endl;              // 1 for exisiting

    // erase
    map.erase("kanav");
    cout<<map.size()<<endl;


    // access map
    for(auto i:map)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    // iterator
    unordered_map<string,int> :: iterator it = map.begin();

    while(it!=map.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}