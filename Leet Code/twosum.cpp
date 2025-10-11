#include<bits/stdc++.h>
using namespace std;


// 1 : apprich using hash map || time : O(n)  || space : O(n)
vector<int> twoSum1(vector<int>& nums, int target) 
{
int n = nums.size();
 map<int,int>mp;
for(int x = 0 ;x < n ; x++ )
{
    int num = nums[x];
    int rev = target - num;
    if(mp.find(rev) != mp.end())
    {
        return{mp[rev],x};
    }
    mp[num] = x;
}

    return {-1,-1};
}


// 2 : approch using two pointer || onley when array is soted || time : less then O(n) || space : O(1)
vector<int> twoSum2(vector<int>& nums, int target)
{
    int n = nums.size();
    int l = 0 , h = n-1;
    while(l <= h )
    {
        if(nums[l] + nums[h] == target)
        {
            return {l,h};
        }
        else if(nums[l] + nums[h] > target)
        {
            h--;
        }
        else 
        {
            l++;
        }
    }
    return {-1,-1};
}


// 3 : spproch using BF || Timr : O(n^2) || space : o(1) not using aney extra space 
vector<int> twoSum3(vector<int>& nums, int target)
{
    int n = nums.size();
    for(int x = 0 ; x < n ; x++ )
    {
       for( int i = 0 ; i < n ; i++ )
       {
        if(nums[x] + nums[i] == target)
        {
            return {x,i};
        }
       }
    }

    return {-1,-1};
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
    int k = 5;
    vector<int>ans = twoSum1(arr,k);

    cout<<ans[0]<<" ";
    cout<<ans[1]<<endl;
 return 0;
}


