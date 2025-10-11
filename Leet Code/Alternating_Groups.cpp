// There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

// Return the number of alternating groups.


#include<bits/stdc++.h>
using namespace std;
class solv
{
public:
 int k_alternative_group(vector<int>&arr , int k)
 {
    int def = 0 , n = arr.size() ;
    for(int x = 0 ; x < k-1 ; x++ )
    {
        if(arr[x]!=arr[x+1]) def++;
    }
    int c = 0;
    for(int x = 0 ; x < n ; x++ )
    {
        if(def == k-1) c++;

        if(arr[x] != arr[(x+1)%n]) def--;

        if(arr[(x+k)%n] != arr[(x+k-1)%n]) def++;
    }

    return c;
 }


};

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ;x < n ; x++ )
    {
        cin>>arr[x];
    }
    solv s1;
    cout<<s1.k_alternative_group(arr,3);


 return 0;
}