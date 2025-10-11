//[1,]

// find the maximum product subarray

#include<bits/stdc++.h>
using namespace std;
int max_product(vector<int>&arr) // BF solution of this problem
{
    int pro =INT_MIN ;
    int n = arr.size();
    for(int x = 0 ; x < n ; x++ )
    {
        int p1 = 1;
        for(int i = x ; i < n ; i++ )
        {
            p1 *= arr[i];
        }
        pro = max(pro,p1);
    }   
    return pro;
}

int max_product2(vector<int>arr)
{
    int n = arr.size();
    int pf1 = 1 , pf2 = 1;
    int ans;
    for(int x = 0 ; x < n ; x++ )
    {
        if(pf1 == 0) pf1 = 1;
        if(pf2 == 0) pf2 = 1;

        pf1 *= arr[x];
        pf2*= arr[n-x-1];

        int temp = max(pf1,pf2);

        ans = max(ans,temp);

    }
    return ans;
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
    int ans = max_product2(arr);
    cout<<ans;
 return 0;
}