#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>&arr) 
{
    int n = arr.size();
    if(n==1) return 0;
    int l = 0 , h = n-1;
   while(l <= h)
   {
    int mid =  (l+h)/2;
    if( (mid == 0 || mid == n-1) || ( arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid] ) )
    {
        return mid;
    }
    else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
    {
        l = mid+1;
    }
    else 
    {
        h = mid - 1;
    }
   }

   return -1;
}
int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }
    cout<<findPeakElement(arr);
    
 return 0;
}