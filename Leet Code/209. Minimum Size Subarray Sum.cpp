#include<bits/stdc++.h>
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
using namespace std;
class Solution {
public:
    int minSubArrayLen(int  t, vector<int>& arr) {
        int n = arr.size(),sum=0;
        vector<ll>prefix(n+1,0);
        rep(x,n)
        {
            sum = arr[x]+sum;
            prefix[x] = sum;
        }
    int ans = INT_MAX;
        rep(x,n)
        {
            int l = x;
            while(l > 0)
            {
                if(prefix[x]-prefix[l] >= t)
                {
                    ans = min(ans,x-l+1);
                    break;
                }
            }
        }
        return ans;
    }
}obj;

void test()
{
    int t , n ; cin>>t>>n;
    vector<int>arr(n);
    rep(x,n) cin>>arr[x];
    obj.minSubArrayLen(t,arr);
}



int main()
{
int n;
cin>>n;
while(n--)
{
test();
}
return 0;
}