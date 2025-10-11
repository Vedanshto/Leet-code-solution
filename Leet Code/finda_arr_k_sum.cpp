#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            int c = 0 , sum = 0 ;
            unordered_map<int, int> mp;
            mp[0] = 1;
            for(int x : nums)
            {
                sum+=x; 

                if(mp.find(sum-k) != mp.end())
                {
                    c+=mp[sum-k];
                }
                mp[sum]++;
            }
            return c;
        }

    };
int main()
{

    int n ;
    cin>>n;
    vector<int> nums(n);
    for(int x = 0 ; x < n ; x++)
    {
        cin>>nums[x];
    }
    int k;
    cin>>k;
    Solution s;
    cout<<s.subarraySum(nums,k);
 return 0;
}