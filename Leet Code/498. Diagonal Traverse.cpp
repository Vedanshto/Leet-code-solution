#include<bits/stdc++.h>
#define rep(x, n) for(int x = 0; x < (n); ++x)
#define ll long long
#define el cout<<endl;
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n = mat.size();
        if (n == 0) return {};

        int m = mat[0].size();
        if (m == 0) return {};

        if(n == 1) return mat[0];

        queue<pair<pair<int,int>,int>>q;

        int count = 0;

    for(int col = 0; col < m; col++) {
        q.push({{0, col}, count++});
    }

    for(int row = 1; row < n; row++) {
        q.push({{row, m - 1}, count++});
    }


        cout<<q.size();

        vector<int>ans;

        while(!q.empty())
        {
            auto it = q.front() ; q.pop();

            vector<int>temp;
            int x = it.first.first , y = it.first.second , z = it.second;           
            
            int f = x , s = y;
            while (x < n && y >= 0)
            {
                // x+1  y-1
                temp.push_back(mat[x][y]);
                x = x+1 ; y = y-1;
            }            

            if(z % 2 == 0)
            {
                reverse(temp.begin(),temp.end());
            }

            ans.insert(ans.end(),temp.begin(),temp.end());
        }

        return ans;
    }
}obj; 


int main()
{

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int x , y;
cin>>x>>y;

vector<vector<int>>arr(x,vector<int>(y));
rep(i,x)
{
    rep(m , y)
    {
        cin>>arr[i][m];
    }
}



vector<int>temp = obj.findDiagonalOrder(arr);


rep(x,temp.size)
{
    cout<<temp[x]<<" ";
}

return 0;
}