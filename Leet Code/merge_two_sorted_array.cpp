#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2)
{
    
  int n = arr1.size();
  int m = arr2.size();
  if( n > m) return findMedianSortedArrays(arr2,arr1);
  int left = (n+m+1)/2;
  
  int l = 0 , h = n;

  while (l <= h)
  {
    int mid = (l+h)/2;
    int mid2 = left - mid;
    int l1 = INT_MIN , l2 = INT_MIN;
    int r1 = INT_MAX , r2 = INT_MAX;
    if(mid < n) r1 = arr1[mid];
    if(mid2 < m) r2 = arr2[mid2];
    if(mid - 1 >= 0) l1 = arr1[mid-1];
    if(mid2 - 1 >= 0) l2 = arr2[mid2-1];

    if(l1 <= r2 && l2 <= r1)
    {
        if((m+h) % 2 == 0)
        {
            return ((double)(max(l1,l2)+min(r1,r2) ))/ 2.0 ; 
        }
        else 
        {
            return max(l1,l2);
        }
    }
    else if(l1 > r2)
    {
        h = mid-1;
    } 
    else 
    {
        l = mid+1;
    }
}
return 0;
  
}





int main()
{
int n , m;
cin>>n;
vector<int>arr1(n);
for(int x = 0 ; x < n ; x++ )
{
    cin>>arr1[x];
}
cin>>m;
vector<int>arr2(m);
for(int x = 0 ; x < m ; x++ )
{
    cin>>arr2[x];
}
cout<<findMedianSortedArrays(arr1,arr2);
return 0;
}