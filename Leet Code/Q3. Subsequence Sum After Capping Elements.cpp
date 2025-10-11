#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
class Solution {
public:
    bool backtrack(vector<int>& nums, int idx, int current, int k) {
        if (current == k) return true;      
        if (current > k || idx == nums.size()) return false;

        if (backtrack(nums, idx+1, current + nums[idx], k)) return true;

        
        return backtrack(nums, idx+1, current, k);
    }

    vector<bool> subsequenceSumAfterCapping(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> ans(n, false);

        for (int x = 1; x <= n; x++) {
            vector<int> capped;
            for (int a : arr) capped.push_back(min(a, x));

            if (backtrack(capped, 0, 0, k))
                ans[x-1] = true;
        }

        return ans;
    }
}obj;



int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

vector<int>arr = {4,3,2,4};
int k = 5;

vector<bool> ans =  obj.subsequenceSumAfterCapping(arr,k);

rep(x,ans.size())
{
    if(ans[x]) cout<<"true"<<" ";
    else cout<<"false" <<" ";
}


return 0;
}