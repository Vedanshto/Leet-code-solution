//31. Next Permutation

#include<bits/stdc++.h>
using namespace std;
void next_permutation(vector<int>& arr)
{
 //step 1 : find the downfall from the end

 int pos = -1; // hold the position of doun fall
 int  n = arr.size();// size of array

//  for(int x = 0 ; x < n ; x++ )  X(error) -> we need to find downfall from back

    for(int x = n-2 ; x >=0 ; x--)
    {
        if(arr[x] < arr[x+1])
        {
            pos = x;
            break;
        }
    }

    if(pos == -1) // if we dont find aney down fall so it's mean that it was the last permutation 
    {  //            we need to just reverse the aray
        reverse(arr.begin(),arr.end());
        return;
    }

    for(int x = n-1 ; x >= 0 ; x-- ) // after the DF pos we get we need to find the slightley larger numder 
    // then arr[pos] . so we loop from the back and swap it
    {
        if(arr[pos] < arr[x])
        {
            swap(arr[x],arr[pos]);
            break;
        }
    }
    // after the swap we need to reverse the array after the position of downfall .. eg . reverse(arr.begin()+pos+1,arr.end());
    reverse(arr.begin()+pos+1,arr.end());
}
int main()
{
    int n;//sizeof array;
    cin>>n;
    vector<int>arr(n);
    for(int x = 0 ; x < n ; x++ )
    {
        cin>>arr[x];
    }
    next_permutation(arr);
    for(int x = 0 ; x < n ; x++ )
    {
        cout<<arr[x]<<" ";
    }
 return 0;
}