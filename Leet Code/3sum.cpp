#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // vector<vector<int>> threeSum(vector<int> &arr)
    // {
    //     vector<vector<int>> ans;
    //     int n = arr.size();
    //     for (int x = 0; x < n; x++)
    //     {
            
    //         for (int i = x + 1; i < n; i++)
    //         {
    //             for (int z = i + 1; z < n; z++)
    //             {
    //                 if (arr[x] + arr[i] + arr[z] == 0)
    //                 {
    //                     vector<int> temp(3);
    //                     temp[0] = arr[x];
    //                     temp[1] = arr[i];
    //                     temp[2] = arr[z];

    //                     sort(temp.begin(), temp.end());

    //                     if (find(ans.begin(), ans.end(), temp) == ans.end())
    //                     {
    //                         ans.push_back(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    vector<vector<int>> threeSum(vector<int> &arr, int tar)
    {
        int n = arr.size();
        set<vector<int>>st;
        for(int x = 0 ; x < n ;x++ )
        {
            unordered_map<int,int>mp;
            for(int i = x+1 ; i < n ; i++ )
            {
                int def = arr[x]+arr[i];
                def = tar - def;
                if(mp.find(def) != mp.end() )
                {
                    vector<int>temp(3) ;
                    temp[1] = arr[x] ; temp[2] = arr[i] ; temp[3] = def;
                    st.insert(temp);
                }
                mp[arr[i]]++;
            }
        }
        if(st.size() == 0) return{{}};
        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
}obj1;

int main()
{
    int n ; cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ ) cin>>arr[x];
    int tar ; cin>>tar;
    vector<vector<int>>ans = obj1.threeSum(arr,tar);
    for(auto it : ans)
    {
        for(auto i : ans[0])
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}