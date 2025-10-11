//2523. Closest Prime Numbers in Range
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // suing the BF approch Time : O(N^2) 
        vector<int> closestPrimes(int l, int r ) {
            vector<int>arr;
            for(int x = l ; x <= r ; x++ )
            {
                 int c = 0;   
                for(int i = 2 ; i < x-1 ; i++ )
                {
                    if(x % i == 0) c++;
                }
    
                if(c == 0) 
                {
                arr.push_back(x);
                //cout<<x<<" is the prime no"<<endl;
                }
            }
            int pos = 0 , mx = INT_MIN;
            if(arr.size() >= 2 )
            {
                for(int x = 0 ;x < arr.size()-1 ; x++ )
                {
                    if(arr[x+1] - arr[x] < mx)
                    {
                        pos = x;
                        mx = arr[x+1] - arr[x];
                    }
                }

                return {arr[pos],arr[pos+1]};
            }


            return {-1,-1};
        }




        // Using sieve of eratotenes || tiem : O(N) || space : O(N)

        vector<int> closestPrimes2(int l, int r )
        {
            vector<bool>arr(r+1,true);
            arr[0] = arr[1] = false;

            for(int x = 2 ; x * x <= r ; x++ )
            {
                if(arr[x])  
                {
                    for(int i = x*x ; i <= r ; i+=x )
                    {
                        arr[i] = false;
                    }
                }
            }

            vector<int>array;
            for(int x = max(2,l) ; x <= r; x++  )
            {
                if(arr[x])
                {
                    array.push_back(x);
                }
            }

            if(array.size() < 2) return{-1,-1};

            int mn = INT_MAX , pos = 0;

            for(int x = 1 ; x < array.size() ; x++ )
            {
                int temp = array[x] - array[x-1];
                if(temp < mn)
                {
                    mn = temp;
                    pos = x;
                }
            }

            return {array[pos-1],array[pos]};
        }
 }c1;

int main()
{
    vector<int>ans;
    ans = c1.closestPrimes2(19,31);
    cout<<ans[0]<<" "<<ans[1];
 return 0;
}