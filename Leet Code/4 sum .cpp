#include<bits/stdc++.h>
using namespace std;
// Better approch
vector<vector<int>>Two_sum_1(vector<int>&arr , int tar)
{
    int n = arr.size();
    set<vector<int>>st;
    for(int x = 0 ; x < n ; x++ )
    {
        for(int i = x+1 ; i < n ; i++ )
        {
            set<long long>mp;
            for(int j = i+1 ; j < n ; j++ )
            {
                long long temp = arr[x] + arr[i] + arr[j];
                long long four = tar - (temp);
                if(mp.find(four)!=mp.end())
                {
                    vector<int>hold={arr[x],arr[i],arr[j],(int)four};
                    sort(hold.begin(),hold.end());
                    st.insert(hold);
                }    
                mp.insert(arr[j]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}


vector<vector<int>>Two_sum_2(vector<int>&arr , int tar)
{
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    for(int x = 0 ; x < n ; x++ )
    {
        if(x > 0 && arr[x] == arr[x+1]) continue;
        for(int i = x+1 ; i < n ; i++ )
        {
            if(i > x && arr[i] == arr[i+1]) continue;
            int l = i+1 , h = n-1;
            while (l < h)
            {
                int sum = arr[x]+arr[i]+arr[l]+arr[h];
                if(sum == tar)
                {
                    vector<int>temp={arr[x],arr[i],arr[l],arr[h]};
                    ans.push_back(temp);
                    while(h > l && arr[l] == arr[l+1]) l++;
                    while(h > l && arr[h] == arr[h-1]) h--;
                    l++;
                    h--;
                }
                else if(sum > tar)
                {
                    h--;
                }
                else 
                {
                    l++;
                }
            }
            
        }
    }

    return ans;
}

int main()
{
    vector<int>arr={1,8,7,3,2,5};
    int tar=11;
    vector<vector<int>>ans = Two_sum_2(arr,tar);
    for(int x = 0 ; x < ans.size() ; x++ )
    {
        for(int i = 0 ; i < ans[0].size() ; i++)
        {
        cout<<ans[x][i]<<" ";
        }
        cout<<endl;
    }
   
 return 0;
}