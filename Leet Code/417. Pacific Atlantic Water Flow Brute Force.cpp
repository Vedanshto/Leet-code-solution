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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {

        int n = h.size() , m = h[0].size();
        vector<vector<int>>ans;
        for(int x = 0 ; x < n ; x++ )
        {
            for(int i = 0 ; i < m ; i++ )
            {
                queue<pair<int,int>>q;
                vector<vector<int>>visited(n,vector<int>(m,0));
                q.push({x,i});
                visited[x][i] = 1;
                bool P_O  = false , A_O = false;

                while (!q.empty())
                {
                    auto [f ,s] = q.front(); q.pop();

                    if(f == 0 || s == 0) P_O = true;
                    if(f == n-1 || s == m-1) A_O = true;

                    if(P_O && A_O)
                    {
                        ans.push_back({x,i});
                        break;
                    }

                    for(int y = 0 ; y < 4 ; y++ )
                    {
                        int newx = f+dx[y] , newy = s+dy[y];

                        if(newx >= 0 && newx < n && newy >= 0 && newy < m && !visited[newx][newy] && h[newx][newy] <= h[f][s])
                        {
                            q.push({newx,newy});
                            visited[newx][newy] = 1;
                        }

                    }
                }
                

            }
        }

        rep(x,ans.size())
    {
       cout<<ans[x][0]<<" "<<ans[x][1];
       el
    }
        return ans;

    }
}obj;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> h = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    
    vector<vector<int>>ans = obj.pacificAtlantic(h);
    

  
    
    
    
    return 0;
}