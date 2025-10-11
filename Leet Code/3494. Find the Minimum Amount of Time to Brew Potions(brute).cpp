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
  bool check(const vector<long long>& ans, const vector<int>& skill, int manaVal, long long base) {
        int n = skill.size();
        long long time = base;
        for(int i = 0; i < n; i++){
            if(time < ans[i]) return false;
            time += 1LL * skill[i] * manaVal;
        }
        return true;
    }








    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        // n is teh size of skill and m is the mans

        int n = skill.size() , m = mana.size();
           

        vector<ll>ans(n);
        
        // insert the first because it was the start 

        ll sum = 0;

        for(int x = 0 ; x < n ; x++ )
        {
            sum += 1ll * mana[0] * skill[x]; // mana[0] because it was for the first 
            ans[x] = sum;
        }

        
        // itrate from mana 

        for(int x = 1 ; x < m ; x++ )
        {

            long long l = ans[0], h = ans[n-1]+1;
 
            ll time = h;


            while( l <= h ) // binary search to find the first time the was good to star
            {
                ll mid = (l+h) / 2 ;
                vll temp = ans;
                if (check(temp , skill , mana[x] , mid) )
                {   
                    ans = temp;
                    time = mid;
                    h = mid-1;
                }   
                else l = mid+1;
                
            }

            ll base = time;

            for(int y = 0 ; y < n ; y++ )
            {
                base += 1LL* mana[x] * skill[y] ;   
                ans[y] = base;
            }

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