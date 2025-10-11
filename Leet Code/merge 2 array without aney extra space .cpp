#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr1 , vector<int>&arr2 )
{
    int n = arr1.size();
    int m = arr2.size();

    int l = 0 , h = 0;
    vector<int>temp;
    while (l < n && h < m)
    {
        if(arr1[l] <= arr2[h] )
        {
            temp.push_back(arr1[l]);
            l++;
        }
        else 
        {
            temp.push_back(arr2[h]);
            h++;
        }
    }

    while (l < n)
    {
        temp.push_back(arr1[l]);
            l++;
    }
    while (h < m)
    {
        temp.push_back(arr2[h]);
            h++;
    }
    
    
    for(int x = 0 ; x < temp.size() ; x++ )
    {
        if(x < n)
        {
            arr1[x] = temp[x];
        }
        else 
        {
            arr2[x-n] = temp[x];
        }
    }

}
int main()
{
    vector<int>arr1 = {0,1,3,2,5};
    vector<int>arr2 = {6,3,1,5};

    merge(arr1,arr2);

    for(int x = 0 ; x < 5 ; x++ )
    {
        cout<<arr1[x]<<" ";
    }
    for(int x = 0 ; x < 4 ; x++ )
    {
        cout<<arr2[x]<<" ";
    }

 return 0;
}