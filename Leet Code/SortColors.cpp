#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int mid = 0 , low = 0 , high = arr.size()-1 , n = arr.size();

        while (mid <= high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[low],arr[mid]);
                mid++;
                low++;
            }
            else if(arr[mid] == 1)
            {
                mid++;
            }
            else 
            {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
        

    }
};

int main()
{

    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }

    Solution s1;
    s1.sortColors(arr);
    for(int x = 0 ; x < n ; x++ )
    {
        cout<<arr[x]<<" ";
    }


    return 0;
}