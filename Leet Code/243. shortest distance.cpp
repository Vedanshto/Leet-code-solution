#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
class Solution
{

    public:
    int shortestDistance(vector<string>&str , string s1 , string s2)
    {
        int ans = INT_MAX;
        
        unordered_map<string,int>mp;

        for(int x = 0 ; x < str.size() ; x++ )
        {
            if(str[x] == s1 && mp.find(s2)!=mp.end())
            {
                ans = min(ans,abs(x-mp[s2]));
            }
            else if(str[x] == s2 && mp.find(s1) != mp.end())
            {
                ans = min(ans,abs(x-mp[s1]));
            }
            mp[str[x]] = x;
            
        }
        
        return ans ;

    } 
    
};



int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n ; cin>>n;

vector<string>str(n);

rep(x,n)
{
    cin>>str[x];
}

string s1 , s2;
cin>>s1>>s2;

Solution obj;

int ans = obj.shortestDistance(str,s1,s2);

cout<<ans;

return 0;
}