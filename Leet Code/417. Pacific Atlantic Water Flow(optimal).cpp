#include <bits/stdc++.h>
using namespace std;
#define rep(x, n) for (int x = 0; x < (n); ++x)
#define ll long long
#define el cout << endl;
#define min_heap priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define yes cout << "yes";
#define no cout << "No";
const string directions = "LRUD";
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {

        int n = h.size(), m = h[0].size();
        
       vector<vector<int>>arr(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        for(int x = 0 ; x < n ; x++ )
        {
            for(int i = 0 ; i < m ; i++ )
            {
                if(x == 0 || i == 0 || x == n-1 || i == m-1)
                {
                    arr[x][i]++;
                    q.push({x,i});
                }
            }
        }

        while (!q.empty())
        {
            auto [x,y] = q.front() ; int mx_height = h[x][y];
            q.pop();

            for(int i = 0 ; i < 4 ; i++ )
            {
                int newx = x+dx[i] , newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >=0 && newy < m && h[newx][newy] >= mx_height && arr[newx][newy] != 2)
                {
                    arr[newx][newy]++;
                    q.push({newx,newy});
                }
            }
        }
     
        
        vector<vector<int>>ans;

        for(int x = 0 ; x < n ; x++ )
        {
            for(int i = 0 ; i < m ; i++ )
            {
                if(arr[x][i] == 2)
                {
                    ans.push_back({x,i});
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
} obj;

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