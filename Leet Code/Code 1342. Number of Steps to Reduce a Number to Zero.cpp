#include<bits/stdc++.h>
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        
        int bits = log2(num)+1;
        int ans = 0;
        for(int x = 1 ; x <= bits ; x++ )
        {
            if(num&(1<<x-1))
            {
                cout<<x;el
                ans+=x;
                cout<<ans;
                el el
            }
        }
        return ans;
    }
};

int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int tc;
cin>>tc;
while(tc--)
{
    Solution obj;
    obj.numberOfSteps(14);
}
return 0;
}