#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define yes cout<<"yes";
#define no cout<<"No";
#define vi vector<int>
#define vll vector<long long>
const string directions = "LRUD";
const vector<int> dx={0,1,0,-1} ;
const vector<int> dy={1,0,-1,0} ;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        ll n = skill.size() , m = mana.size();

        // vector to sore the current times 

        vector<ll>ans(n,0);
        ll sum = 0;
        for(ll x = 0 ; x < n ; x++ )
        {
            sum += mana[0] * skill[x] * 1LL;
            ans[x] = sum;
        }

        // for the rest 

        for(ll x = 1 ; x < m ; x++ )
        {

            // create a temp vector for storing the max valuse

            vector<ll>temp(n);
            temp[0] = ans[0] + ( mana[x] * 1LL * skill[0]);


            for(ll i = 1 ; i < n ; i++ ) // for the sill
            {
                temp[i] = max(   ans[i]  , temp[i-1] ) +  (skill[i] * 1LL * mana[x]) ;
            }


            for(ll i = n-2 ; i >= 0 ; i--)
            {
                // last one 

                temp[i] = temp[i+1] - (mana[x]* 1LL * skill[i+1]);

            }

            ans = temp;
        }


        return ans[n-1];
        
    }
};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi skill = {1,5,2,4};
    vi mana = {5,1,4,2};
    Solution obj;

    cout<<obj.minTime(skill,mana);
    return 0;
} 