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
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        priority_queue<  vector<int> , vector<vector<int>>, greater<vector<int>>> q;

        vector<vector<int>>distence(n,vector<int>(n,1e9));
        vector<vector<int>>visited(n,vector<int>(n,false));

        q.push( { grid[0][0],0,0 } );

        distence[0][0] = grid[0][0];
      

        while(!q.empty())
        {
            auto temp = q.top() ; q.pop();

            int h = temp[0] , x = temp[1] , y = temp[2];

            if( visited[x][y]) continue;
            visited[x][y] = true;

            if( x == n-1 && y == n-1) return h;

            for(int i = 0 ; i < 4 ; i++ )
            {
                int newx = x+dx[i] , newy = y+dy[i];

                if(newx >= 0 && newy >= 0 && newx < n && newy < n && !visited[newx][newy])
                {
                    int d = max(distence[x][y] , grid[newx][newy] );

                    if(distence[newx][newy] > d)
                    {
                        distence[newx][newy] = d;
                        q.push({d,newx,newy});
                    }
                }
            }
        }

        //cout<< distence[n-1][n-1];

        return distence[n-1][n-1];

    }
}obj;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};

   cout<< obj.swimInWater(grid);

    return 0;
}