#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int>&arr , int temp )
{
   int n = arr.size;
   int ans = INT_MAX;
   int pos = -1; 
   for(int x = 0 ; x < n ; x++ )
    {
        if(arr[x] > temp && arr[x] < ans )
        {
            ans = arr[x];
            pos = x;            
        }
    }

    return pos;
}
int main()
{
    int n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        
    }
    
 return 0;
}