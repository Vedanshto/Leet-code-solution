#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define yes cout<<"yes";
#define no cout<<"No";

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        int n = nums.size() , m = target.size();

        unordered_map<string,int>mp;

        for(int x = 0 ; x < n ; x++ )
        {
            mp[nums[x]]++;
        }

        int ans = 0 ; // to store the numbers for combinations

        // check for ever string 

        for(int x = 0 ; x < n ; x++ )
        {
            if(nums[x].size() > m) continue; 
            int sz = m - nums[x].size();
            string fst(target.end()-sz,target.end());
            if( nums[x]+fst == target && mp.find(fst) != mp.end())
            {
                ans+=mp[fst];
                if(fst == nums[x]) ans--;
            }
        }

        return ans;

    }
}obj;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        obj.numOfPairs();
    }
    return 0;
}