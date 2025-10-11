#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&arr, int k , bool chk_left)
{
    int n = arr.size()-1;
    int l = 0 , h = n-1;
    int ans = -1;
    while (l<=h)
    {
        int mid = (l+h)/2;
        if(arr[mid] > k)
        {
            h = mid-1;
        }
        else if(arr[mid] < k)
        {
            l = mid+1;
        }
        else
        {
            ans = mid;
            if(chk_left)
            {
              h =   mid -1 ;
            }
            else 
            {
               l = mid+1;
            }
        }
    }
    return ans;
}
vector<int>find_the_first_and_last_accuring_target(vector<int>&arr , int k)
{
    vector<int>ans={-1,-1};
    int lft = binary_search(arr,k,true);
    int rit = binary_search(arr,k,false);
    ans[0] = lft;
    ans[1] = rit;
    return ans;
}

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }
    int k ;
    cin>>k;
    vector<int>ans=find_the_first_and_last_accuring_target(arr,k);

    for(auto it :ans)
    {
        cout<<it<<" ";
    }
 return 0;
}