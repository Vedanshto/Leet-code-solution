#include<bits/stdc++.h>
using namespace std;
class solution
{
private:
    int ans = 0;
public:

    void merge(vector<int>&arr , int l, int m, int h)
    {
        int lp = l , hp = m+1;
         int j = m + 1;
        for (int i = l; i <= m; ++i) {
            while (j <= h && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            c += (j - (m + 1));
        }

        vector<int>temp;
        while (lp <= m && hp <= h)
        {
            if(arr[lp] <= arr[hp])
            {
                temp.push_back(arr[lp]);
                lp++;
            }
            else
            {
                ans += (m-lp+1) ;
                temp.push_back(arr[hp]);
                hp++;
            }
        }
        while (lp <= m)
        {
            temp.push_back(arr[lp]);
                lp++;
        }
        while (hp <= h)
        {
            temp.push_back(arr[hp]);
                hp++;
        }
        
        for(int x = 0 ; x < temp.size() ; x++ )
        {
            arr[l+x] = temp[x];
        }      
        
    }

    void mg_sort(vector<int>&arr,int l , int h)
    {
        if(l >= h) return;

        int mid = (l+h) / 2;
       mg_sort(arr,l,mid);
       mg_sort(arr,mid+1,h);
       merge(arr,l,mid,h);
    }


    int count(vector<int>&arr)
    {
        int n = arr.size();
        mg_sort(arr,0,n-1);
        int count = ans;

        return count;
        
    }
    
}obj;
int main()
{   
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }
    int ans = obj.count(arr);

    cout<<ans;
    return 0;
}