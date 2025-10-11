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
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size(); // size of energy vector

        vi prefix(n,0);

        rep(x,k)
        {
            prefix[x] = energy[x];
          
        }

        
        for(int x = k ; x < n ; x++ )
        {
            prefix[x] = prefix[x-k] + energy[x] ;
            
        }

        
        
        vi arr(k);
        
        for(int x = 0 ; x < n ; x++ )
        {
            int temp = x % k;
            arr[temp] = prefix[x];
        }
        
        int ans = *max_element(begin(arr),end(arr));

       

        for(int x = 0 ; x < n-k ; x++ )
        {
           int temp = x % k;
           ans = max(ans , arr[temp] - prefix[x] );
        }
        
     
        return ans;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi energy = {5,2,-10,-5,1}; 
    int k = 3;

    Solution obj;
    obj.maximumEnergy(energy,k);
    return 0;
}