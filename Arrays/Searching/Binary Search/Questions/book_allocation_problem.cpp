/*
    Question on https://www.codingninjas.com/codestudio/problems/allocate-books_1090540
*/

bool possibleSol(vector<int> arr, int n, int m, int mid)
{
    int pageSum = 0;
    int studentCount = 1;
    for(int i =0; i<n; i++)
    {
        if(pageSum+arr[i] <=mid)
            pageSum+=arr[i];
        else
        {
            studentCount++;
            if(studentCount>m || arr[i]>mid)
                return false;
            pageSum=arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++)
		sum+= arr[i];
    int e = sum;
    int mid = s + (e-s)/2;
    int ans=0;
    while(s<=e)
    {
        mid = s + (e-s)/2;
        if(possibleSol(arr, n, m,mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return ans;
}