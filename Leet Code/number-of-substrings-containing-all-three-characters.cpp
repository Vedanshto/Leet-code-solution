// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include<bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
    int n = s.size() , c = 0 , low = 0;
    int hash[3]={0};

    for(int x = 0 ; x < n ; x++ )
    {
        hash[ s[x]-'a']++;

        while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0 )
        {
            c += n-x;

            hash[s[low]-'a']--;

            low++;

        }
    }
    return c;
}
int main()
{

    string s;
    cin>>s;
    cout<<numberOfSubstrings(s);
    return 0;
}