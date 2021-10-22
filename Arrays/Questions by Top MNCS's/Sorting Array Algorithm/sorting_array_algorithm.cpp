#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include<climits>
using namespace std;


int linearsearch(int arr[], int n, int ind)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==ind)
        {
            return i;
        }
    }
    return 0;
}

// ------------------------------ Sort Array ------------------------------------

void arrange(int arr[],int n, int *final_arr)
{
    int ind[n];
    ind[0] = 0;
    ind[1] = n-1;
    bool position[n];
    for(int i=0; i<n; i++)
    {
        position[i] = false;
    }
    position[0] = true;
    position[n-1] = true;

    int counter = 2;
    int mid = n-1;
    int multiple = 1;
    while(1)
    {
        if(counter==n)
            break;
        int val = 1;
        int div = pow(2,multiple);
        for(int i=0; i<multiple; i++)
        {
            if(counter==n)
                break;
            
            if(mid/div<1)
            {
                for(int i=0; i<n; i++)
                {
                    if(position[i] == false)
                    {
                        ind[counter] = i;
                        counter++;
                    }
                }
            }

            else
            {

            int index = val*mid/div;

            ind[counter] = index;
            position[index] = true;
            
            val+=2;
            counter++;
            }
        }
        multiple++;
    }
    for(int i=0; i<n; i++)
    {
        int ind_ar = linearsearch(ind, n, i);
        final_arr[i] = arr[ind_ar];
    }
}

// ------------------------------ Remove Even Numbers ------------------------------------

void remove_even(vector<int> &v, int n)
{
    int first_even = INT_MAX;
    int first_odd = INT_MAX;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]%2==0 && first_even==INT_MAX)
        {
            first_even = i;
        }
        else if(v[i]%2!=0 && first_odd==INT_MAX)
        {
            first_odd =i;
        }
    }
    v[max(first_even,first_odd)] = v[first_even] + v[first_odd];
    v.erase(v.begin() + min(first_even,first_odd));
    int last_even = INT_MAX;
    int last_odd = INT_MAX;
    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i]%2==0 && last_even==INT_MAX)
        {
            last_even = i;
        }
        else if(v[i]%2!=0 && last_odd==INT_MAX)
        {
            last_odd =i;
        }
    }
    v[min(last_even,last_odd)] = v[last_even] + v[last_odd];
    v.erase(v.begin() + max(last_even,last_odd));
}

// ------------------------------ Remove Negative Numbers ------------------------------------

void remove_negative(vector<int> &v, int n)
{
    int first_neg = INT_MAX;
    int first_pos = INT_MAX;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]<0 && first_neg==INT_MAX)
        {
            first_neg = i;
        }
        else if(v[i]>0 && first_pos==INT_MAX)
        {
            first_pos =i;
        }
    }
    v[max(first_neg,first_pos)] = v[first_neg] + v[first_pos];
    v.erase(v.begin() + min(first_neg,first_pos));
    int last_neg = INT_MAX;
    int last_pos = INT_MAX;
    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i]<0 && last_neg==INT_MAX)
        {
            last_neg = i;
        }
        else if(v[i]>0 && last_pos==INT_MAX)
        {
            last_pos =i;
        }
    }
    v[min(last_neg,last_pos)] = v[last_neg] + v[last_pos];
    v.erase(v.begin() + max(last_neg,last_pos));
}

// ------------------------------ Remove Duplicate Numbers ------------------------------------
void remove_duplicate(vector<int> &v, int dup)
{
    vector< int >::iterator index;
    index =  find(v.begin(), v.end(), dup);
    v.erase(index);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int final_arr[n];
    arrange(arr,n, final_arr);
    vector<int> v1;
    for(int i=0; i<n; i++)
    {
        v1.push_back(final_arr[i]);
    }
    
    for(int i=0; i<v1.size(); i++)
    {
        if(v1[i]%2==0)
        {
            remove_even(v1,n);
        }
    }
    for(int i=0; i<v1.size(); i++)
    {
        if(v1[i]<0)
        {
            remove_negative(v1,n);
        }
    }
    for(int i=0; i<v1.size(); i++)
    {
        if(v1[i]%2==0)
        {
            remove_even(v1,n);
        }
    }

    int numbers[1001];
    for(int i=0; i<1001; i++ )
    {
        numbers[i] = INT_MIN;
    }

    for(int i=0; i<v1.size(); i++)
    {
        int count_val = count(v1.begin(), v1.end(), v1[i]);
        numbers[v1[i]] = count_val;
    }

    for(int i=0; i<1001; i++)
    {
        if(numbers[i]>1)
        {
            remove_duplicate(v1,i);
            numbers[i]--;
        }
    }

    for(int i=0; i<v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    return 0;
}