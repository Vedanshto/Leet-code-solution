// 2226. Maximum Candies Allocated to K Children

#include<bits/stdc++.h>
using namespace std;

bool chk(vector<int>&arr, long long k , int po)
{
    long long int ans = 0 ;
    for(int x = 0 ; x < arr.size() ; x++ )
    {
        ans += arr[x] / po;
    }

    return ans >= k;
}

int solv( vector<int>&arr, long long k )
{
        int n = arr.size();
    int l = 0 , h = 0;

    for(int x = 0 ; x < n ; x++ )
    {
        h = max(h,arr[x]);
    }

    while(l < h)
    {   
        int mid = (l+h+1) / 2;
        if(chk(arr,k,mid))
        {
            l = mid;    
        }
        else 
        {
            h = mid-1;
        }
    }


}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }

    int k ;
    cin>>k;
    
    cout<<solv(arr,k);
    return 0;
}
