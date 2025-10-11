// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.



// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

// Output: 2


#include<bits/stdc++.h>
using namespace std;

class sol
{
public:
bool check_the_zeros(vector<int>& nums, vector<vector<int>>& q,int k)
{
    int n = nums.size() , m = q.size();
    vector<int>arr(n+1,0);

    for(int x = 0 ; x < k ; x++ )
    {
        int l = q[x][0], h =q[x][1] , num = q[x][2];
        
        arr[l]+=num;
        arr[h+1]-=num;
    }
    int sum = 0 ;

    for(int x = 0 ; x < n ; x++ )
    {
        sum+=arr[x];
        if(sum < nums[x]) return false;
    }

    return true;

}
 
int minZeroArray(vector<int>& nums, vector<vector<int>>& q)
{
    int m = q.size() , n = nums.size();
    if(!check_the_zeros(nums,q,m)) return -1;

    int low = 0 , h = n-1;

    while (low <= h)
    {
        int mid = (low+h)/ 2 ;

        if(check_the_zeros(nums,q,mid))
        {
            h = mid-1;
        }
        else 
        {
            low = mid+1;
        }
    }
    return low;
}

};


int main()
{
    vector<int>n={2,0,2};
    vector<vector<int>>q = {{0,2,1},{0,2,1},{1,1,3}};
    sol obj1;
    cout<<obj1.minZeroArray(n,q);
 return 0;
}
