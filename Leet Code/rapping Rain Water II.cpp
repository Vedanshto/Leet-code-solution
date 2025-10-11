#include<bits/stdc++.h>
using namespace std;
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
#define min_heap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
#define yes cout<<"yes";
#define no cout<<"No";
const string directions = "LRUD";
const vector<int> dx={0,1,0,-1} ;
const vector<int> dy={1,0,-1,0} ;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        
        int n = arr.size() , m = arr[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        rep(x,n)
        {
            rep(i,m)
            {
                if( x == 0 || x == n-1 || i == 0 || i == m-1)
                {
                    q.push({arr[x][i],x,i});
                    visited[x][i] = true;
                }
            }
        }


        int mx_height = 0 , trap_water = 0;


        while (!q.empty())
        {
            int height = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];
            q.pop();
            mx_height = max(mx_height,height);

            for(int i = 0 ; i < 4 ; i++ )
            {
                int newx = x+dx[i] ; int newy = y+dy[i];

                if(newx >= 0 && n > newx && newy >= 0 && newy < m && !visited[newx][newy])
                {
                    if(arr[newx][newy] < mx_height)
                    {
                        trap_water +=  (  mx_height  - arr[newx][newy] );
                    }

                    q.push({arr[newx][newy] , newx , newy });
                    visited[newx][newy] = true;

                }

            }


        }
        
        cout<<trap_water;

        return trap_water;

    }
}obj;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    //cin >> tc;

    vector<vector<int>>arr = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };

    while (tc--)
    {
        obj.trapRainWater(arr);
    }
    return 0;
}